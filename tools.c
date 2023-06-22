#include "monty.h"

/**
  * data_init - data
  * @data: data
  * @number: line number
  */
void data_init(data_t *data, unsigned int number)
{
	data->line = NULL;
	data->number = number;
	data->argv = NULL;
	data->opcode = NULL;
}
