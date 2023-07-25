#include "sort.h"

/**
 * _swap - exchange 2 values
 * @array: array of swaped values
 * @i: first value
 * @j: second value
 * Return: void
 */
void _swap(int *array, int i, int j)
{
	int temp;

	if (array[i] != array[j])
	{
		temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}

/**
 * shell_sort - sorts an array of integers using the Knuth sequence
 * @array: array of sorted values
 * @size: size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j;
	size_t n = 0;

	if (size < 2)
		return;

	while (n <= size / 3)
		n = n * 3 + 1;

	while (n >= 1)
	{
		for (i = n; i < size; i++)
			for (j = i; j >= n && array[j] < array[j - n]; j -= n)
				_swap(array, j, j - n);

		n /= 3;
		print_array(array, size);
	}
}
