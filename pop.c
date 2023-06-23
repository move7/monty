#include "monty.h"
/**
 * _pop -  removes the top element
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _pop(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current;

	current = header;
	header = current->next;
	free(current);
}
