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
	int x;

	if (!*stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	x = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = x;
}

/**
 * add - This function adds the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void add(stack_t **stack, unsigned int count)
{
	if (!*stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * sub - This function subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void sub(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;

}
