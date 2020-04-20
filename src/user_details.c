#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"../include/user_details.h"
#include"../include/candidate_details.h"
int user_details(char* name)
{
	char buf[1024];
	int row = 0, col = 0;
	printf("\n==========================================================================");
	printf("\n\n");
	printf("\n========================");
	printf("\nUSER INFORMATION");
	printf("\n========================");
	FILE* fp = fopen("../data/userdetails.csv", "r");//file containing details of all users or voters
	if (!fp) 
	{
		printf("Can't open file\n");
		return 0;//returns when file does not exist
	}
	while (fgets(buf, 1024, fp))
	{
		col = 0;
		row++;

		if (row == 1)
		{
			continue;
		}
		char* field = strtok(buf, ",");
		printf("\n");
		char* string = field;
		string = strtok(NULL, ",");
		if (strcmp(field, name) == 0)//compares username fetched from user_login function with that of user_details file
		{
			while (field)
			{
				if (col == 0)
				{
					printf("First Name:\t");//prints value fetched from file
				}
				if (col == 1)
				{
					printf("Last Name:\t");//prints value fetched from file
					printf("%s\n", string);
					col++;
				}
				if (col == 2)
				{
					printf("Age:\t");//prints value fetched from file

				}
				if (col == 3)
				{
					printf("Phone:\t");//prints value fetched from file
				}
				if (col == 4)
				{
					printf("Postal code:\t");//prints value fetched from file
				}
				if (col == 5)
				{
					printf("Province:\t");//prints value fetched from file
					printf("%s\n", field);
					printf("\n\nPress Enter to view the candidates in your Province...!!");
					getch();
					candidate_details(field);//passing province of logged in user to restrict from voting nominees in other provinces
					break;
				}
				if (col < 5 && col != 1)
				{
					printf("%s\n", field);
					field = strtok(NULL, ",");
					col++;
				}
			}
			printf("\n");
        }
	}

	fclose(fp);
	return 0;
}
