#include<conio.h>
#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
#include "getFileColSize.h"
#include"getfield.h"
int getFileColSize(char* tmp) {
	char* tempHeaderRow = getfield(tmp, 1);
	char* token = strtok(tempHeaderRow, ",");
	int totalCols = 0;
	while (token != NULL) {
		token = strtok(NULL, ",");
		totalCols++;
	}
	return totalCols;
}
