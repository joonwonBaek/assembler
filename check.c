#include "myas.h"

int is_valid(char *op, char *args)
{
	//printf("if valid, return 1\n");
	//printf("otherwise, return 0\n");

	char *src;
	char *dest;
	char arr[200];
	
	strcpy(arr, args);

	src = strtok(arr, ",");
	dest = strtok(NULL, "\n");

	if(src[0] == '(' && dest[0] == '(')
		return 0;
	else if(src[0] == '$' && dest[0] == '$')
		return 0;

	
	return 1;
}
