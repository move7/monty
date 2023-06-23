#define _GNU_SOURCE
#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

stack_t *header = NULL;
/**
* main - function for monty code interpreter
* @argc: argument count
* @argv: argument value
*
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	data_t *data = NULL;
	char *buffer = NULL;
	size_t nread = 0;
	ssize_t line_read;
	unsigned int line_number = 1;
	int statut;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = f_open(argv[1]);
	data = malloc(sizeof(data_t));
	if (data == NULL)
	{
		fprintf(stderr, "Failed to allocate memory for data\n");
		exit(EXIT_FAILURE);
	}
	while ((line_read = getline(&buffer, &nread, file)) != -1)
	{
		buffer[strcspn(buffer, "\n")] = '\0';
		if ((strlen(buffer) == 0) || (is_empty_line(buffer) == 1))
			continue;
		data_init(data, line_number++);
		data->line = (char *)malloc((strlen(buffer) + 1) * sizeof(char));
		strcpy(data->line, buffer);
		data->opcode = strtok(buffer, SEPARATORS);
		if (data->opcode)
		data->argv = strtok(NULL, SEPARATORS);
		statut = execute(data);
		if (statut == 1)
		{
			freeAll(data, &file);
			exit(EXIT_FAILURE);
		}
	}
	freeAll(data, &file);
	return (0);
}

