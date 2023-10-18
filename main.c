#define _XOPEN_SOURCE 700

#include "monty.h"

/**
 * struct var_s - struct to contain the main variables of the Monty interpreter
 * @queue: flag to determine if in stack vs queue mode
 * @stack_len: length of the stack
 */
typedef struct var_s
{
	int queue;
	size_t stack_len;
} var_t;

/**
 * main - Monty bytecode interpreter
 * @argc: number of arguments passed
 * @argv: array of argument strings
 *
 * Return: EXIT_SUCCESS on success or EXIT_FAILURE on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	unsigned int line_number = 0;
	FILE *fs = NULL;
	char *lineptr = NULL, *op = NULL;
	size_t n = 0;

	var.queue = 0;
	var.stack_len = 0;
	if (argc != 2)
	{
		dprintf(STDOUT_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	fs = fopen(argv[1], "r");
	if (fs == NULL)
	{
		dprintf(STDOUT_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&lineptr, &n, fs) != -1)
	{
		line_number++;
		op = strtok(lineptr, "\n\t\r ");
		if (op != NULL && op[0] != '#')
		{
			get_op(op, &stack, line_number);
		}
	}
	exit(EXIT_SUCCESS);
}
