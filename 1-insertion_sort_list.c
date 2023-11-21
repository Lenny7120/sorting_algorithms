#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 * in ascending order using the Insertion sort algorithm
 * @list: The list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev, *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		prev = current->prev;
		next = current->next;
		while (prev != NULL && current->n < prev->n)
		{
			/* Swap the nodes */
			prev->next = next;
			if (next != NULL)
				next->prev = prev;
			current->prev = prev->prev;
			current->next = prev;
			if (prev->prev != NULL)
				prev->prev->next = current;
			else
				*list = current;
			prev->prev = current;
			/* Print the list after each swap */
			print_list(*list);
			/* Update the pointers */
			prev = current->prev;
			next = current->next;
		}
		current = next;
	}
}
