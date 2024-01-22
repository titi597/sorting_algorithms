#include "sort.h"
void quick_sort(int *array, size_t size);
void swap(int *a, int *b);
int lomuto_partition(int *array, size_t size, int left, int right);
void lomuto_sort(int *array, size_t size, int left, int right);
/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Lomuto partition scheme for Quick sort
 * @array: The array to be partitioned
 * @left: Starting index of the partition
 * @right: Ending index of the partition
 * @size: Size of the array
 *
 * Return: Partition index
 */
int lomuto_partition(int *array, size_t size, int left, int right)
{
	int *pivot, i, j;

	pivot = array + right;
	for (i = j = left; j < right; j++)
	{
		if (array[j] < *pivot)
		{
			if (i < j)
			{
				swap(array + j, array + i);
				print_array(array, size);
			}
			i++;
		}
	}

	if (array[i] > *pivot)
	{
		swap(array + i, pivot);
		print_array(array, size);
	}

	return (i);
}

/**
 * lomuto_sort - Recursive function to perform Quick sort on an array
 * @array: The array to be sorted
 * @right: Starting index of the array/partition
 * @left: Ending index of the array/partition
 * @size: Size of the array
 */
void lomuto_sort(int *array, size_t size, int left, int right)
{
	int partition_idx;

	if (right - left > 0)
	{
		partition_idx = lomuto_partition(array, size, left, right);
		lomuto_sort(array, size, left, partition_idx - 1);
		lomuto_sort(array, size, partition_idx + 1, right);
	}
}
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

	lomuto_sort(array, size, 0, size - 1);
}
