#include <stdio.h>
#include <windows.h>
#include <conio.h>

void add_course (void);
void delete_course (void);
void list_courses (void);
void update_course (void);

struct course
{
	int courseID;
	char courseName [20];
	float grade;
} course;

FILE *fp, *ft;

main ()
{
	int choice;
	printf("------------ M E N U ------------\n");
	printf("1) ADD Course\n");
	printf("2) DELETE Course\n");
	printf("3) LIST Courses\n");
	printf("4) UPDATE Course\n");
	printf("5) EXIT\n\n");
	printf("Choice? : "); scanf("%d", &choice);
	
	switch (choice)
	{
		case 1:
			add_course();
		case 2:
			delete_course();
		case 3:
			list_courses();
		case 4:
			update_course();
		default:
			exit(0);
	}
}

void add_course (void)
{
	printf("\n---------------------------------\n");
	printf("Enter the course ID: "); scanf("%d", &course.courseID);
	printf("Enter the course NAME: "); scanf("%s", course.courseName);
	printf("Enter the course GRADE: "); scanf("%f", &course.grade);
	
	fp = fopen("courses.txt", "ab+");
	fseek(fp, 0, SEEK_END);
	fwrite(&course, sizeof(course), 1, fp);
	fclose(fp);
	
	printf("\nSuccesfully Added..\n");
	Sleep(1000); system("cls"); main();
}

void delete_course (void)
{
	int ID;
	printf("\n---------------------------------\n");
	printf("%s\t  %s\t  %s", "Course ID", "Course Name", "Grade");
	fp = fopen("courses.txt","rb+");
	while (fread (&course, sizeof(course), 1, fp) == 1)
	{
		printf("\n%d\t\t  %s\t  %.2f", course.courseID, course.courseName, course.grade);
	}
	
	printf("\n\nChoice ID for delete: "); scanf("%d", &ID);
	
	ft = fopen("delete_operation.txt","wb+");
	rewind(fp);
	while (fread (&course, sizeof(course), 1, fp) == 1)
	{
		if (course.courseID != ID)
		{
			fseek(ft, 0, SEEK_CUR);
			fwrite(&course, sizeof(course), 1, ft);
		}
	}
	fclose(ft); fclose(fp);
	remove("courses.txt"); rename("delete_operation.txt","courses.txt");
	fflush(stdin);
	printf("\nSuccesfully Deleted..\n");
	Sleep(1000); system("cls"); main();
}

void list_courses (void)
{
	printf("\n---------------------------------\n");
	printf("%s\t  %s\t  %s", "Course ID", "Course Name", "Grade");
	
	fp = fopen("courses.txt","rb");
	while (fread (&course, sizeof(course), 1, fp) == 1)
	{
		printf("\n%d\t\t  %s\t  %.2f", course.courseID, course.courseName, course.grade);
	}
	fclose(fp);
	
	printf("\n\nPress any key to MENU..");
	getch(); system("cls"); main();
}

void update_course (void)
{
	int ID;
	printf("\n---------------------------------\n");
	printf("%s\t  %s\t  %s", "Course ID", "Course Name", "Grade");
	fp = fopen("courses.txt","rb+");
	while (fread (&course, sizeof(course), 1, fp) == 1)
	{
		printf("\n%d\t\t  %s\t  %.2f", course.courseID, course.courseName, course.grade);
	}
	
	printf("\n\nChoice ID for edit: "); scanf("%d", &ID);
	
	rewind(fp);
	while (fread (&course, sizeof(course), 1, fp) == 1)
	{
		if (course.courseID == ID)
		{
			printf("\nCourse name: %s", course.courseName);
			printf("\nEnter a new name: "); scanf("%s", course.courseName);
			printf("\nCourse grade: %.2f", course.grade);
			printf("\nEnter a new grade: "); scanf("%f", &course.grade);
			
			fseek(fp, ftell(fp)-sizeof(course), 0);
			fwrite(&course, sizeof(course), 1, fp);
			fclose(fp);	
		}	
	}
	
	printf("\nSuccesfully Edited..\n");
	Sleep(1000); system("cls"); main();
}
