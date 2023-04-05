#ifndef LISTS_H
#define LISTS_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Singly linked list node
 * @n: Integer data
 * @next: Pointer to the next node
 *
 * Description: Singly linked list node structure
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function prototypes */
size_t print_listint(const listint_t *h);
listint_t *add_nodeint_end(listint_t **head, const int n);
void free_listint2(listint_t **head);
listint_t *reverse_listint(listint_t **head);

#endif /* LISTS_H */

