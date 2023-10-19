#include "monty.h"

/**
 * free_s - Frees the singly linked list.
 * @head: Pointer to the head of the list
 * Return: Nothing
 */
void free_s(stack_t *head)
{
	stack_t *node = head;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		node = head;
		head = head->next;
		free(node);
	}
}

/**
 * free_l - Frees the `getline` list.
 * @a: Pointer to an array of strings
 * Return: Nothing
 */
void free_l(char *a[])
{
	int i = 0;

	while (a[i] != NULL)
	{
		free(a[i]);
		i++;
	}
}
