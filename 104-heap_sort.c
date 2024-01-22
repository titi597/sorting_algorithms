#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * swap - Swaps two elements in an array.
 * @a: Pointer to the first element.
 * @b: Pointer to the second element.
 */
void swap(int *a, int *b)
{
	int temp = *a;

	*a = *b;
	*b = temp;
}

/**
 * heapify - Adjusts the heap to satisfy the heap property.
 * @array: The array to be heapified.
 * @size: The size of the array.
 * @i: The index of the current root.
 * @max: The maximum index in the heap.
 */
void heapify(int *array, size_t size, size_t i, size_t max)
{
	size_t largest = i;
	size_t left = 2 * i + 1;
	size_t right = 2 * i + 2;

	if (left < max && array[left] > array[largest])
		largest = left;
	if (right < max && array[right] > array[largest])
		largest = right;
	if (largest != i)
	{
		swap(&array[i], &array[largest]);
		print_array(array, size);
		heapify(array, size, largest, max);
	}
}

/**
 * heap_sort - Sorts an array of integers in ascending order
 *             using the Heap sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
	int i;

	if (array == NULL || size < 2)
		return;
	/* Build the heap (rearrange array) */
	for (i = size / 2 - 1; i >= 0; i--)
		heapify(array, size, i, size);
	/* One by one extract elements from the heap */
	for (i = size - 1; i > 0; i--)
	{
		swap(&array[0], &array[i]);
		print_array(array, size);
		heapify(array, size, 0, i);
	}
}
