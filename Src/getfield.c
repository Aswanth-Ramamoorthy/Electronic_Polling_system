#include<conio.h>
#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
#include"getfield.h"
// read the csv file(Particular filed)
char* getfield(char* line, int num)
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