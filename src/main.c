#include "../include/Function.h"
#include<conio.h>
#include<stdio.h>
#include<string.h>


int main()
{
	int n;
	printf("\n\t\t\t\t==========================================");
	printf("\n\t\t\t\tWELCOME TO THE PRESIDENTIAL ELECTIONS 2020");
	printf("\n\t\t\t\t==========================================");
	printf("\n\nInstructions:\n\n");
	printf("1.You can vote only once.\n2.Login using your User-ID and Password.\n3.Proceed to vote if your information displayed is correct.\n4.Please be fair and impartial in voting");
	printf("\n\n\t\t\t\tIf you agree Press Enter to proceed...!!");
	if (getch() == 13)
		XY:
	printf("\n\n\n\t\t\t\t1. Admin Login\t\t2. User Login");//option to choose level of access
	printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
	scanf("%d", &n);//fetching input from user
	switch (n)
	{
	case 1:
		admin_login();//secure admin login to view results
		break;
	case 2: 
		user_login();//access to the polling system
		break;
	default: printf("\n\n\t\t\t\tNO MATCH FOUND");
		printf("\n\n\t\t\tPress Enter to re-Enter the choice");
		if(getch() == 13)
			goto XY;//option to retry
	}
	return 0;
}