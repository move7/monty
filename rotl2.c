#include "monty.h"

/**
 * _rotl2 - rotates the stack to the top
 * without free stack.
 * @stack: stack head
 * @line_number: number of the line
 * Return: no return
*/
void _rotl2(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *tmp, *new_header;

	if (stackLen(header) >= 2)
	{
		tmp = header;
		new_header = header->next;
		new_header ->prev = NULL;
		while (tmp -> next)
			tmp = tmp->next;
		tmp->next = header;
		header->next = NULL;
		header->prev = tmp;
		header = new_header;
	}	
}
