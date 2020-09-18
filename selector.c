#include "monty.h"

/**
 * selector - Function for select parameter op.
 * @stack: Double pointer to the head of the Stack.
 * @tokens: Entry parameter.
 * @count: Number of the line.
 * Return: Nothing.
 */
void selector(stack_t **stack, char *tokens, unsigned int count)
{
	instruction_t functions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"swap", swap},
		{"add", add},
		{"sub", sub},
		{"nop", nop},
		{"pop", pop},
		{"div", _div},
		{"mul", mul},
		{"mod", mod},
		{"pchar", pchar},
		{NULL, NULL}
	};

	int format = 0; /* Variable for travel the structure*/

	while (format < 12)
	{
		/* Compare the entry parameter with the functions for execute*/
		if (strcmp(functions[format].opcode, tokens) == 0)
		{
			functions[format].f(stack, count);
			return;
		}
		format++;
			}
	if (tokens[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", count, tokens);
		exit(EXIT_FAILURE);
	}
}
