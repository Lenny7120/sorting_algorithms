#include <stdio.h>
#include "sort.h"

/**
 * swap_nodes - swaps two nodes in a doubly linked list
 * @list: a pointer to the head of the list
 * @node1: the first node to swap
 * @node2: the second node to swap
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	/* Adjust the pointers of the previous and next nodes */
	if (node1->prev)
		node1->prev->next = node2;
	else
		*list = node2;
	if (node2->next)
		node2->next->prev = node1;

	/* Swap the pointers of the nodes */
	node1->next = node2->next;
	node2->prev = node1->prev;
	node2->next = node1;
	node1->prev = node2;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: a pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	/* Perform the Cocktail shaker sort with alternating directions */
	while (swapped)
	{
		swapped = 0;
		current = *list;

		/* Traverse the list from left to right */
		while (current->next)
		{
			/* Compare and swap adjacent nodes if needed */
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				swapped = 1;
				/* Print the list after each swap */
				print_list(*list);
			}
			else
				current = current->next;
		}

		/* If no swap was done, the list is sorted */
		if (!swapped)
			break;

		swapped = 0;
		current = current->prev;

		/* Traverse the list from right to left */
		while (current->prev)
		{
			/* Compare and swap adjacent nodes if needed */
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				swapped = 1;
				/* Print the list after each swap */
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
