#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * get_max - Getting the maximum value of integers.
 * @array: pointer an array of integers.
 * @size: the array.
 *
 * Return: The max integer in the array.
 */
int get_max(int *array, int size)
{
	int max, i;

	for (max = array[0], i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order.
 * @array: pointer to an array of integers.
 * @size: an array.
 */
void counting_sort(int *array, size_t size)
{
	int *counting, *sort, max, i;

	if (array == NULL || size < 2)
		return;
	sort = malloc(sizeof(int) * size);
	if (sort == NULL)
		return;
	max = get_max(array, size);
	counting = malloc(sizeof(int) * (max + 1));
	if (counting == NULL)
	{
		free(sort);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		counting[i] = 0;
	for (i = 0; i < (int)size; i++)
		counting[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		counting[i] += counting[i - 1];
	print_array(counting, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sort[counting[array[i]] - 1] = array[i];
		counting[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sort[i];
	free(sort);
	free(counting);
}
