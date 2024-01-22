#include "sort.h"

/**
 * quick_sort - Sorts an array of integers in ascending order using the
 *              Quick sort algorithm with Lomuto partition scheme.
 * @array: The array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	_quick_sort(array, 0, size - 1, size);
}

/**
 * _quick_sort - Recursive function to perform Quick sort on an array
 * @array: The array to be sorted
 * @low: Starting index of the array/partition
 * @high: Ending index of the array/partition
 * @size: Size of the array
 */
void _quick_sort(int *array, ssize_t low, ssize_t high, size_t size)
{
	if (low < high)
	{
		ssize_t partition_idx = lomuto_partition(array, low, high, size);

		_quick_sort(array, low, partition_idx - 1, size);
		_quick_sort(array, partition_idx + 1, high, size);
	}
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Partition index
 */
ssize_t lomuto_partition(int *array, ssize_t low, ssize_t high, size_t size)
{
	int pivot = array[high];
	ssize_t i = low - 1;
	ssize_t j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;

			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] != array[high])
	{
		swap(&array[i + 1], &array[high]);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
