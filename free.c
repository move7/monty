#include "monty.h"

/**
 * freeData - free the data
 * @data: data holder
 */
void freeData(data_t *data)
{
	free(data->line);
	free(data->argv);
	free(data->opcode);
	data->line = NULL;
	data->argv = NULL;
	data->opcode = NULL;

}
/**
 * freeStack - free the stack
 *
 */
void freeStack(void)
{
	stack_t *current;
	stack_t *prev;

	current = header;
	while (current)
	{
		prev = current;
		current = current->next;
		free(prev);
	}

}
/**
 * freeAll - free the stack
 *@data: free data
 *@file: file to close
 */
void freeAll(data_t *data, FILE **file)
{
	freeData(data);
	freeStack();
	fclose(file);
}

