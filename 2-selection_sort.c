#include "sort.h"



/**
 * find_min - function to find minimum in array
 * @arr: array
 * @idx: index
 * @n: size of array
 * Return: index of min
*/

int find_min(int *arr, int idx, size_t n)
{
	int i, min, index_min;

	min = arr[idx];
	index_min = idx;

	for (i = idx; i < (int)n; i++)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			index_min = i;
		}
	}

	if (index_min == idx)
	{
		return (-1);
	}

	return (index_min);
}




/**
 * selection_sort- funct to sort array of int using the Selection sort
 * @array: array of int
 * @size: size of array
*/

void selection_sort(int *array, size_t size)
{
	int i, min, temp;

	for (i  = 0; i < (int)size; i++)
	{
		min = find_min(array, i, size);

		if (min != -1)
		{
			temp = array[i];
			array[i] = array[min];
			array[min] = temp;
			print_array(array, size);
		}
	}
}
