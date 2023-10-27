#include "sort.h"

/**
 *swap_int - function to swap 2 elements
 *@x: element 1 node
 *@y: element 2 node
 *@head: head of list
*/

void swap_int(listint_t *x, listint_t *y, listint_t **head)
{
	listint_t *temp1 = NULL, *temp2 = NULL;

	if (x == NULL || y == NULL)
	{
		return;
	}

	temp1 = x->prev;
	temp2 = y->next;

	if (temp1)
	{
		temp1->next = y;
	}
	if (temp2)
	{
		temp2->prev = x;
	}

	x->next = temp2;
	x->prev = y;
	y->next = x;
	y->prev = temp1;
	if (temp1 == NULL)
		*head = y;
}


/**
 * insertion_sort_list- function to sort integers using insertion sort
 * @list: doubly linked list of integers
 *
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *head, *prev;
	int val;

	if (list == NULL || (*list)->next == NULL || (*list) == NULL)
	{
		return;
	}
	head = *list;

	while (head)
	{
		prev = head->prev;
						val = head->n;

		while (prev && prev->n > val)
		{
			swap_int(prev, head, list);
			print_list(*list);
			prev = head->prev;

		}
		head = head->next;
	}

}
