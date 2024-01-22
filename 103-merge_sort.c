#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * merge - Merges two subarrays into a single sorted array.
 * @array: The original array containing two sorted subarrays.
 * @left: The left subarray.
 * @left_size: The size of the left subarray.
 * @right: The right subarray.
 * @right_size: The size of the right subarray.
 */
void merge(int *array, int *left, size_t left_size, int *right, size_t right_size)
{
	size_t i = 0, j = 0, k = 0;
	int *temp = malloc(sizeof(int) * (left_size + right_size));

	if (temp == NULL)
		return;
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(right, right_size);

	while (i < left_size && j < right_size)
	{
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];
	}
	while (i < left_size)
		temp[k++] = left[i++];
	while (j < right_size)
		temp[k++] = right[j++];
	for (i = 0; i < (left_size + right_size); i++)
		array[i] = temp[i];
	printf("[Done]: ");
	print_array(array, left_size + right_size);
	free(temp);
}
/**
 * merge_sort - Sorts an array of integers in ascending order
 *              using the Merge sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void merge_sort(int *array, size_t size)
{
	if (size > 1)
	{
		size_t middle = size / 2;
		int *left = array;
		int *right = array + middle;

		printf("Merging...\n");
		printf("[left]: ");
		print_array(left, middle);
		printf("[right]: ");
		print_array(right, size - middle);

		merge_sort(left, middle);
		merge_sort(right, size - middle);

		merge(array, left, middle, right, size - middle);
	}
}
