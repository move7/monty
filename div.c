#include "monty.h"
/**
 *  _div -  divides the second top element of the stack
 *  by the top element of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _div(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	current->next->n = current->next->n / header->n;
	header = current->next;
	free(current);
	free(*stack);
}
