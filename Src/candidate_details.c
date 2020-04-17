#include<conio.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#pragma warning(disable : 4996)
#include "getfield.h"
#include"candidate_details.h"
int candidate_details(char* province)
{
	char buf[1024];
	printf("\n==========================================");
	printf("\nCANDIDATES INFORMATION");
	printf("\n------------------------------------------");
	//fp = fopen("userdetails.csv", "r");
	FILE* fp = fopen("candidate_details.csv", "r");
	if (!fp) {
		printf("Can't open file\n");
	}

	int row = 0;
	//removing carriage return and new line character - due to getchar() ???
	province = strtok(province, "\r\n");

	while (fgets(buf, 1024, fp))
	{
		if (row == 0) {
			row++;
			continue;
		}

		char* tmp = strdup(buf);
		printf("\n");
		char* tempRow = getfield(tmp, 1);

		char* token = strtok(tempRow, ",");
		const char* fieldProvince = token;

		if (strcmp(fieldProvince, province) == 0) {
			int col = 1;
			while (token != NULL) {
				if (col == 1) {
					printf("Below are your candidates for your Province:");
					printf("%s", token);
					printf("\n--------------------------");
					col++;
					continue;
				}
				else if (col > 2) {
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
	int vote_casted = cast_vote(province);
	return vote_casted;
}
