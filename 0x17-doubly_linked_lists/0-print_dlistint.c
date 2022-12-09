#include "lists.h"

/**
 * print_dlistint - Prints all elements of a doubly linked list
 * @h: List head
 *
 * Return: Sie of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	if (!h)
		return (0);

	printf("%d\n", h->n);
	return (1 + print_dlistint(h->next));
}
