#include "monty.h"
/**
 * _pchar - prints the char at the top of the stack, 
 * followed by a new line
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _pchar(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	printf("%c\n", header->n);
	free(*stack);
}
