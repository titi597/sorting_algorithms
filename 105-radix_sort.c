#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Returns the maximum value in an array.
 * @array: The array to find the maximum value in.
 * @size: The size of the array.
 * Return: The maximum value.
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - Sorts an array based on a significant place value.
 * @array: The array to be sorted.
 * @size: The size of the array.
 * @ex: The current significant place value (1, 10, 100, ...).
 * @div: buffer to store the sorted.
 */
void countSort(int *array, size_t size, int ex, int *div)
{
	int count[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	size_t i;

	for (i = 0; i < size; i++)
		count[(array[i] / ex) % 10] += 1;
	for (i = 0; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		div[count[(array[i] / ex) % 10] - 1] = array[i];
		count[(array[i] / ex) % 10] -= 1;
	}
	for (i = 0; i < size; i++)
		array[i] = div[i];
}

/**
 * radix_sort - Sorts an array of integers in ascending order
 *               using the Radix sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void radix_sort(int *array, size_t size)
{
	int max, ex, *div;

	if (array == NULL || size < 2)
		return;

	div = malloc(sizeof(int) * size);
	if (div == NULL)
		return;

	max = get_max(array, size);
	for (ex = 1; max / ex > 0; ex *= 10)
	{
		countSort(array, size, ex, div);
		print_array(array, size);
	}

	free(div);
}
