#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * using the "Radix sort" algorithm
 * @array: array of integers
 * @size: size of the array
 * Return: Always nothing.
 */
void radix_sort(int *array, size_t size)
{
	int max, i, p;
	int *dump;
	unsigned int j;

	max = 0;
	if (!array || size < 2)
		return;
	for (j = 0; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}
	for (p = 1; max / p > 0; p *= 10)
	{
		int count[10] = {0};

		dump = malloc(sizeof(int) * size);
		if (dump == NULL)
			return;
		for (i = 0; i < (int) size; i++)
			count[(array[i] / p) % 10]++;
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
		for (i = size - 1; i >= 0; i--)
		{
			dump[count[(array[i] / p) % 10] - 1] = array[i];
			count[(array[i] / p) % 10]--;
		}
		for (i = 0; i < (int) size; i++)
			array[i] = dump[i];
		free(dump);
		print_array(array, size);
	}
}


