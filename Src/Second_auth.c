#pragma warning(disable : 4996)
#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"second_auth.h"

int second_auth(char *name)
{
	char ID_type[20];
	char ID_number[20];
	char name_on_ID[30];
	printf("\n===========================================================================");
	printf("\nSecondary Authentication");
	printf("\n\n\nBelow are the list of Available ID's that are accepted to cast your vote");
	printf("\n\t 1.Voter card.\n\t 2.Passport.\n\t 3.Provincial card");
	printf("\n\nIf you have any one of this ID's Press Enter to proceed...!!\n");
	getch();
	printf("\n===========================================================================\n");

	printf("\n\n");

	printf("Please enter your ID type\n\t(Hint:ID-Votercard \n\t\tID-Passport\n\t\tID-ProvincialCard) :");
	scanf("%s", &ID_type);

	printf("\nEnter your name (Exactly printed on your ID):");
	scanf("%s", &name_on_ID);

	printf("\nEnter the ID-number(Exactly Printed on your ID):");
	scanf("%s", &ID_number);
	int b = atoi(ID_number);
	FILE* fp = fopen("second_auth1.csv", "r");
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
		if (strcmp(field, name_on_ID) == 0 && strcmp(name_on_ID, name) == 0);
		{
			field = strtok(NULL, ",");
			if (strcmp(field, ID_type) == 0)
			{

				field = strtok(NULL, ",");
				int a = atoi(field);
				if (a == b)
				{
					while (field) {
						//printf("%s", field);
						flag++;
						field_count++;
						break;
					}
				}
			}
		}
		if (strcmp(name, name_on_ID) != 0)
		{
			flag = 0;
		}
	}
	if (flag == 0) {
		printf("\nStatus:Invalid login");
		printf("\n");
		printf("\n\n\t\t\t\t  (PRESS [Y] TO RE-LOGIN)");
		if (getch() == 'y' || getch() == 'Y')
			system("clear");
		second_auth(name);
	}
	else
	{
		printf("\nStatus:Successful Login");
		printf("\n\nSelected ID is Valid");
		printf("\nPress Enter to display your details...!!");
		getch();
		user_details(name);

	}
	fclose(fp);

}

