#include "sort.h"

void _swap(int *, int *, int *, size_t);
void buildMaxHeap(int *, size_t, size_t, size_t);

/**
 * heap_sort - sorts an array in ascending order,
 * implementing the sift-down heap sort algorithm.
 * @array: array to be sort
 * @size: size of the array
 *
 * Return: nothing
 */
void heap_sort(int *array, size_t size)
{
	int start, end;

	if (array == NULL || size <= 1)
		return;

	for (start = size / 2 - 1; start >= 0; start--)
		buildMaxHeap(array, start, size, size);
	for (end = size - 1; end >= 0; end--)
	{
		_swap(array, &array[0], &array[end], size);
		buildMaxHeap(array, 0, end, size);
	}
}
/**
 * buildMaxHeap - builds binary heap from bottom up
 * @array: array of integers
 * @start: index of the first element
 * @end: index of the last element
 * @size: size of the array
 *
 * Return: nothing
 */
void buildMaxHeap(int *array, size_t start, size_t end, size_t size)
{
	int biggest = start;
	int left = 2 * start + 1;
	int right = 2 * start + 2;

	if (left < (int)end && array[left] > array[biggest])
		biggest = left;
	if (right < (int)end && array[right] > array[biggest])
		biggest = right;
	if (biggest != (int)start)
	{
		_swap(array, &array[start], &array[biggest], size);
		buildMaxHeap(array, biggest, end, size);
	}
}

/**
 * _swap - Swaps two int values
 * @array: the integer array to sort
 * @left: address of first value
 * @right: address of second value
 * @size: the size of the array
 *
 * Return: Void
 */
void _swap(int *array, int *left, int *right, size_t size)
{
	int temp;

	if (left != right)
	{
		temp = *left;
		*left = *right;
		*right = temp;
		print_array(array, size);
	}
}
