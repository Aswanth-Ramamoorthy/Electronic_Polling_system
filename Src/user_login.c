#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"..include/user_login.h"
#include"..include/user_details.h"
int user_login()
{
	static int i = 0;
	char username[15];
	char password[12];
	char* str[1024];
	FILE* fp = fopen("../data/auth.csv", "r");//file containing user authentication details
	printf("--*--*--*--*--*--*--*--*--*");
	printf("\n\tUSER LOGIN\n");
	printf("--*--*--*--*--*--*--*--*--*\n");
	printf("Enter your username:\n");
	scanf("%s", &username);//fetching input from user

	printf("Enter your password:\n");
	for (i = 0; i < 6; i++)
	{
		password[i] = getch();
		printf("*");//to hide the password on input screen

	}
	password[i] = '\0';
	char string[1024];
	int row_count = 0;
	int field_count = 0, flag = 0;
	if (!fp) 
	{
		printf("Can't open file\n");
		return 0;//returns when file does not exist
	}
	while (fgets(string, 1024, fp) && flag == 0)
	{
		field_count = 0;
		row_count++;
		if (row_count == 1)
		{
			continue;
		}
		char* field = strtok(string, ",");
		if (strcmp(field, username) == 0)//compares entered username to that of auth.csv file
		{
			field = strtok(NULL, ",");
			if (strcmp(field, password) == 0)//compares entered password to that of auth.csv file
			{
				while (field) 
				{
					flag++;
					field_count++;
					break;
				}
			}
		}
	}
	if (flag == 0)
	{
		printf("\nStatus:Invalid login");
		printf("\n");
		printf("\n\n\t\t\t\t  (PRESS [Y] TO RE-LOGIN)");
		if (getch() == 'y' || getch() == 'Y')
		user_login();//making the function available for user to retry
        fclose(fp);
        return -1;//returns when login fails
	}
	else
	{
		printf("\nStatus:Successful Login");
		printf("\n\n");
		printf("\nPress enter to view your details");
		getch();
		user_details(username);//this function displays details of the user
        fclose(fp);
        return 1;//returns when login succeeds
	}
}

