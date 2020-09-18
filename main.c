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
	atexit(freex);
	exit(EXIT_SUCCESS);
}
/*
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	size_t len;
	ssize_t read_line;
	unsigned int line_num = 0;
	char *command, *line = NULL;
	FILE *fd;
	int l = 0;

	global_head = &head;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	fd = fopen(argv[1], "r");
	if (!fd)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while ((read_line = getline(&line, &len, fd)) != -1)
	{
		command = strtok(line, LIMITERS);
		line_num++;

		if (command)
		        selector(&head, command, line_num);
	}
	if (line)
		free(line);
	fclose(fd);
        atexit(freex);
	exit(EXIT_SUCCESS);
}*/

/**
 * freex - global frees memory
 * Return: void
 */
void freex(void)
{
	stack_t *freex = NULL, *aux = NULL;

	freex = *global_head;
	while (freex)
		aux = freex->next, free(freex), freex = aux;
}
