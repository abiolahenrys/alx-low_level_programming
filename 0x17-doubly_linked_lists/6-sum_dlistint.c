#include "lists.h"

/**
 * sum_dlistint - Sums up the data in a doubly linked list.
 * @head: List beginning
 *
 * Return: Sum of items in the linked list.
 */
int sum_dlistint(dlistint_t *head)
{
	if (!head)
		return (0);

	return (head->n + sum_dlistint(head->next));
}
