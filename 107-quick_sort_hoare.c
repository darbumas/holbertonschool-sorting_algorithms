#include "sort.h"

/**
 * swap - swap two integers.
 * @a: pointer to the first integer to swap.
 * @b: pointer to the second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * partition_sort - Order a subset of an array of integers
 * according to the hoare partition scheme.
 * @array: given array of integers.
 * @size: size of the array.
 * @left: starting index of the subset to order.
 * @right: ending index of the subset to order.
 * Return: The final partition index.
 */
int partition_sort(int *array, size_t size, int left, int right)
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
 * recursive_qsort - implementthe quicksort algorithm through recursion.
 * @array: array of integers to sort.
 * @size: size of the array.
 * @left: starting index of the array partition to order.
 * @right: ending index of the array partition to order.
 */
void recursive_qsort(int *array, size_t size, int left, int right)
{
	int p;

	if (right - left > 0)
	{
		p = partition_sort(array, size, left, right);
		recursive_qsort(array, size, left, p - 1);
		recursive_qsort(array, size, p, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	recursive_qsort(array, size, 0, size - 1);
}
