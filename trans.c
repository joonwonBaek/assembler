#include "myas.h"

int instr_trans(char *op, char *args, char* mcode)
{
	char *src;
	char *dest;

	// check syntax
	if(!is_valid(op, args)){
		printf("Error: %s %s is not valid\n", op, args);
		return 0;
	}


	strcpy(mcode, "AB CD EF");

	src = strtok(args, ",");
	dest = strtok(NULL, "\n");

	if(src[0] == '%' && dest[0] == '%')
		strcpy(mcode, "89");
	else if(src[0] == '(' && dest[0] == '%')
		strcpy(mcode, "8b");
	else if(src[0] == '-' && dest[0] == '%')
		strcpy(mcode, "8b");
	else if(src[0] == '0' && dest[0] == '%')
		strcpy(mcode, "a1");
	else if(src[0] == '%' && dest[0] == '0')
		strcpy(mcode, "a3");
	else if(src[0] == '$')
	{
		if(strcmp(dest, "%eax") == 0)
			strcpy(mcode, "b8");
		else if(strcmp(dest, "%ecx") == 0)
			strcpy(mcode, "b9");
		else if(strcmp(dest, "%edx") == 0)
			strcpy(mcode, "ba");
		else if(strcmp(dest, "%ebx") == 0)
			strcpy(mcode, "bb");
		else if(strcmp(dest, "%esp") == 0)
			strcpy(mcode, "bc");
		else if(strcmp(dest, "%ebp") == 0)
			strcpy(mcode, "bd");
		else if(strcmp(dest, "%esi") == 0)
			strcpy(mcode, "be");
		else if(strcmp(dest, "%edi") == 0)
			strcpy(mcode, "bf");
		else
			strcpy(mcode, "error");
	}

	else
		strcpy(mcode, "error");
	
	return 1;
}
