#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

#define SEPARATORS " \t\n"
/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

extern stack_t *header;
/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct data_t - store data line
 * @line: line reades
 * @number: number of line
 * @argv: argument
 * @opcode: opcode
 *
 *Description: data
 */
typedef struct data_t
{
	char *line;
	unsigned int number;
	char *argv;
	char *opcode;
} data_t;

/*------tools.c*/
void data_init(data_t *data, unsigned int number);
int stackLen(stack_t *stack);
/*-------------------free.c*/
void freeData(data_t *data);
void freeStack(void);
void freeAll(data_t *data, FILE **file);
/*-----request_handelin.c*/
int execute(data_t *data);
/*----------file_handling.c*/
FILE *f_open(char *name);
/*--------data_checker.c*/
int is_valid_number(const char *str);
int arg_checker(data_t *data);
int is_empty_line(char *str);
/*----------push.c */
void _push(stack_t **head,
		unsigned int __attribute((unused)) line_number);
/*----------pall.c---*/
void _pall(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number);
void _pint(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number);
void _pop(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number);
void _swap(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number);
void _nop(__attribute((unused)) stack_t **stack,
		__attribute((unused)) unsigned int line_number);
void _add(__attribute((unused)) stack_t **stack,
                __attribute((unused)) unsigned int line_number);
void _sub(__attribute((unused)) stack_t **stack,
                __attribute((unused)) unsigned int line_number);
void _div(__attribute((unused)) stack_t **stack,
                __attribute((unused)) unsigned int line_number);
void _mul(__attribute((unused)) stack_t **stack,
                __attribute((unused)) unsigned int line_number);
void _mod(__attribute((unused)) stack_t **stack,
                __attribute((unused)) unsigned int line_number);
#endif

