#include "monty.h"

/**
 * _pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @stack: stack head
 * @line_number: number of the line
 * Return: no return
*/
void _pstr(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	stack_t *tmp;

	tmp = header;
	while (tmp)
	{
		if (tmp->n > 127 || tmp->n <= 0)
			break;
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
	free(*stack);
}
