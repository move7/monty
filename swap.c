#include "monty.h"
/**
 *  _swap -  swaps the top two elements
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _swap(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *current, *current_next;
	int temp;

	current = header;
	current_next = header->next;
	temp = current->n;
	current->n = current_next->n;
	current_next->n = temp;
}
