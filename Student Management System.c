#include<stdio.h>
#include<string.h>

void showMenu();
void addStudent();
void showAllStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

int roll[100];
int marks[100];
int age[100];
char name[100] [50];
int totalStudents = 0;
int i;

int main()
{
	int choice;
	
	while(1)
	{
		showMenu();
		scanf("%d",&choice);
		
		if(choice == 1)
		{
			addStudent();
		}
		else if(choice == 2)
		{
			showAllStudents();
		}
		else if(choice == 3)
		{
			searchStudent();
		}
		else if(choice == 4)
		{
			updateStudent();
		}
		else if(choice == 5)
		{
			deleteStudent();
		}
		else if(choice == 6)
		{
			printf("Thank You\n");
			break;
		}
		else
		{
			printf("Invalid choice\n");
		}
	}
	
	return 0;
}

void showMenu()
{
	printf("========== STUDENT MANAGEMENT SYSTEM ==========\n");

	printf("1. Add Student\n");	
	printf("2. Show All Students\n");
	printf("3. Search Student\n");
	printf("4. Update Student\n");
	printf("5. Delete Student\n");
	printf("6. Exit\n");

	printf("Enter your choice:\n");
}

void addStudent()
{
	if(totalStudents == 100)
	{
    	printf("Student List is Full!\n");
    	return;
	}
	printf("Enter roll number\n");
	scanf("%d",&roll[totalStudents]);
	
	for(i=0; i<totalStudents; i++)
	{
		if(roll[totalStudents] == roll[i])
		{
			printf("Roll Number Already Exists\n");
			return;
		}
	}
	
	printf("enter marks\n");
	scanf("%d",&marks[totalStudents]);
	
	printf("Enter the Name of student\n");
	scanf("%s", name[totalStudents]);
	
	printf("Enter Age of Student\n");
	scanf("%d",&age[totalStudents]);
	
	totalStudents++;
	
	printf("Student Added Succesfully!\n");
}

void showAllStudents()
{
	if(totalStudents == 0)
	{
		printf("No Student Found\n");
	}
	else
	{
		for(i = 0; i < totalStudents; i++)
		{
    		printf("------------------------------\n");
    		printf("Student %d\n\n", i + 1);
			
    		printf("Roll Number : %d\n", roll[i]);
    		printf("Name        : %s\n", name[i]);
    		printf("Age         : %d\n", age[i]);
    		printf("Marks       : %d\n", marks[i]);
			
    		printf("------------------------------\n\n");
		}
	}
}

void searchStudent()
{
	int searchRoll;
	int found = 0;
	
	printf("Enter the roll number\n");
	scanf("%d",&searchRoll);
	
	for(i = 0; i < totalStudents; i++)
	{
		if(searchRoll == roll[i])
		{
			printf("roll number: %d\n",roll[i]);
			printf("Marks: %d\n",marks[i]);
			printf("Name of Student: %s\n",name[i]);
			printf("Age of Student: %d\n",age[i]);
			found = 1;
			break;
		}
	}
	if(found == 0)
	{
		printf("Student Not Found\n");
	}
}

void updateStudent()
{
	int searchRoll;
	int newMarks;
	int found = 0;
	
	printf("Enter Roll Number to Update:\n");
	scanf("%d",&searchRoll);
	
	for(i = 0; i < totalStudents; i++)
	{
		if(searchRoll == roll[i])
		{
			printf("roll number: %d\n",roll[i]);
			printf("Marks: %d\n",marks[i]);
			printf("Name of Student: %s\n",name[i]);
			printf("Age of Student: %d\n",age[i]);
			
			printf("Enter New Name:\n");
			scanf("%s", name[i]);
			
			printf("Enter New Age:\n");
			scanf("%d", &age[i]);
			
			printf("Enter New Marks:\n");
			scanf("%d",&newMarks);
			
			marks[i] = newMarks;
			
			printf("Student Update Succesfull\n");
			
			found = 1;
			break;
		}
	}
	if(found == 0)
	{
		printf("Student Not Found\n");
	}
}

void deleteStudent()
{
	int searchRoll;
	int found = 0;
	int j;
	
	printf("Enter Roll number to delete\n");
	scanf("%d",&searchRoll);
	
	for(i = 0; i < totalStudents; i++)
	{
		if(searchRoll == roll[i])
		{
			for(j = i; j < totalStudents - 1; j++)
			{
				roll[j] = roll[j+1];
				marks[j] = marks[j+1];
				age[j] = age[j+1];
				strcpy(name[j], name[j+1]);
			}
			
			totalStudents--;
			
			printf("Student Delete Succesfull\n");
			
			found = 1;
			break;
		}
	}
	if(found == 0)
	{
		printf("Student Not Found\n");
	}
}
