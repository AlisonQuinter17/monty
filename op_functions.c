#include "monty.h"

/**
 * swap - This function swaps the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void swap(stack_t **stack, unsigned int count)
{
	int tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}

/**
 * mod - computes the rest of the division of the
 * second top element of the stack by the top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void mod(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n %= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * pchar -  prints the char at the top of the stack,
 * followed by a new line.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void pchar(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
			count);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", (*stack)->n);
}
