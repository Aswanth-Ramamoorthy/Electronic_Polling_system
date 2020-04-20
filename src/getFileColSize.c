#include<conio.h>
#include<stdio.h>
#include<string.h>
#include "../include/getFileColSize.h"
#include"../include/getfield.h"
// For finding  the column size of the csv files
int getFileColSize(char* tmp)
{
	char* tempHeaderRow = getfield(tmp, 1);
	char* token = strtok(tempHeaderRow, ",");
	int totalCols = 0;
	while (token != NULL)
	{
		token = strtok(NULL, ",");
		totalCols++;
	}
	return totalCols;
}
