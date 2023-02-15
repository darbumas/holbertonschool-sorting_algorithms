#include "sort.h"

/**
 * setGapSize - sets the Knuth Sequence gap for given arr[size]
 * @size: given array size
 * Return: gap size
 */
size_t setGapSize(size_t size)
{
	size_t gap = 1;

	while (gap < size)
		gap = gap * 3 + 1;
	return ((gap - 1) / 3);
}

/**
 * shell_sort - sorts an array using the Shell sort algo
 * @array: array of ints to sort
 * @size: size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;
	int temp;

	if (!array)
		return;


	for (gap = setGapSize(size); gap; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i += 1)
		{
			temp = array[i];
			for (j = i; (j > gap - 1) && (array[j - gap] > temp); j -= gap)
				array[j] = array[j - gap];
			array[j] = temp;
		}
		print_array(array, size);
	}
}
