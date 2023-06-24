#include "monty.h"
/**
 *  _sub -  subtracts the top element of the stack from the second 
 *  top element of the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _sub(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	current->next->n = current->next->n - header->n;
	header = current->next;
	free(current);
	free(*stack);
}
