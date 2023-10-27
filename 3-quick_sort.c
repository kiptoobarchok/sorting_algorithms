#include "sort.h"

/**
 * Swap_Int - function to swap 2 int
 * @x: int one
 * @y: int two
*/

void Swap_Int(int *x, int *y)
{
	int temp;

	temp = *x;
	*x = *y;
	*y = temp;

}

/**
 * partition - partition an array using a pivot
 * @arr: array
 * @lower: int
 * @upper: int
 * @n: size of array
 * Return: index of pivot
*/

int partition(int *arr, int lower, int upper, size_t n)
{
	int pivot = arr[upper];
	int a = lower - 1, b;

	for (b = lower; b <= upper; b++)
	{
		if (arr[b] <= pivot)
		{
			a++;
			if (a != b)
			{
				Swap_Int(&arr[a], &arr[b]);
				print_array(arr, n);
			}
		}
	}
	return (a);
}

/**
 * lomuto - sorting an array
 * @arr: array to be sorted
 * @lower: lowest array val
 * @upper: highest value of array
 * @n: size of array
*/

void lomuto(int *arr, int lower, int upper, size_t n)
{
	int i;

	if (lower < upper)
	{
		i = partition(arr, lower, upper, n);
		lomuto(arr, lower, i - 1, n);
		lomuto(arr, i + 1, upper, n);
	}
}

/**
 * quick_sort- function to sort using lomuto partition
 * @array: array to be sorted
 * @size: size of array
*/

void quick_sort(int *array, size_t size)
{
	lomuto(array, 0, size - 1, size);
}
