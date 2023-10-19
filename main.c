#include "monty.h"

/**
 * main - maincfction
 * @argc: The number of command-line arguments
 * @argv: An array of command-line argument strings
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char *argv[])
{
	stack_t *stack = NULL;
	static char *lines[1000] = {NULL};
	int cnt = 0;
	FILE *file_stream;
	size_t buff = 1000;

	if (argc != 2)
	{
		fprintf(stderr, "Usage: MontyInterpreter file\n");
		exit(EXIT_FAILURE);
	}
	file_stream = fopen(argv[1], "r");
	if (file_stream == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	for (cnt = 0; getline(&(lines[cnt]), &buff, file_stream) > 0; cnt++)
		;
	exec(lines, stack);
	free_l(lines);
	fclose(file_stream);
	return (0);
}
