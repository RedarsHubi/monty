#include "monty.h"

/**
 * m_pall - print all values
 * @stack: double pointer to head of stack
 * @line: executed line
 *
 * Return: void
 */
void push_all(stack_t **stack, unsigned int line)
{
	stack_t *head;

	(void)(line);

	head = *stack;
	while (head != NULL)
	{
		printf("%d\n", head->n);
		head = head->next;
		if (head == *stack)
		{
			return;
		}
	}
}
