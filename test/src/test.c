
/**
 * @file test.c
 *
 * @brief Implementation of automated unit tests.
 *
 * @author Priyanga Soundararajan - priyangasoundararaja@cmail.carleton.ca
 * @author Aswanth Ramamoorthy - aswanthramamoorthy@cmail.carleton.ca
 * @author Vignesh Balaji - vigneshbalaji@cmail.carleton.ca
 * @author Soma Ravindran - somaravindran@cmail.carleton.ca
 */

#include "include/test.h"
#include "include/test_cases.h"
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<conio.h>
#define itoa(x)
#pragma warning(disable:4996)

int test_main()
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
        printf("\n\n\n\t\t\t\t1. Admin Login\t\t2. User Login");
    printf("\n\n\n\t\t\t\t\tENTER YOUR CHOICE: ");
    scanf("%d", &n);
    switch (n)
    {
        case 1:
            admin_login();
            break;
        case 2:
            user_login();
            break;
        default: printf("\n\n\t\t\t\tNO MATCH FOUND");
            printf("\n\n\t\t\tPress Enter to re-Enter the choice");
            if(getch() == 13)
                goto XY;
    }
    return 0;
}