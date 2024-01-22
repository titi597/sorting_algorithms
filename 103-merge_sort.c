#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge_env - Merges two subarrays into a single sorted array.
 * @merge: The original array containing two sorted subarrays.
 * @div: pointer to an array.
 * @front: first array
 * @aptr: second array.
 * @back: third array.
 */
void merge_env(int *merge, int *div, size_t front, size_t aptr, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(merge + front, aptr - front);

	printf("[right]: ");
	print_array(merge + aptr, back - aptr);

	for (i = front, j = aptr; i < aptr && j < back; k++)
		div[k] = (merge[i] < merge[j]) ? merge[i++] : merge[j++];
	for (; i < aptr; i++)
		div[k++] = merge[i];
	for (; j < back; j++)
		div[k++] = merge[j];
	for (i = front, k = 0; i < back; i++)
		merge[i] = div[k++];

	printf("[Done]: ");
	print_array(merge + front, back - front);
}
/**
 * merge_recursive - Implement the merge sort algorithm.
 * @merge: A subarray of an array.
 * @div: A buffer to store.
 * @front: The front index.
 * @back: The back index.
 */
void merge_recursive(int *merge, int *div, size_t front, size_t back)
{
	size_t aptr;

	if (back - front > 1)
	{
		aptr = front + (back - front) / 2;
		merge_recursive(merge, div, front, aptr);
		merge_recursive(merge, div, aptr, back);
		merge_env(merge, div, front, aptr, back);
	}
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	int *div;

	if (array == NULL || size < 2)
		return;

	div = malloc(sizeof(int) * size);
	if (div == NULL)
		return;

	merge_recursive(array, div, 0, size);

	free(div);
}
