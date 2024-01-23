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
 * bitonic_merge - Merges two bitonic sequences in a given direction.
 * @array: The array to be sorted.
 * @low: Starting index of the sequence.
 * @div: the sequence of elements array.
 * @dir: Number of elements in the sequence.
 * @apt: Direction of sorting (1 for ascending, 0 for descending).
 */
void bitonic_merge(int *array, size_t low, size_t div, size_t dir, char apt)
{
	size_t i, upt = dir / 2;
	
	if (dir > 1)
	{
		for (i = div; i < div + upt; i++)
		{
			if ((apt == UP && array[i] > array[i + upt]) ||
			    (apt == DOWN && array[i] < array[i + upt]))
				swap(array + i, array + i + upt);
		}
		bitonic_merge(array, low, div, upt, apt);
		bitonic_merge(array, low, div + upt, upt, apt);
	}
}

/**
 * bitonic_rec - Recursively sorts a bitonic sequence in a given direction.
 * @array: The array to be sorted.
 * @dir: Starting index of the sequence.
 * @sq: Number of elements in the sequence.
 * @size: the size of elements.
 * @div: Direction of sorting (1 for ascending, 0 for descending).
 */
void bitonic_rec(int *array, size_t size, size_t dir, size_t sq, char div)
{
	size_t uptr = sq / 2;
	char *stir = (div == UP) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, stir);
		print_array(array + dir, sq);

		bitonic_rec(array, size, dir, uptr, UP);
		bitonic_rec(array, size, dir + uptr, uptr, DOWN);
		bitonic_merge(array, size, dir, sq, div);

		printf("Result [%lu/%lu] (%s):\n", sq, size, stir);
		print_array(array + dir, sq);
	}
}

/**
 * bitonic_sort - Sorts an array of integers in ascending order
 * using the Bitonic sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_rec(array, size, 0, size, UP);
}
