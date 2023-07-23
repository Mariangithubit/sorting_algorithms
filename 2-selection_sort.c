#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 * @array: array of integer
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int temp;
	size_t i, step, min_idx;

	for (step = 0; step < size - 1; step++)
	{
		min_idx = step;
		for (i = step + 1; i < size; i++)
		{
			if (array[i] < array[min_idx])
				min_idx = i;
		}
		if (min_idx != step)
		{
			temp = array[step];
			array[step] = array[min_idx];
			array[min_idx] = temp;
			print_array(array, size);
		}
	}
}
