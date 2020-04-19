#include<stdio.h>
#include<conio.h>
#include<string.h>
#include"../include/display_count.h"
int display_count()
{
	char filename[100];

	printf("\nEnter the filename to open \n");
	scanf("%s", filename);//reads file name from input by admin 

	// Open file
	FILE* fp = fopen(filename, "r");//file to display
	if (fp == NULL)
	{
		printf("Cannot open file \n");
		printf("\n\n\t(PRESS [Y] TO RE-ENTER file name)");
		if (getch() == 'y' || getch() == 'Y')
		display_count();//option to retry 
		return 0;//returns when filename is invalid
	}

	char c = fgetc(fp);
	while (c != EOF)
	{
		printf("%c", c);
		c = fgetc(fp); 	// To read contents from file
		return 1;
	}

	fclose(fp);
	return -1;
}