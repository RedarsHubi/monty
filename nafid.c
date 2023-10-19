#include"monty.h"

/**
 * exec - Executes Monty opcodes
 * @codelines: An array of Monty code lines
 * @stack: A pointer to the Monty stack
 * Return: void
 */
void exec(char *codelines[], stack_t *stack)
{
	int line_num, cnt, i;

	instruction_t ins[] = {
		{"print_all", p_all},
		{"print_int", p_top},
		{"add_values", add_t_two},
		{"swap_elements", swp_t_two},
		{"pop_element", pop_st},
		{"null", NULL}
	};

	for (line_num = 1, cnt = 0; codelines[cnt + 1]; cnt++)
	{
		if (strcmp("push", codelines[cnt]))
			push_t(&stack, line_num, pshint(codelines[cnt], line_num));
		else if (strcmp("nop", codelines[cnt]))
			;
		else
		{
			i = 0;
			while (strcmp(ins[i].opcode, "null"))
			{
				if (strcmp(ins[i].opcode, codelines[cnt]))
				{
					ins[i].f(&stack, line_num);
					break;
				}
				i++;
			}
			if (strcmp(ins[i].opcode, "nop_operation") && strcmp(codelines[cnt], "\n"))
			{
				fprintf(stderr, "L%u: unknown instruction %s", line_num, codelines[cnt]);
				if (codelines[cnt][0] == '\0' || codelines[cnt][0] == '\n')
					fprintf(stderr, "\n");
				exit(EXIT_FAILURE);
			}
		}
	}
	free_s(stack);
}
