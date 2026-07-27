#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int balance=10000;
int computer;
int ask;

void clear_input_buffer()
{
char m;
while((m=getchar())!='\n' && m!=EOF);
}

void place_bet();
void ask_user(int );
void roll_dice(int );
void results(int );

int main()
{
printf("\n\n---||:> Welcome to DICE Gambling game <:||---\n\n");

srand((unsigned int)time(NULL));

printf("==========================\n");
printf("Current balance : %$%d\n",balance);
printf("==========================\n\n");
while(balance>=0)
{
char choice;
if(balance==0)
{
printf(";{\n");
printf("You are bankrupt !\n");
return 0;
}
place_bet();

do
{
printf("Do you want to play again? (y/n):");
scanf("%c",&choice);
clear_input_buffer();

if(choice=='n' || choice=='N')
{
printf("\n:)\nThanks for playing !\nYour Final balance : %d\n\n",balance);
return 0;
}

}while(choice!='y' && choice!='Y');

}

return 0;
}

void place_bet()
{
int bet;
while(1)
{
printf("==========================\n");
printf("Enter a bet : ");
scanf("%d",&bet);
clear_input_buffer();
printf("==========================\n\n\n");

if(bet<=50)
{
printf("Bid must be greater than $50\n\n");
}
else if(bet>balance)
{
printf("insufficient balance,you only have %d\n\n",balance);
}
else
{
break;
}
}
printf("==========================\n");
printf("Entered bid of : %$%d\n",bet);
printf("==========================\n\n");

ask_user(bet);

}


void ask_user(int bet)
{
int f=0;
do
{
printf("Choose a number between (1 to 6) :");
scanf("%d",&ask);
clear_input_buffer();
if(ask>6 || ask<1)
{
printf("Invalid choice,Enter again !\n");
}
else
{
f=1;
}
}while(f!=1);

printf("_=_=_=_=_=_=_=_=_=_=_=_=\n");
printf("Rolling Dice....\n");
printf("_=_=_=_=_=_=_=_=_=_=_=_=\n\n");
roll_dice(bet);

}

void roll_dice(int bet)
{
computer=((rand()%6)+1);

switch(computer)
{
case 1:
printf("+-------+\n");
printf("|       |\n");
printf("|   o   |\n");
printf("|       |\n");
printf("+-------+\n\n");
break;
case 2:
printf("+-------+\n");
printf("| o     |\n");
printf("|       |\n");
printf("|     o |\n");
printf("+-------+\n\n");
break;
case 3:
printf("+-------+\n");
printf("| o     |\n");
printf("|   o   |\n");
printf("|     o |\n");
printf("+-------+\n\n");
break;
case 4:
printf("+-------+\n");
printf("| o   o |\n");
printf("|       |\n");
printf("| o   o |\n");
printf("+-------+\n\n");
break;
case 5:
printf("+-------+\n");
printf("| o   o |\n");
printf("|   o   |\n");
printf("| o   o |\n");
printf("+-------+\n\n");
break;
case 6:
printf("+-------+\n");
printf("| o   o |\n");
printf("| o   o |\n");
printf("| o   o |\n");
printf("+-------+\n\n");
break;
default:
break;
}

printf("==========================\n");
printf("Lucky number is :(%d)\n",computer);
printf("==========================\n\n");


results(bet);
}

void results(int bet)
{
char m;
printf("==========================\n");
printf("Your choice :(%d)\n",ask);
printf("==========================\n\n");

if(ask==computer)
{
printf("You won !\n");
balance=balance+bet;
printf("==========================\n");
printf("Updated balance :(%d)\n",balance);
printf("==========================\n\n");

}
else
{
printf("You lost !\n");
balance=balance-bet;
printf("==========================\n");
printf("Updated balance :(%d)\n",balance);
printf("==========================\n\n");

}


}
