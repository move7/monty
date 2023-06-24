#include "monty.h"
/**
 *  _mod -  computes the rest of the division of the second 
 *  top element of the stack by the top element of the stack.
 *  by the top element of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _mod(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	current->next->n = current->next->n % header->n;
	header = current->next;
	free(current);
	free(*stack);
}
