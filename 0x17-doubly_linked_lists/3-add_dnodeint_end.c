#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a doubly linked list
 *
 * @head: Pointer to list beginning
 * @n: Value of the new node
 *
 * Return: Address of new node or NULL on failure.
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *current = *head;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (!current)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}

	while (current->next)
		current = current->next;

	current->next = node;
	node->prev = current;

	return (node);
}
