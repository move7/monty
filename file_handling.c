#include "monty.h"
/**
* f_open - open file
* @name: name of the file
* Return: file
*/
FILE *f_open(char *name)
{
	FILE *fptr;

	fptr = fopen(name, "r");
	if (fptr == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", name);
		exit(EXIT_FAILURE);
	}
	return (fptr);
}

