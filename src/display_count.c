/**
 * @file display_count.c
 *
 * @brief Implementation of display_count function to display the final count of the
 * votes casted.
 *
 *
 * @author Priyanga Soundararajan - priyangasoundararaja@cmail.carleton.ca
 *
 *
 **/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"../include/display_count.h"

/**
 * The function displays a final cont of the votes present in the file.
 * @param[in] the function takes “filename” as input parameter.
 *
 * @param[out] the function displays the "vote_count.csv" file as the output.
 *
 *
 * @return Return 0 when file opens and return 1 when filename is invalid.
 *
 **/

int display_count(){

	char filename[100];

	printf("\nEnter the filename in the following format to open \n");
	printf("\nExample: ../src/data/filename\n");
	scanf("%s", filename);//reads file name from input by admin 

	// Open file
	FILE* fp = fopen(filename, "r");//file to display
	if (fp == NULL){

		printf("Cannot open file \n");
		printf("\n\n\t(PRESS [Y] TO RE-ENTER file name)");

		if (getch() == 'y' || getch() == 'Y') {
			display_count();//option to retry 

		}
	}

	// Read contents from file
	char c = fgetc(fp);
	while (c != EOF){

		printf("%c", c);
		c = fgetc(fp); // To read contents from file
	}
	fclose(fp);
	return 0;
}