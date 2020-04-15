#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "global.h"
#include"user_details.h"
int user_login()
{
	char username[15];
	char password[12];
	char* str[1024];
	FILE* fp = fopen("auth.csv", "r");

	printf("Enter your username:\n");
	scanf("%s", &username);

	printf("Enter your password:\n");
	scanf("%s", &password);
	for (i = 0; i < 6; i++)
	{
		password[i] = getch();
		printf("*");

	}
	password[i] = '\0';
	char string[1024];
	int row_count = 0;
	int field_count = 0, flag = 0;
	if (!fp) {
		printf("Can't open file\n");
		return 0;
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
		if (strcmp(field, username) == 0)
		{
			field = strtok(NULL, ",");
			if (strcmp(field, password) == 0)
			{
				while (field) {
					printf("%s", field);
					flag++;
					field_count++;
					break;
				}
			}
		}
	}
	if (flag == 0) {
		printf("\nStatus:Invalid login");
		printf("\n");
                printf("\n\n\t  (PRESS [Y] TO RE-LOGIN)");
		if (getch() == 'y' || getch() == 'Y')
		system("clear");

	}
	else
	{
		printf("\nStatus:Successful Login");
		//const int secondary_authentication = second_auth(username);
		//return secondary_authentication;
		user_details(username);
	}
	fclose(fp);

}
