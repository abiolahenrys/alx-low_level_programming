#include "lists.h"

/**
 * free_dlistint - Recursively frees a doubly linked list.
 * @head: List beginning.
 *
 * Return: Always nothing
 */
void free_dlistint(dlistint_t *head)
{
	if (!(head))
		return;

	if (head->next)
		free_dlistint(head->next);

	free(head);
}
