#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"..include/admin_login.h"

int admin_login()
{
	static int i = 0;
	char adminID[15];
	char adminpass[12];
	printf("Enter your Admin-ID:\n");
	scanf("%s", &adminID);//inputs admin ID from user
	printf("Enter your password:\n");
	for (i = 0; i < 8; i++)
	{
		adminpass[i] = getch();
		printf("*");//hides password from user input terminal
	}
	adminpass[i] = '\0';
	if (strcmp(adminID, "Admin") == 0)
	{
		if (strcmp(adminpass, "white!23") == 0)
		{
			printf("\nWelcome.Login Success!");
			return 1;//returns when login succeeds
	
		}
		else 
		{
			printf("\nwrong password");
			return 0;//returns when password is incorrect
		}
	}
	else
    {
	    return -1;//returns if admin ID is incorrect
    }
	
}


