#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - Inserts a new node at a given position.
 *
 * @head: Pointer to a pointer to the beginning of a list.
 * @idx: Index of the list where the new node should be added.
 * @n: Data of the new node to be added.
 *
 * Return: Address of the new node, or NULL if it failed.
 * If it is not possible to add the new node at index idx,
 * do not add the new node and return NULL.
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *temp;
	unsigned int i;

	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = n;
	if (idx == 0)
	{
		new->next = *head;
		*head = new;
		return (new);
	}

	temp = *head;
	for (i = 0; i < idx - 1 && temp != NULL; i++)
		temp = temp->next;

	if (temp == NULL)
	{
		free(new);
		return (NULL);
	}

	new->next = temp->next;
	temp->next = new;

	return (new);
}

