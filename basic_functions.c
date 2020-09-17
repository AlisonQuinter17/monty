#include "monty.h"

/**
 * push - This function pushes an element to the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void push(stack_t **stack, unsigned int count)
{
	stack_t *new = NULL;
	char *elem = strtok(NULL, LIMITERS);
	int i = 0;

	if (!elem || (!isdigit(*elem) && *elem != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}
	while (elem[i])
	{
		if (!isdigit(elem[i]) && elem[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", count);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	new->n = atoi(elem);
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	else
	{
		*stack = new;
		new->next = NULL;
	}
}

/**
 * pall - This function prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void pall(stack_t **stack, unsigned int count)
{
	/* Pass the value of stack to var so stack is not modified*/
	stack_t *var = *stack;
	/*Unused varible*/
	(void)count;

	while (var)
	{
		printf("%d\n", var->n);
		var = var->next;
	}
}

/**
 * pint - This function prints the value at the top of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void pint(stack_t **stack, unsigned int count)
{
	/* Pass the value of stack to list so stack is not modified*/
	stack_t *list = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", count);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", list->n);
}

/**
 * pop - This function removes the top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void pop(stack_t **stack, unsigned int count)
{
	stack_t *new_nd;
	/* Pass the value of stack to new_nd so stack is not modified*/
	new_nd = *stack;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", count);
		exit(EXIT_FAILURE);
	}
	*stack = new_nd->next;
	free(new_nd);
}

/**
 * nop - This function nop doesn’t do anything.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void nop(stack_t **stack, unsigned int count)
{
	/*Unused varibles*/
	(void) stack;
	(void) count;
}
