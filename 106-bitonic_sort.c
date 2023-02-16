#include "sort.h"

#define UP 0
#define DOWN 1

/**
 * swap - swaps two integers.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * recursive_merge - recursively sorts an array of integers with
 * a constant value for sequence.
 * @array: given array of integers.
 * @size: size of the array.
 * @start: starting index of the sequence in array to sort.
 * @seq: size of the sequence to sort.
 * @dir: The direction to sort in.
 */
void recursive_merge(int *array, size_t size, size_t start, size_t seq,
		char dir)
{
	size_t i, jump = seq / 2;

	if (seq > 1)
	{
		for (i = start; i < start + jump; i++)
		{
			if ((dir == UP && array[i] > array[i + jump]) ||
			    (dir == DOWN && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		}
		recursive_merge(array, size, start, jump, dir);
		recursive_merge(array, size, start + jump, jump, dir);
	}
}

/**
 * bitonic_sorter - converts an array of integers into a bitonic sequence.
 * @array: given array of integers.
 * @size: size of the array.
 * @start: start index of a block of the building bitonic sequence.
 * @seq: size of a block of the building bitonic sequence.
 * @dir: The direction to sort the bitonic sequence block in.
 */
void bitonic_sorter(int *array, size_t size, size_t start,
			size_t seq, char dir)
{
	size_t mid = seq / 2;
	char *str = (dir == UP) ? "UP" : "DOWN";

	if (seq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);

		bitonic_sorter(array, size, start, mid, UP);
		bitonic_sorter(array, size, start + mid, mid, DOWN);
		recursive_merge(array, size, start, seq, dir);

		printf("Result [%lu/%lu] (%s):\n", seq, size, str);
		print_array(array + start, seq);
	}
}

/**
 * bitonic_sort - sorts an array of integers in ascending
 * order using the bitonic sort algorithm.
 * @array: given array of integers to sort.
 * @size: size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	bitonic_sorter(array, size, 0, size, UP);
}
