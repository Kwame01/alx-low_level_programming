#include "lists.h"

/**
 * sum_listint - Computes the sum of all elements of a linked list.
 * @head: Pointer to the head node of the list.
 *
 * Return: The sum of all elements of the list.
 */

int sum_listint(listint_t *head)
{
    listint_t *temp;
    int sum = 0;

    if (head == NULL)
        return (0);

    temp = head;

    while (temp != NULL)
    {
        sum += temp->n;
        temp = temp->next;
    }

    return (sum);
}
