#include "lists.h"

/**
 * get_dnodeint_at_index - Gets the node at specified index.
 *
 * @head: List beginning.
 * @index: Location of node to get.
 *
 * Return: Node at specified index, else NULL
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	if (index >= dlistint_len(head))
		return (NULL);

	if (index == 0)
		return (head);

	return (get_dnodeint_at_index(head->next, index - 1));
}

/**
 * dlistint_len - Counts the number of elements in a doubly linked list
 * @h: List head
 *
 * Return: Integer representing the length of the linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	if (!h)
		return (0);

	return (1 + dlistint_len(h->next));
}
