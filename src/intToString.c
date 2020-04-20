#include<conio.h>
#include<stdio.h>
#include<string.h>
#include"../include/intToString.h"
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