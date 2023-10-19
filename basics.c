#include "monty.h"

/**
 * add_t_two - adds the top two elements of the stack.
 * @stack: pointer to head of the stack
 * @line_number: line number in the file
 * Return: void
 */
void add_t_two(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *next_element;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current && current->next)
	{
		next_element = current->next;
		next_element->n += current->n;
		free(current);
		*stack = next_element;
	}
}

/**
 * p_top - Prints the value at the top of the stack.
 * @stack: pointer to head of the stack
 * @line_number: line number in the file
 * Return: void
 */
void p_top(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

/**
 * push_t - Pushes an element onto the stack
 * @stack: pointer to head of the stack
 * @line_number: line number in the file
 * @value: value to push
 * Return: address of the new element
 */
void push_t(stack_t **stack, unsigned int line_number, int value)
{
	stack_t *new_element, *current = *stack;

	if (stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_element = malloc(sizeof(stack_t));
	if (new_element == NULL)
		exit(EXIT_FAILURE);

	new_element->prev = NULL;
	new_element->n = value;
	new_element->next = *stack;

	if (*stack)
		current->prev = new_element;

	*stack = new_element;
}

/**
 * pop_st - Removes the top element from the stack
 * @stack: pointer to head of the stack
 * @line_number: line number in the file
 * Return: void
 */
void pop_st(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current)
	{
		*stack = current->next;
		free(current);
	}
}

/**
 * swp_t_two - Swaps the top two elements of the stack
 * @stack: pointer to head of the stack
 * @line_number: line number in the file
 * Return: void
 */
void swp_t_two(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack, *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (current && current->next)
	{
		temp = current->next;
		if (temp->next)
			temp->next->prev = current;
		current->next = temp->next;
		temp->prev = NULL;
		temp->next = current;
		current->prev = temp;
		*stack = temp;
	}
}
