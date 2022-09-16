#include "sort.h"

/**
 * merge_aux - Sorts the subarray (auxiliary array)
 * @arr: Array of int to sort
 * @aux: Subarray
 * @low: Lowest index of arr
 * @mid: Middle index of arr
 * @hi: Highest index of arr
 */
void merge_aux(int *arr, int *aux, size_t low, size_t mid, size_t hi)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(arr + low, mid - low);

	printf("[right]: ");
	print_array(arr + mid, hi - mid);

	for (i = low, j = mid; i < mid && j < hi; k++)
		aux[k] = (arr[i] < arr[j]) ? arr[i++] : arr[j++];
	for (; i < mid; i++)
		aux[k++] = arr[i];
	for (; j < hi; j++)
		aux[k++] = arr[j];
	for (i = low, k = 0; i < hi; i++)
		arr[i] = aux[k++];

	printf("[Done]: ");
	print_array(arr + low, hi - low);
}

/**
 * merge - Implements the top-down merge sort algorithm
 * @arr: Array of int to sort
 * @aux: subarray of int
 * @low: low index of arr
 * @hi: high index of arr
 */
void merge(int *arr, int *aux, size_t low, size_t hi)
{
	size_t mid;

	if (hi - low > 1)
	{
		mid = low + (hi - low) / 2;
		merge(arr, aux, low, mid);
		merge(arr, aux, mid, hi);
		merge_aux(arr, aux, low, mid, hi);
	}
}

/**
 * merge_sort - Sorts an array of ints in ascending order
 * @array: Array of int to sort
 * @size: size of arr
 */
void merge_sort(int *array, size_t size)
{
	int *aux;

	if (array == NULL || size < 2)
		return;
	aux = malloc(sizeof(int) * size);
	if (aux == NULL)
		return;
	merge(array, aux, 0, size);
	free(aux);
}
