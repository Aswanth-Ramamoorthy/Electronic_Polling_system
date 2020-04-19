
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
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<conio.h>
#define itoa(x)
#pragma warning(disable:4996)


int test_user_login()
{
    static int i = 0;
    char username[15];
    char password[12];
    char* str[1024];
    FILE* fp = fopen("../data/auth.csv", "r");
    printf("--*--*--*--*--*--*--*--*--*");
    printf("\n\tUSER LOGIN\n");
    printf("--*--*--*--*--*--*--*--*--*\n");
    printf("Enter your username:\n");
    scanf("%s", &username);

    printf("Enter your password:\n");
    for (i = 0; i < 6; i++)
    {
        password[i] = getch();
        printf("*");

    }
    password[i] = '\0';
    char string[1024];
    int row_count = 0;
    int field_count = 0, flag = 0;
    if (!fp)
    {
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
            user_login();
    }
    else
    {
        printf("\nStatus:Successful Login");
        printf("\n\n");
        printf("\nPress enter to view your details");
        getch();
        user_details(username);
    }
    fclose(fp);
    return 0;

}

int test_user_details(char* name)
{
    char buf[1024];
    int row = 0, col = 0;
    printf("\n==========================================================================");
    printf("\n\n");
    printf("\n========================");
    printf("\nUSER INFORMATION");
    printf("\n========================");
    FILE* fp = fopen("../data/userdetails.csv", "r");
    if (!fp)
    {
        printf("Can't open file\n");
        return 0;
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
        if (strcmp(field, name) == 0)
        {
            while (field)
            {
                if (col == 0)
                {
                    printf("First Name:\t");
                }
                if (col == 1)
                {
                    printf("Last Name:\t");
                    printf("%s\n", string);
                    col++;
                }
                if (col == 2)
                {
                    printf("Age:\t");

                }
                if (col == 3)
                {
                    printf("Phone:\t");
                }
                if (col == 4)
                {
                    printf("Postal code:\t");
                }
                if (col == 5)
                {
                    printf("Province:\t");
                    printf("%s\n", field);
                    printf("\n\nPress Enter to view the candidates in your Province...!!");
                    getch();
                    candidate_details(field);
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

char* test_intToString(int num, char* str)
{
    if (str == NULL)
    {
        return NULL;
    }
    sprintf(str, "%d", num);
    return str;
}

int test_getFileColSize(char* tmp)
{
    char* tempHeaderRow = test_getfield(tmp, 1);
    char* token = strtok(tempHeaderRow, ",");
    int totalCols = 0;
    while (token != NULL)
    {
        token = strtok(NULL, ",");
        totalCols++;
    }
    return totalCols;
}

char* test_getfield(char* line, int num)
{
    for (char* tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";\n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int test_cast_vote(char* province)
{
    FILE* fp;

    char buf[1024];
    char candidate_id[30];
    printf("\n==========================================");
    printf("\n::::::Cast Your Vote::::::");
    printf("\n------------------------------------------");
    printf("\n----Type in the Candidate Id (e.g Candidate1) and press Enter to cast your vote----------");
    printf("\n\n");
    printf("Enter your preferred Candidate Id here:");
    scanf("%s", &candidate_id);
    if ((strcmp(candidate_id, "Candidate1") == 0) || (strcmp(candidate_id, "Candidate2") == 0) || (strcmp(candidate_id, "Candidate3") == 0) || (strcmp(candidate_id, "Candidate4") == 0) || (strcmp(candidate_id, "Candidate5") == 0))
    {
        fp = fopen("../data/vote_count.csv", "r+");

        if (!fp)
        {
            printf("Can't open file\n");
            return -1;
        }

        FILE* tempVoteFile = fopen("../data/temp.csv", "w+");
        int row = 0;
        while (fgets(buf, 1024, fp))
        {
            char* tmp = strdup(buf);
            char* tmp2 = strdup(buf);
            int fileColSize = test_getFileColSize(tmp2);
            static int selectedCandidateColIndexInFile;
            if (row == 0)
            {
                char* tempHeaderRow = test_getfield(tmp, 1);
                fprintf(tempVoteFile, tempHeaderRow);
                char* token = strtok(tempHeaderRow, ",");
                int headerCol = 0;
                while (token != NULL)
                {
                    if (strcmp(token, candidate_id) == 0)
                    {
                        selectedCandidateColIndexInFile = headerCol;
                        //break;
                    }
                    token = strtok(NULL, ",");
                    headerCol++;
                }
                row++;
                continue;
            }
            printf("\n");
            char* tempRow = test_getfield(tmp, 1);
            char* token = strtok(tempRow, ",");
            const char* fieldProvince = token;
            if (strcmp(fieldProvince, province) == 0)
            {
                int col = 1;
                while (token != NULL) {
                    if (selectedCandidateColIndexInFile == (col - 1))
                    {
                        int tempToken = atoi(token);
                        tempToken++;
                        char str[20];
                        if (test_intToString(tempToken, str) != NULL)
                        {
                            fprintf(tempVoteFile, strcat(str, ","));
                        }

                    }
                    else {
                        if (col == fileColSize)
                        {
                            fprintf(tempVoteFile, "%s%s", token, "");
                        }
                        else {
                            fprintf(tempVoteFile, "%s%s", token, ",");
                        }
                    }

                    token = strtok(NULL, ",");
                    col++;
                }
            }
            else
            {
                int col = 1;
                while (token != NULL)
                {
                    if (col == fileColSize)
                    {
                        fprintf(tempVoteFile, "%s%s", token, "");
                    }
                    else
                    {
                        fprintf(tempVoteFile, "%s%s", token, ",");
                    }
                    token = strtok(NULL, ",");
                    col++;
                }
            }
            free(tmp);
            row++;
        }
        fclose(fp);
        printf("\n");
        printf("Vote casted for your candidate: ");
        printf("%s", candidate_id);
        printf(" successfully.");
        printf("\n\nThank you!!!");
        printf("\n\n");
        printf("Press any key to exit");
        getch();
        fclose(tempVoteFile);
        remove("../data/vote_count.csv");
        rename("../data/temp.csv", "../data/vote_count.csv");
        return 0;
    }
    else
    {
        printf("Please enter a valid candidate number as given in the e.g");
        printf("\n\n");
        return cast_vote(province);
    }
    //return 0;
}

int test_candidate_details(char* province)
{
    char buf[1024];
    printf("\n==========================================");
    printf("\nCANDIDATES INFORMATION");
    printf("\n------------------------------------------");
    FILE* fp = fopen("../data/candidate_details.csv", "r");
    if (!fp)
    {
        printf("Can't open file\n");
        return -1;
    }

    int row = 0;
    //removing carriage return and new line character - due to getchar() ???
    province = strtok(province, "\r\n");

    while (fgets(buf, 1024, fp))
    {
        if (row == 0)
        {
            row++;
            continue;
        }

        char* tmp = strdup(buf);
        printf("\n");
        char* tempRow = test_getfield(tmp, 1);

        char* token = strtok(tempRow, ",");
        const char* fieldProvince = token;

        if (strcmp(fieldProvince, province) == 0)
        {
            int col = 1;
            while (token != NULL)
            {
                if (col == 1)
                {
                    printf("Below are your candidates for your Province:");
                    printf("%s", token);
                    printf("\n--------------------------");
                    col++;
                    continue;
                }
                else if (col > 2)
                {
                    printf("\nCandidate");
                    printf("%d", col - 2);
                    printf(": ");
                    printf("%s", token);
                    printf("\n");
                }

                token = strtok(NULL, ",");
                col++;
            }
        }

        free(tmp);
        row++;
    }

    fclose(fp);
    printf("\nPress Enter to vote...!!");
    getch();
    printf("\n\n\n");
    int vote_casted = cast_vote(province);
    return vote_casted;
}

int test_admin_login()
{
    static int i = 0;
    char adminID[15];
    char adminpass[12];
    printf("Enter your Admin-ID:\n");
    scanf("%s", &adminID);
    printf("Enter your password:\n");
    for (i = 0; i < 8; i++)
    {
        adminpass[i] = getch();
        printf("*");
    }
    adminpass[i] = '\0';
    if (strcmp(adminID, "Admin") == 0)
    {
        if (strcmp(adminpass, "white!23") == 0)
        {
            printf("\nWelcome.Login Success!");
            return 1;

        }
        else
        {
            printf("\nwrong password");
            return 0;
        }
    }
    else
    {
        return -1;
    }
}

}


char* test_replace_char(char* str, char find, char replace)
{
    char* current_pos = strchr(str, find);
    while (current_pos)
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}


int test_cases()
{
    int value, choice;
    FILE* test_output = fopen("../test/results/test_output.csv", "w");
    printf("\n1. Enter 1 to test admin login function.\n");
    printf("\n2. Enter 2 to test attemp value function.\n");
    printf("\n3. Enter 3 to test user details function.\n");
    printf("\n4. Enter 4 to test cast vote function.\n");
    printf("\n5. Enter 5 to test display results function.\n");
    printf("\n6. Enter 6 to test candidate details function.\n");
    printf("\n7. Enter 7 to test user login function.\n");
    printf("\n8. Enter 8 to test secondary authentication function.\n");
    scanf("%d", &choice);
	switch (choice)
	{
	case 1:
		printf("\nTesting admin login function\n");

		/* Test case 1 - When password is wrong */

		value = test_admin_login(); //Passing correct username and wrong password

		if (value == 0)
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Username: Correct, Password:Wrong, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Username: Correct, Password:Wrong, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/* Test case 2 - When username and password are correct */

		value = test_admin_login("Admin", "white!23"); //Passing correct username and correct password

		if (value == 1)
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Username: Correct, Password:Correct, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Username: Correct, Password:Correct, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/* Test case 3 - Valid file */

		value = test_admin_login("admin", "white!23"); //Passing wrong username and correct password

		if (value = -1)
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Username: Wrong, Password:Correct, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Username: Wrong, Password:Correct, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		fclose(test_output);
		break;

	case 2:
		printf("\nTesting attemp value function\n");

		/* Test case - User must not be allowed to make more than one attempt to vote */
		//Input parameter does not affect filename as it is passed internally

		/*Test case 1*/
		int value = test_attemt_value("Hari", "Black7");// First attempt by user "Hari"
		if (value = 1)
		{

			char c[100];
			sprintf(c, "1)Criteria Passed with Username:Hari , Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Username:Hari , Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/
		int value = test_attemt_value("Hari", "Black7");// Second attempt by user "Hari"
		if (value = 0)
		{

			char c[100];
			sprintf(c, "2)Criteria Passed with Username:Hari , Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Username:Hari , Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		break;


	case 3:
		printf("\n\nTesting user details function.");

		/* Test case  - Display user details on success */
		//Input parameter does not affect filename as it is passed internally


		/*Test case 1*/
		printf("\n");
		int value = test_user_details("Hari");
		printf("\n");
		if (value == 0)//When file not found
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Username: Hari, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Username: Hari, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/

		if (value == 1) // When Username is valid
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Username: Hari, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Username: Hari, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 3*/
		int value = test_user_details("Sree");
		printf("\n");
		if (value == -1) // When Username is not valid
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Username: Sree, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Username: Sree, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;



	case 4:
		printf("\n\nTesting cast vote function");

		/* Test case  - Vote count should be incremented for each candidate from votes by users under each province */
		//Input parameter does not affect filename as it is passed internally

		int value = test_cast_vote("Ontario");

		/*Test case 1*/
		printf("\n");
		if (value == 0)//When file not found
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Province: Ontario, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Province: Ontario, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/

		if (value == 1) // When Candidate_Id is valid
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Province: Ontario, Candidate_Id: Candidate1, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Province: Ontario, Candidate_Id: Candidate1, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 3*/
		printf("\n");
		if (value == -1) // When Candidate_Id is not valid
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Province: Ontario, Candidate_Id: Candi1, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Province: Ontario, Candidate_Id: Candi1, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;

	case 5:
		printf("\n\nTesting display results function");
		/* Test case  - Display results of poll if the file exists */
		int value = test_display_count();

		/*Test case 1*/
		//Input parameter does not affect filename as it is passed internally
		printf("\n");
		if (value == 0)//When file not found
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Filename: vote_count.csv, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Filename: vote_count.csv, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/

		if (value == 1) // When Filename is valid
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Filename: vote_count.csv, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Filename: vote_count.csv, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 3*/
		printf("\n");
		if (value == -1) // When Filename is not valid
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Filename: votecount.csv, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Filename: votecount.csv, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;

	case 6:
		printf("\n\nTesting candidate details function");

		/* Test case  - Display candidate details if the file exists */
		int value = test_candidate_details("Ontario");

		/*Test case 1*/
		printf("\n");
		if (value == 0)//When file not found
		//Input parameter does not affect filename as it is passed internally
		//No other criteria is checked here as this function is called from user_details function where all conditions are already checked
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Province: Ontario, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Province: Ontario, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;

	case 7:
		printf("\n\nTesting user login function");

		/* Test case  - Check whether the user is authenticated if file is found */
		int value = test_user_login();

		/*Test case 1*/
		printf("\n");
		if (value == 0)//When file not found
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Username: Vignesh, Password:Black2, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Username: Vignesh, Password:Black2, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/

		if (value == 1) // When Username and Password are correct
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Username: Vignesh, Password:Black2, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Username: Vignesh, Password:Black2, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);

		}

		/*Test case 3*/
		printf("\n");
		if (value == -1) // When Username and Password are incorrect
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Username: Vignesh, Password:Black, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Username: Vignesh, Password:Black, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;

	case 8:
		printf("\n\nTesting secondary authentication function");


		/* general Test case  - check for total value of admitted patients if file exists */
		//Input parameter does not affect filename as it is passed internally

		int value = test_secondary_authentication("Hari");

		/*Test case 1*/
		printf("\n");
		if (value == 0)//When file not found
		{
			char c[100];
			sprintf(c, "1)Criteria Passed with Username: Aswanth, ID Name:ID-Votercard, ID Number:1111, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "1)Criteria Failed with Username: Aswanth, ID Name:ID-Votercard, ID Number:1111, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 2*/

		if (value == 1) // When user secondary details are valid
		{
			char c[100];
			sprintf(c, "2)Criteria Passed with Username: Aswanth, ID Name:ID-Votercard, ID Number:1111, Expected Output: 0, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "2)Criteria Failed with Username: Aswanth, ID Name:ID-Votercard, ID Number:1111, Expected Output: 1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}

		/*Test case 3*/
		printf("\n");
		if (value == -1) // When user secondary details are not valid
		{
			char c[100];
			sprintf(c, "3)Criteria Passed with Username: Aswanth, ID Name:ID-Votercard, ID Number:111, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		else
		{
			char c[100];
			sprintf(c, "3)Criteria Failed with Username: Aswanth, ID Name:ID-Votercard, ID Number:111, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;
	}