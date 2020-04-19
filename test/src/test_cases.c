
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

		value = admin_login("Admin", "wrong"); //Passing correct username and wrong password

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

		value = admin_login("Admin", "white!23"); //Passing correct username and correct password

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

		value = admin_login("admin", "white!23"); //Passing wrong username and correct password

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
		int value = attemt_value("Hari", "Black7");// First attempt by user "Hari"
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
		int value = attemt_value("Hari", "Black7");// Second attempt by user "Hari"
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
		int value = user_details("Hari");
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
		int value = user_details("Sree");
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

		int value = cast_vote("Ontario");

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
		int value = display_count();

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
			sprintf(c, "3)Criteria F
			ailed with Filename: votecount.csv, Expected Output: -1, Output: %d .\n", value);
			printf(c);
			fprintf(test_output, c);
		}
		break;

	case 6:
		printf("\n\nTesting candidate details function");

		/* Test case  - Display candidate details if the file exists */
		int value = candidate_details("Ontario");

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
		int value = user_login();

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

		int value = secondary_authentication("Hari");

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