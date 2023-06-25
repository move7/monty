
#include "monty.h"
/**
* execute - executes the opcode
* @data: data line
* Return: 0 for success otherwise 1
*/

int execute(data_t *data)
{
	unsigned int i = 0;
	stack_t *stack;
	instruction_t opst[] = {
				{"push", _push},
				{"pall", _pall},
				{"pint", _pint},
				{"pop", _pop},
				{"swap", _swap},
				{"nop", _nop},
				{"add", _add},
				{"sub", _sub},
				{"div", _div},
				{"mul", _mul},
				{"mod", _mod},
				{"pchar", _pchar},
				{"pstr", _pstr},
				{"rotl", _rotl},
				{"rotr", _rotr},
				{NULL, NULL}
				};

	for (i = 0; opst[i].opcode != NULL; i++)
	{
		if (strcmp(data->opcode, opst[i].opcode) == 0)
		{
			if (arg_checker(data) == 1)
				return (1);
			stack = (stack_t *) malloc(sizeof(stack_t));
			if (stack == NULL)
			{
				printf("Error: malloc failed\n");
				exit(EXIT_FAILURE);
			}
			if (data->argv)
				stack->n = atoi(data->argv);
			stack->prev = NULL;
			stack->next = NULL;
			opst[i].f(&stack, data->number);
			return (0);
		}
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", data->number, data->opcode);
	return (1);
}

