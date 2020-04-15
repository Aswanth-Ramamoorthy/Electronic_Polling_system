#include<conio.h>
#include<stdio.h>
#include<string.h>
#include <stdlib.h>
#include "getFileColSize.h"
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
