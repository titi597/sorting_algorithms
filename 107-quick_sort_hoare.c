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
	int tmp;

	tmp= *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partition - Partitions the array using the Hoare scheme.
 * @array: The array to be partitioned.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 * Return: The index of the pivot after partitioning.
 */
int hoare_partition(int *array, size_t size, int left, int right)
{
	int pivot, above, below;

	pivot = array[right];
	for (above = left - 1, below = right + 1; above < below;)
	{
		do {
			above++;
		} while (array[above] < pivot);
		do {
			below--;
		} while (array[below] > pivot);

		if (above < below)
		{
			swap(array + above, array + below);
			print_array(array, size);
		}
	}

	return (above);
}
/**
 * quick_sort_hoare_recursive - Recursively sorts a partition of the array.
 * @array: The array to be sorted.
 * @low: The starting index of the partition.
 * @high: The ending index of the partition.
 * @size: The size of the array.
 */
void quick_sort_hoare_recursive(int *array, int low, int high, size_t size)
{
	int ptr;

	if (high - low > 0)
	{
		ptr = hoare_partition(array, size, low, high);
		quick_sort_hoare_recursive(array, size, low, ptr - 1);
		quick_sort_hoare_recursive(array, size, ptr, high);
	}
}
/**
 * quick_sort_hoare - Sorts an array of integers in ascending order using Quick sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_hoare_recursive(array, size, 0, size - 1);
}
