#include "monty.h"

/**
 * _rotr -  rotates the stack to the bottom.
 * @stack: stack head
 * @line_number: number of the line
 * Return: no return
*/
void _rotr(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *new_header;

	if (stackLen(header) >= 2)
	{
		new_header = header;
		while (new_header->next)
			new_header = new_header->next;
		new_header->next = header;
		new_header->prev->next = NULL;
		new_header->prev = NULL;
		header->prev = new_header;
		header = new_header;
	}
	free(*stack);
}
