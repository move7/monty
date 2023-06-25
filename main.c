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
	unsigned int line_number = 0;
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
		line_number++;
		buffer[strcspn(buffer, "\n")] = '\0';
		if ((strlen(buffer) == 0) || (is_empty_line(buffer) == 1))
		{
			free(buffer);
			continue;
		}
		data_init(data, line_number);
		data->line = buffer;
		data->opcode = strtok(buffer, SEPARATORS);
		if (strcmp(data->opcode, "queue") == 0 || strcmp(data->opcode, "stack") == 0)
		{
			data->queue = (strcmp(data->opcode, "queue") == 0)? 1 : 0;
			continue;
		}
		if (data->opcode)
		data->argv = strtok(NULL, SEPARATORS);
		statut = execute(data);
		if (statut == 1)
			break;
	}
	/*free(buffer);*/
	freeAll(data, &file);
	if (statut == 1)
		exit(EXIT_FAILURE);
	return (0);
}

