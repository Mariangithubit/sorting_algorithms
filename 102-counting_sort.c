#include "sort.h"

/**
 * counting_sort - sorts an array of integers using the Counting sort algorithm
 * @array: array to be counting
 * @size: size of array
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
	int n, j;
	int *count_array, *x;
	size_t i;

	if (!array || size < 2)
		return;

	n = array[0];
	for (i = 0; i < size; i++)
	{
		if (array[i] > n)
			n = array[i];
	}
	count_array = calloc((n + 1), sizeof(int));
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]++;
	}
	for (j = 1; j < n; j++)
	{
		count_array[j + 1] += count_array[j];
	}
	print_array(count_array, n + 1);
	x = malloc(sizeof(int) * size);
	for (i = 0; i < size; i++)
	{
		count_array[array[i]]--;
		x[count_array[array[i]]] = array[i];
	}
	for (i = 0; i < size; i++)
	{
		array[i] = x[i];
	}
	free(x);
	free(count_array);
}
