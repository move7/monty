#include "monty.h"
/**
 *  _mul - multiplies the second top element of the stack
 *  with the top element of the stack 
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _mul(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	current->next->n = current->next->n * header->n;
	header = current->next;
	free(current);
	free(*stack);
}
