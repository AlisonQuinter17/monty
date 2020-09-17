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
	stack_t *newnode = NULL;
	char *n = strtok(NULL, LIMITERS);

	newnode = malloc(sizeof(stack_t));

	if (!newnode)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	newnode->n = atoi(n);
	newnode->prev = NULL;

	if (*stack)
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
		*stack = newnode;
	}
	else
	{
		*stack = newnode;
		newnode->next = NULL;
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
	stack_t *list = *stack;
	(void) count;

	while (list)
	{
		printf("%d\n", list->n);
		list = list->next;
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
	stack_t *list = *stack;
	(void) count;

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
	stack_t *list = *stack;

	if (!*stack)
	{
		fprintf(stderr, "L%u: usage: push integer\n", count);
		exit(EXIT_FAILURE);
	}

	list = (*stack)->next;
	free(*stack);
	*stack = list;
}

/**
 * nop - This function doesn’t do anything.
 * @stack: Double pointer to the head of the Stack.
 * @count: Number of the line.
 *
 * Return: Nothing.
 **/
void nop(stack_t **stack, unsigned int count)
{
	(void) stack;
	(void) count;
}
