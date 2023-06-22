#include "monty.h"

/**
 * _pall - display stack
 * @stack: stack head
 * @line_number: number of the line
 * Return: no return
*/
void _pall(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *tmp;

	tmp = header;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
