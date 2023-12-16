#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *                       order using the insertion sort algorithm
 * @list: A pointer to a pointer to the head of listint_t doubly linked list
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *temp;

	if (!list || !(*list)->next)
		return;

	current = (*list)->next;

	/* Traverse from left to right */
	while (current)
	{
		/* Update temp pointer */
		temp = current;

		/* Traverse from right to left to sort */
		while (temp->prev && temp->n < temp->prev->n)
		{
			/* Update next node prev pointer */
			if (temp->next)
				temp->next->prev = temp->prev;

			/* Swap previous node and temp node */
			temp->prev->next = temp->next;
			temp->next = temp->prev;

			/* Update prev pointer to previous node for next iteration */
			temp->prev = temp->prev->prev;

			/* Update previous node's next pointer */
			if (temp->prev)
				temp->prev->next = temp;
			else /* Update head of list */
				*list = temp;

			/* Update the next node to point back to temp */
			temp->next->prev = temp;

			print_list(*list);
		}
		current = current->next;
	}
}
