#include "monty.h"
stack_t **global_head = NULL;

/**
 * main - Main function.
 * @argc: The argument count.
 * @argv: The argument vector.
 *
 * Description: This is the main function of the Monty project.
 * Return: The success or error.
 **/
int main(int argc, char *argv[])
{
	ssize_t reading;
	size_t bufsize;
	FILE *fd;
	unsigned int count = 0;
	char *tokens, *line = NULL;
	stack_t *head = NULL;

	global_head = &head;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	fd = fopen(argv[1], "r");

	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while ((reading = getline(&line, &bufsize, fd)) != -1)
	{
		tokens = strtok(line, LIMITERS);
		count++;
		if (tokens)
		{
			selector(&head, tokens, count);
		}
	}
	if (line)
		free(line);
	fclose(fd);
	atexit(freesea);
	exit(EXIT_SUCCESS);
}

/**
 * freesea - This function frees memory.
 *
 * Return: Nothing
 */
void freesea(void)
{
	stack_t *freesea = NULL, *aux = NULL;

	freesea = *global_head;
	while (freesea)
		aux = freesea->next, free(freesea), freesea = aux;
}
