#include "sort.h"
#include <stdio.h>

/**
 * bubble_sort - sorts array of integers in ascending order
 * @array: array of integers
 * @size: size of array
 * Return: void
 */
void bubble_sort(int *array, size_t size)
{
	size_t i;
	int temp, sorted;

	if (!array || size == 0)
		return;

	do {
		sorted = 1;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				sorted = 0;
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
			}
		}
	} while (sorted == 0);
}
