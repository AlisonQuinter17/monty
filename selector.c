#include "monty.h"

/**
 * selector - Function for select parameter op.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 * Return: Nothing.
 */
void selector(stack_t **stack, char *tokens, unsigned int count)
{
	instruction_t commands[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{NULL, NULL}
	};

	int run = 0;

	while(run < 8)
	{
		if (strcmp(commands[run].opcode, tokens) == 0)
		{
			commands[run].f(stack, count);
			return;
		}
		run++;
	}
	if (strlen(tokens) != 0 && tokens[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", count, tokens);
		exit(EXIT_FAILURE);
	}
}
