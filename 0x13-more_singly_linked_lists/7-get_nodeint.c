#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of a listint_t linked list.
 * @head: pointer to the head node of the linked list.
 * @index: index of the node to be returned, starting from 0.
 *
 * Return: pointer to the nth node of the linked list,
 *         NULL if the node does not exist.
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int i;
	listint_t *temp;

	temp = head;

	for (i = 0; i < index && temp != NULL; i++)
		temp = temp->next;

	if (i == index && temp != NULL)
		return (temp);
	else
		return (NULL);
}

