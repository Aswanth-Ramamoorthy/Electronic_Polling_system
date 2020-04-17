#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#pragma warning(disable : 4996)
#include"getFileColSize.h"
#include"replace_char.h"
#include"getfield.h"
#include "cast_vote.h"
#include"intToString.h"
int cast_vote(char* province) {
	FILE* fp;

	char buf[1024];
	char candidate_id[30];
	printf("\n==========================================");
	printf("\n::::::Cast Your Vote::::::");
	printf("\n------------------------------------------");
	printf("\n----Type in the Candidate Id (e.g Candidate1) and press Enter to cast your vote----------");
	printf("\n\n");
	printf("Enter your Candidate Id here:");
	scanf("%s", &candidate_id);
	if ((strcmp(candidate_id, "Candidate1") == 0) || (strcmp(candidate_id, "Candidate2") == 0) || (strcmp(candidate_id, "Candidate3") == 0) || (strcmp(candidate_id, "Candidate4") == 0) || (strcmp(candidate_id, "Candidate5") == 0))
	{
		fp = fopen("vote_count.csv", "r+");

		if (!fp) {
			printf("Can't open file\n");
		}

		FILE* tempVoteFile = fopen("temp.csv", "w+");
		int row = 0;
		while (fgets(buf, 1024, fp))
		{
			char* tmp = strdup(buf);
			char* tmp2 = strdup(buf);
			int fileColSize = getFileColSize(tmp2);
			static int selectedCandidateColIndexInFile;
			if (row == 0) {
				char* tempHeaderRow = getfield(tmp, 1);
				fprintf(tempVoteFile, tempHeaderRow);
				char* token = strtok(tempHeaderRow, ",");
				int headerCol = 0;
				while (token != NULL) {
					if (strcmp(token, candidate_id) == 0) {
						selectedCandidateColIndexInFile = headerCol;
						break;
					}
					token = strtok(NULL, ",");
					headerCol++;
				}
				row++;
				continue;
			}
			printf("\n");
			char* tempRow = getfield(tmp, 1);
			char* token = strtok(tempRow, ",");
			const char* fieldProvince = token;
			if (strcmp(fieldProvince, province) == 0) {
				int col = 1;
				while (token != NULL) {
					if (selectedCandidateColIndexInFile == (col - 1)) {
						int tempToken = atoi(token);
						tempToken++;
						char str[20];
						if (intToString(tempToken, str) != NULL)
						{
							fprintf(tempVoteFile, strcat(str, ","));
						}

					}
					else {
						if (col == fileColSize) {
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
			else {
				int col = 1;
				while (token != NULL) {
					if (col == fileColSize) {
						fprintf(tempVoteFile, "%s%s", token, "");
					}
					else {
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
		printf(" successfully.Thank you!!!");
		fclose(tempVoteFile);
		remove("vote_count.csv");
		rename("temp.csv", "vote_count.csv");
		return 0;
	}
	else
	{
		printf("Please enter a valid candidate number as given in the hint");
		return cast_vote(province);
	}
	return 0;
}