#include"monty.h"
/**
 * pshint - Converts a string to an integer for the push opcode
 * @list: The content of the file
 * @ln: Line number
 * Return: The converted integer
 */
int pshint(char *list, int ln)
{
	char *opcode = "push";
	int number = 0, sign = 1;

	while (*list)
	{
		if (*opcode == *list)
		{
			opcode++;
			list++;
			if (*opcode == '\0')
			{
				while (*list)
				{
					if (*list == '-' && isdigit(*(list + 1)))
					{
						sign = -1;
						list++;
					}
					else if (isdigit(*list))
					{
						number = number * 10 + (*list - '0');
					}
					else if (*list == ' ')
					{
						list++;
					}
					else
					{
						fprintf(stderr, "L%d: usage: push integer\n", ln);
						exit(EXIT_FAILURE);
					}
					list++;
				}
				return (sign * number);
			}
		}
		else
			list++;
	}
	return (0);
}

#include "monty.h"

/**
 * p_all - Print all values on the stack
 * @stack: Pointer to head of the stack
 * @line_num: Line number in the file
 * Return: Void
 */
void p_all(stack_t **stack, unsigned int line_num)
{
	stack_t *current = *stack;
	(void)line_num;

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

