#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include"..include/getFileColSize.h"
#include"..include/replace_char.h"
#include"..include/getfield.h"
#include "..include/cast_vote.h"
#include"..include/intToString.h"
int cast_vote(char* province) 
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
	scanf("%s", &candidate_id);//inputs unique candidate_id from user
	if ((strcmp(candidate_id, "Candidate1") == 0) || (strcmp(candidate_id, "Candidate2") == 0) || (strcmp(candidate_id, "Candidate3") == 0) || (strcmp(candidate_id, "Candidate4") == 0) || (strcmp(candidate_id, "Candidate5") == 0))
	{
		fp = fopen("../data/vote_count.csv", "r+");

		if (!fp) 
		{
			printf("Can't open file\n");
			return 0;//returns when file does not exist
		}

		FILE* tempVoteFile = fopen("../data/temp.csv", "w+");
		int row = 0;
		while (fgets(buf, 1024, fp))
		{
			char* tmp = strdup(buf);
			char* tmp2 = strdup(buf);
			int fileColSize = getFileColSize(tmp2);
			static int selectedCandidateColIndexInFile;
			if (row == 0)
			{
				char* tempHeaderRow = getfield(tmp, 1);
				fprintf(tempVoteFile, tempHeaderRow);
				char* token = strtok(tempHeaderRow, ",");
				int headerCol = 0;
				while (token != NULL)
				{
					if (strcmp(token, candidate_id) == 0)
					{
						selectedCandidateColIndexInFile = headerCol;
						//break;
						return 1;//returns when candidate_id matches
					}
					token = strtok(NULL, ",");
					headerCol++;
					else
                    {
					    return -1;//returns when candidate_id does not match
                    }
				}
				row++;
				continue;
			}

			printf("\n");
			char* tempRow = getfield(tmp, 1);
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
						if (intToString(tempToken, str) != NULL)
						{
							fprintf(tempVoteFile, strcat(str, ","));//writes incremented vote to temp.csv file
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
			} else 
			{
				int col = 1;
				while (token != NULL)
				{
					if (col == fileColSize)
					{
						fprintf(tempVoteFile, "%s%s", token, "");
					} else
					
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
		remove("../data/vote_count.csv");//deletes vote_count.csv
		rename("../data/temp.csv", "../data/vote_count.csv");//renames temp.csv to vote_count.csv
		//return 0;
	}
	else
	{
		printf("Please enter a valid candidate number as given in the e.g");
		printf("\n\n");
		cast_vote(province);
	}
}