#ifndef SORT_H
#define SORT_H

/* Standard library headers */
#include <stdio.h>
#include <stdlib.h>


/**
* struct listint_s - Doubly linked list node
*
* @n: Integer stored in the node
* @prev: Pointer to the previous element of the list
* @next: Pointer to the next element of the list
*/
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

/* Custom functions */
void print_array(const int *, size_t);
void print_list(const listint_t *);
void bubble_sort(int *, size_t);
void insertion_sort_list(listint_t **);
void selection_sort(int *, size_t);
void quick_sort(int *, size_t);
int lomuto_partition(int *, size_t, int, int);
void lomuto_sort(int *, size_t, int, int);
void shell_sort(int *, size_t);
void cocktail_sort_list(listint_t **);
void swap_nodes(listint_t **, listint_t *, listint_t *);
void merge_sort(int *, size_t);
void merge_sort_recursive(int *, size_t);
void merge(int *, size_t, size_t);

#endif
