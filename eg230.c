#include<stdio.h>
#include<string.h>

void buf()
{
int c;
while((c=getchar())!='\n' && c!=EOF);
}

void add_student();
void edit_student();
void delete_student();
void list_student();
void search_student();


// GLOBAL VARIABLES
int roll_number[20];
char name[20][27];   // 20 rows and each row of max 26 characters string
int number_of_students_added;

int main()
{
printf("\n\n/-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\\\n");
printf("---||:> Student data program <:||---\n");
printf("\\_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=_=/\n");
int f=0;            // flag variable
int choice;        // User's Choice 
number_of_students_added=0;
do
{
printf("\n--||:> MENU BAR <:||---\n");
printf("1. Add Students \n");
printf("2. Edit Students \n");
printf("3. Delete Students \n");
printf("4. List Students \n");
printf("5. Search Students \n");
printf("6. Exit ! \n");
printf("===================\n");
printf("Enter your choice :");
scanf("%d",&choice);
buf();
printf("===================\n");
if(choice<1 || choice >6)
{
printf("\n\n-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>--<>-<>-<>-\n");
printf("Invalid choice,press enter to continue......");
buf();
printf("-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>--<>-<>-<>-\n\n");
}
else if(choice==6)
{
printf("\nExiting...\nThanks for visiting !\n");
f=1;
}
else if(choice==1)
{
if(number_of_students_added==20)
{
printf("Data of 20 Students added, you cannot add more\n");
printf("Press enter to continue......");
buf();
}
else
{
add_student();
}
}
else if(choice==2)
{
if(number_of_students_added==0)
{
printf("\n\n-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");
printf("No Record available, Add students first !\npress enter to continue....");
buf();
printf("-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");
}
else
{
edit_student();
}
}
else if(choice==3)
{
if(number_of_students_added==0)
{
printf("\n\n-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");
printf("No Record available, Add students first !\npress enter to continue....");
buf();
printf("-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");
}
else
{
delete_student();
}
}
else if(choice==4)
{
if(number_of_students_added==0)
{
printf("\n\n-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");
printf("No Record available, Add students first !\npress enter to continue....");
buf();
printf("-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-\n");

}
else
{
list_student();
}
}
else
{
if(number_of_students_added==0)
{
printf("\n\n-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>--<>-<>-<>-<>--<>-<>-<>-\n");
printf("No Record available, Add students first !\npress enter to continue....");
buf();
printf("-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>-<>--<>-<>-<>-<>--<>-<>-<>-\n");
}
else
{
search_student();
}
}

}while(f!=1);

return 0;
}

void add_student()
{
char n[27];
int r,i,found;
char m;
printf("\n~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
printf("Student (Add Module)\n");
printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n\n");
printf("Enter roll number : ");
scanf("%d",&r);
buf();
if(r<=0)
{
printf("Invalid roll Number,press enter key to continue.....");
buf();
return;
}
found=0;
i=0;
while(i<number_of_students_added)
{
if(roll_number[i]==r)
{
found=1;
break;
}
i++;
}
if(found==1)
{
printf("That roll number alloted to %s,press any key to continue....",name[i]);
buf();
return;
}
int j=0;
int found_new_line=0;
printf("Enter a name :");
fgets(n,27,stdin);
while(j<strlen(n))
{
if(n[j]=='\n')
{
n[j]='\0';
found_new_line=1;
break;
}
j++;
}

if(found_new_line==0)
{
buf();
}

printf("\n");
printf("Add (Y/N) : ");
m=getchar();
buf();
if(m!='y' && m!='Y')
{
printf("\nStudent not added,press enter key to continue.....");
buf();
return;
}
roll_number[number_of_students_added]=r;
strcpy(name[number_of_students_added],n);
number_of_students_added++;
printf("\nStudent added,press enter key to continue....");
buf();
}


void edit_student()
{
char m;
int found,i,r;
char n[27];
printf("\n~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
printf("    Student (Edit/Update Module)\n");
printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n\n");

printf("Enter roll number :");
scanf("%d",&r);
buf();
if(r<=0)
{
printf("Invalid roll number,press enter to continue....");
buf();
return;
}
found=0;
i=0;
while(i<number_of_students_added)
{
if(roll_number[i]==r)
{
found=1;
break;
}
i++;
}

if(found==0)
{
printf("Roll number not found !,press enter to continue....");
buf();
return;
}

int j=0;
int found_new_line=0;
printf("Name : %s\n\n",name[i]);
printf("Edit the name :");
fgets(n,27,stdin);
while(j<strlen(n))
{
if(n[j]=='\n')
{
n[j]='\0';
found_new_line=1;
break;
}
j++;
}

if(found_new_line==0)
{
buf();
}

printf("\n");
printf("Edit (Y/N) : ");
m=getchar();
buf();
if(m!='Y' && m!='y')
{
printf("\nStudent not edited,press enter key to continue.....");
buf();
return;
}
strcpy(name[i],n);
printf("\nStudent edited,press enter to continue....");
buf();
}


void delete_student()
{
char m;
int found,i,r,endpoint;
printf("\n~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
printf("      Students (Delete Module)\n");
printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n\n");

printf("Enter roll number :");
scanf("%d",&r);
buf();
if(r<=0)
{
printf("Invalid roll number,press enter to continue....");
buf();
return;
}
found=0;
i=0;
while(i<number_of_students_added)
{
if(roll_number[i]==r)
{
found=1;
break;
}
i++;
}

if(found==0)
{
printf("Roll number not found !,press enter to continue....");
buf();
return;
}
printf("Name: %s\n",name[i]);
printf("\nDo you want to delete (Y/N) : ");
m=getchar();
if(m!='Y' && m!='y')
{
printf("Student data not deleted,press enter to continue....");
buf();
return;
}

endpoint=number_of_students_added;
while(i<endpoint-1)
{
roll_number[i]=roll_number[i+1];
strcpy(name[i],name[i+1]);
i++;
}
number_of_students_added--;
printf("\nStudent deleted, press enter to continue....");
getchar();
buf();
}

void list_student()
{
int i=0;
printf("\n~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
printf("        List of Students\n");
printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n\n");

printf("Roll No. | Name of student \n");
printf("========================== \n");
while(i<number_of_students_added)
{
printf("%-5d    | %-26s\n",roll_number[i],name[i]);
i++;
}
printf("\nTotal %d students are enrolled\n",number_of_students_added);
printf("Press enter to continue....");
buf();

}

void search_student()
{
int found;
int r,i;
printf("\n~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n");
printf("     Student (Search Module)\n");
printf("~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~^~\n\n");

printf("Enter roll number :");
scanf("%d",&r);
buf();

if(r<=0)
{
printf("Invalid roll number,press enter to continue....");
buf();
return;
}
found=0;
i=0;
while(i<number_of_students_added)
{
if(roll_number[i]==r)
{
found=1;
break;
}
i++;
}

if(found==0)
{
printf("Roll number not found !,press enter to continue....");
buf();
return;
}
printf("\n(%s) is enrolled on roll number :[%d]\n\n",name[i],roll_number[i]);
printf("press enter to continue....");
buf();

}




