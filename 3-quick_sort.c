#include "sort.h"

/**
 * swap_items - swap two items
 * @array : modified array
 * @l: left item
 * @r: right item
 */
void swap_items(int *array, size_t l, size_t r)
{
	int temp;

	if (array != NULL)
	{
		temp = array[l];
		array[l] = array[r];
		array[r] = temp;
	}
}

/**
 * quick_sort_lomuto - sort sub array
 * @array: Array containing sub_array
 * @low: The first position in the sub array
 * @high: The last position in the sub array
 * @size : The size of an array
 */
void quick_sort_lomuto(int *array, size_t low, size_t high, size_t size)
{
	int pivot;
	size_t n, i;

	if ((low >= high) || (array == NULL))
		return;
	pivot = array[high];
	n = low;
	for (i = low; i < high; i++)
	{
		if (array[i] <= pivot)
		{
			if (n != i)
			{
				swap_items(array, n, i);
				print_array(array, size);
			}
			n++;
		}
	}
	if (n != high)
	{
		swap_items(array, n, high);
		print_array(array, size);
	}
	if (n - low > 1)
		quick_sort_lomuto(array, low, n - 1, size);
	if (high - n > 1)
		quick_sort_lomuto(array, n + 1, high, size);
}

/**
 * quick_sort - sorts an array of integers in ascending order
 * @array: sorted array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	if (array != NULL)
	{
		quick_sort_lomuto(array, 0, size - 1, size);
	}
}
