#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

#define UP 0
#define DOWN 1

/**
 * enum bool - Enumeration of Boolean values.
 * @false: Equals 0.
 * @true: Equals 1.
 */
typedef enum bool
{
	false = 0,
	true
} bool;
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

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **head);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **head);
void counting_sort(int *array, size_t size);
int get_max(int *array, int size);
void merge_sort(int *array, size_t size);
void merge_env(int *merge, int *div, size_t front, size_t aptr, size_t back);
void merge_recursive(int *merge, int *div, size_t front, size_t back);
void heap_sort(int *array, size_t size);
void heapify(int *array, size_t size, size_t i, size_t max);
void radix_sort(int *array, size_t size);
void countSort(int *array, size_t size, int ex, int *div);
void bitonic_merge(int *array, size_t low, size_t div, size_t dir, char apt);
void bitonic_rec(int *array, size_t size, size_t dir, size_t sq, char div);
void bitonic_sort(int *array, size_t size);

#endif /* SORT_H */
