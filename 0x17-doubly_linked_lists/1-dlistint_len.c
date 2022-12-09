#include "lists.h"

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
