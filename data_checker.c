#include "monty.h"

/**
 * is_valid_number - check if the str is a number
 * @str: string to be checked
 * Return: 0 for success otherwise 1
 */
int is_valid_number(const char *str)
{
	size_t i;

	if (str[0] == '\0')
		return (1);
	for (i = 0; i < strlen(str); i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			return (1);
	}
	return (0);
}
/**
 * arg_checker - check if arguments are valid
 * @data: data holder
 * Return: 0 for success otherwise 1
 */
int arg_checker(data_t *data)
{
	if (strcmp(data->opcode, "push") == 0)
	{
		if (!data->argv || (is_valid_number(data->argv) == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", data->number);
			return (1);
		}
	}
	else
	{
		if (strcmp(data->opcode, "pint") == 0)
		{
			if (!header)
			{
				fprintf(stderr, "L%u: can't pint, stack empty\n", data->number);
				return (1);
			}
		}
		else
		{
			if (strcmp(data->opcode, "pop") == 0)
			{
				if (!header)
				{
					fprintf(stderr, "L%d: can't pop an empty stack\n", data->number);
					return (1);
				}

			}
			else
			{
				if (strcmp(data->opcode, "swap") == 0)
				{
					if (stackLen(header) < 2)
					{
						fprintf(stderr, "L%d: can't swap, stack too short\n", data->number);
						return (1);
					}

				}
				else
				{
					if (strcmp(data->opcode, "add") == 0)
					{
						if (stackLen(header) < 2)
						{
							fprintf(stderr, "L%d: can't add, stack too short\n", data->number);
							return (1);
						}
					}
					else
					{
						if (strcmp(data->opcode, "sub") == 0)
						{
							if (stackLen(header) < 2)
							{
								fprintf(stderr, "L%d: can't sub, stack too short\n", data->number);
								return (1);
							}
						}
					}
				}
			}
		}
	}
	return	(0);
}
/**
 * is_empty_line - check if line is empty
 * @str: line
 * Return: 0 for success otherwise 1
 */
int is_empty_line(char *str)
{
	size_t i;

	for (i = 0; i < strlen(str); i++)
	{
		if (!isspace(str[i]))
			return (0);
	}
	return (1);
}
