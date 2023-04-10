#include "lists.h"

/**
 * print_listint_safe - Prints a listint_t linked list
 * @head: Pointer to the head of the linked list
 *
 * Return: The number of nodes in the linked list
 */
size_t print_listint_safe(const listint_t *head)
{
    const listint_t *tmp = head;
    size_t count = 0;

    while (tmp)
    {
        count++;
        printf("[%p] %d\n", (void *) tmp, tmp->n);
        tmp = tmp->next;

        /* Check for a loop */
        if (tmp >= head)
        {
            printf("-> [%p] %d\n", (void *) tmp, tmp->n);
            exit(98);
        }
    }

    return (count);
}
