#include "sort.h"

/**
 * shift_right - swaps two adjacent nodes in a doubly linked-list
 * in the right direction
 * @head: head of the doubly linked list
 * @tail: tail of the doubly linked list
 * @curr: current swapping node
 */
void shift_right(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->next;

	if ((*curr)->prev != NULL)
		(*curr)->prev->next = temp;
	else
		*head = temp;
	temp->prev = (*curr)->prev;
	(*curr)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *curr;
	else
		*tail = *curr;
	(*curr)->prev = temp;
	temp->next = *curr;
	*curr = temp;
}

/**
 * shift_left - swaps two adjacent nodes in a doubly linked-list
 * in the left direction
 * @head: head of the doubly linked list
 * @tail: tail of the doubly linked list
 * @curr: current swapping node
 */
void shift_left(listint_t **head, listint_t **tail, listint_t **curr)
{
	listint_t *temp = (*curr)->prev;

	if ((*curr)->next != NULL)
		(*curr)->next->prev = temp;
	else
		*tail = temp;
	temp->next = (*curr)->next;
	(*curr)->prev = temp->prev;
	if (temp->prev != NULL)
		temp->prev->next = *curr;
	else
		*head = *curr;
	(*curr)->next = temp;
	temp->prev = *curr;
	*curr = temp;
}

/**
 * cocktail_sort_list - sorts doubly linked list in ascending order
 * using the Cocktail shaker sort
 * @list: pointer to the head of the doubly linked list to sort.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *shaker;
	bool cmp = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (cmp == false)
	{
		cmp = true;
		for (shaker = *list; shaker != tail; shaker = shaker->next)
		{
			if (shaker->n > shaker->next->n)
			{
				shift_right(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				cmp = false;
			}
		}
		for (shaker = shaker->prev; shaker != *list;
				shaker = shaker->prev)
		{
			if (shaker->n < shaker->prev->n)
			{
				shift_left(list, &tail, &shaker);
				print_list((const listint_t *)*list);
				cmp = false;
			}
		}
	}
}
