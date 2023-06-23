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
		if (isdigit(str[i]))
			return (0);
	}
	return (1);
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
		if (is_valid_number(data->argv) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", data->number);
			return (1);
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
