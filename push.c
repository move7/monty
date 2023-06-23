#include "monty.h"
/**
 * _push - add node to the stack
 * @stack: stack head
 * @line_number: line number
 * Return: no return
*/
void _push(stack_t **stack,
		__attribute((unused)) unsigned int line_number)
{
	if (header)
	{
		(*stack)->next = header;
		header->prev = *stack;
	}
	header = *stack;
}
