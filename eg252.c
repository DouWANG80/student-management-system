#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void buf()
{
int c;
while((c=getchar())!='\n' && c!=EOF);
}
struct students
{
int roll_number;
char name[27];
};
void add_student();
void edit_student();
void delete_student();
void list_student();
void search_student();
int number_of_students_added;
struct students *s;
int main()
{
int choice,f=0;
printf("\n/----------------------------------\\\n");
printf("---||:> Student data program <:||---\n");
printf("\\__________________________________/\n");
do
{
printf("\n\n    ---||:> MENU BAR <:||---    \n");
printf("====================================\n");
printf("|| 1. Add    Student		  ||\n");
printf("|| 2. Edit   Student		  ||\n");
printf("|| 3. Delete Student		  ||\n");
printf("|| 4. List   Student		  ||\n");
printf("|| 5. Search Student		  ||\n");
printf("|| 6. Exit !			  ||\n");
printf("====================================\n\n");
printf("Enter your choice :");
if(scanf("%d",&choice)!=1)
{
printf("Invalid input! Please enter a number.\n");
buf();
continue;
}
buf();
if(choice<1 || choice>6)
{
printf("\n\n;{");
printf("\nInvalid choice!,press enter to continue....");
buf();
}
else if(choice==6)
{
printf("\n\nExiting....");
printf("\nThanks for visiting !\n");
f=1;

if(s!=NULL)
{
free(s);
s=NULL;
}
}
else if(choice==1)
{
add_student();
}
else if(choice==2)
{
if(number_of_students_added==0)
{
printf("\nNumber of students added : (%d)\n",number_of_students_added);
printf("\nNo records found,Add student first !\n");
printf("press enter to continue....");
buf();
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
printf("No records found,Add student first !\n");
printf("Press enter to continue....");
buf();
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
printf("\nNo records found,Add student first !\n");
printf("Press enter to continue....");
buf();
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
printf("No records found,Add student first !\n");
printf("Press enter to continue....");
buf();
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
int r,found,i;
char m,n[27];
printf("Student (Add Module)\n");
printf("======================\n\n");
printf("Enter roll number :");
scanf("%d",&r);
buf();
if(r<=0)
{
printf("\n\nInvalid roll number ,press eneter to continue....");
buf();
return;
}
found=0;
i=0;
while(i<number_of_students_added)
{
if(s[i].roll_number==r)
{
found=1;
break;
}
i++;
}

if(found==1)
{
printf("Roll number already alloted to (%s),press enter to continue....",s[i].name);
buf();
return;
}
int j=0;
int found_new_line=0;
printf("Enter name of student : ");
fgets(n,27,stdin);
while(n[j]!='\0')
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
printf("\nAdd (Y/N) : ");
m=getchar();
buf();
if(m!='Y' && m!='y')
{
printf("\nStudent not added,press enter to continue....");
buf();
return;
}
number_of_students_added++;
struct students *temp=(struct students *)realloc(s,(number_of_students_added)*sizeof(struct students));
if(temp==NULL)
{
printf("Memory alloaction failed !,press enter to continue....\n");
buf();
return;
}
s=temp;
s[i].roll_number=r;
strcpy(s[i].name,n);
printf("\nStudent added,press enter to continue....");
buf();
}

void edit_student()
{
int r,i,found;
char m;
char n[27];
printf("\n\nEdit/Update Student name\n");
printf("========================\n");
printf("Enter roll number : ");
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
if(s[i].roll_number==r)
{
found=1;
break;
}
i++;
}
if(found==0)
{
printf("Roll number not found,press enter to continue....");
buf();
return;
}
printf("\nName : %s\n",s[i].name);
printf("Do you want to Edit (Y/N) : ");
m=getchar();
buf();
if(m!='Y' && m!='y')
{
printf("Student not updated,press enter to continue....");
buf();
return;
}
int j=0,found_new_line=0;

printf("\nEnter name :");
fgets(n,27,stdin);
while(n[j]!='\0')
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
printf("Update (Y/N) : ");
m=getchar();
buf();
if(m!='Y' && m!='y')
{
printf("Student not updated,press enter to continue....");
buf();
return;
}
strcpy(s[i].name,n);
printf("\nStudent updated !,press enter to continue....");
buf();
}

void delete_student()
{
int r,found,i;
char m;
printf("\nStudent record delete Module\n");
printf("=============================\n");
printf("Enter roll number : ");
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
if(s[i].roll_number==r)
{
found=1;
break;
}
i++;
}
if(found==0)
{
printf("Roll number not found ,press enter to continue....");
buf();
return;
}
printf("\nName : (%s)\n",s[i].name);
printf("Do you want to delete (Y/N) : ");
m=getchar();
buf();
if(m!='Y' && m!='y')
{
printf("\nStudent data not deleted,press enter to continue....");
buf();
return;
}
while(i<number_of_students_added-1)
{
s[i].roll_number=s[i+1].roll_number;
strcpy(s[i].name,s[i+1].name);
i++;
}
number_of_students_added--;
if(number_of_students_added==0)
{
free(s);
s=NULL;
}
else
{
struct students *temp=(struct students *)realloc(s,(number_of_students_added)*sizeof(struct students));
if(temp!=NULL)
{
s=temp;
}
else
{
printf("Memory allocation failed !\n");
}
}
printf("\nStudent data deleted,press enter to continue....");
buf();
}

void list_student()
{
int i=0;
char m;
printf("\n---||:> List of students <:||---\n");
printf("=================================\n\n");
printf("S.no | Roll number | Name \n");
printf("__________________________\n");
while(i<number_of_students_added)
{
printf("%-5d|%-5d        |%-5s\n",i+1,s[i].roll_number,s[i].name);
i++;
}
printf("==========================\n");
printf("Total students : %d \n",number_of_students_added);
printf("Press enter to continue....");
buf();
}

void search_student()
{
int r,i,found;
char m;
printf("\n   Student (Search Module)\n");
printf("===========================\n\n");
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
if(s[i].roll_number==r)
{
found=1;
break;
}
i++;
}
if(found==0)
{
printf("Roll number not found,press enter to continue....");
buf();
return;
}
printf("\n%s is enrolled at roll number %d\n",s[i].name,s[i].roll_number);
printf("Press enter to continue....");
buf();
}