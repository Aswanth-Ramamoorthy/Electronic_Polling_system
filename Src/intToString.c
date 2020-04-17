#include<conio.h>
#include<stdio.h>
#include<string.h>
#pragma warning(disable : 4996)
#include"intToString.h"
// Convert int to string
char* intToString(int num, char* str)
{
	if (str == NULL)
	{
		return NULL;
	}
	sprintf(str, "%d", num);
	return str;
}