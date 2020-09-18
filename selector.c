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
		{NULL, NULL}
	};

	int format = 0; /* Variable for travel the structure*/

	while (format < 8)
	{
		/* Compare the entry parameter with the functions for execute*/
		if (strcmp(functions[format].opcode, tokens) == 0)
		{
			functions[format].f(stack, count);
			return;
		}
		format++;
	}
	fprintf(stderr, "L%u: unknown instruction %s\n", count, tokens);
	exit(EXIT_FAILURE);
}
