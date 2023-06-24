#include "monty.h"
/**
 *  _add -  adds the top two elements of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _add(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	current->next->n = current->next->n + header->n;
	header = current->next;
	free(current);
	free(*stack);
}
