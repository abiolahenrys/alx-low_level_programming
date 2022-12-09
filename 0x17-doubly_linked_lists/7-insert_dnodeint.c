#include "lists.h"

/**
 * insert_dnodeint_at_index - Inserts a node at the specified index.
 *
 * @h: Pointer to list beginning.
 * @idx: Index at which to insert new node.
 * @n: Value, n of the new node to be inserted at index, idx.
 *
 * Return: Address of node inserted or NULL on failure.
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *node, *current;
	size_t list_len = dlistint_len(*h);

	/* Return NULL if index specified not in list */
	if (idx > list_len)
		return (NULL);

	/* Add node as normal if empty node or index is the end */
	if (!(*h) || idx == list_len)
		return (add_dnodeint_end(h, n));

	/* Create new node */
	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;

	/* Get existing node at index */
	current = get_dnodeint_at_index(*h, idx);

	if (idx) /* If index is non-zero */
	{
		current->prev->next = node;
		node->prev = current->prev;
	} else   /* If index is zero */
	{
		*h = node;
		node->prev = NULL;
	}
	/* Base case, i.e. whether index is zero or not */
	node->next = current;
	current->prev = node;

	return (node);
}

/**
 * dlistint_len - Counts the number of elements in a doubly linked list
 * @h: List beginning.
 *
 * Return: Integer representing the length of the linked list.
 */
size_t dlistint_len(const dlistint_t *h)
{
	if (!h)
		return (0);

	return (1 + dlistint_len(h->next));
}

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
