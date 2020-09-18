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
		free(stack);
		exit(EXIT_FAILURE);
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
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
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", count);
		free(stack);
		exit(EXIT_FAILURE);
	}
	sum = (*stack)->n;
	sum += (*stack)->next->n;
	pop(stack, count);
	(*stack)->n = sum;
}

/**
 * sub - subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void sub(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n -= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _div - This function subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void _div(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n /= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * mul - This function subtracts the top element of the stack from
 * the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void mul(stack_t **stack, unsigned int count)
{
	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", count);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	(*stack) = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
