#include "sort.h"

/**
 * _swap - swap two noodes
 * @node: the node to swap
 * @list: doubly linked list
 * Return: void
 */
void _swap(listint_t **node, listint_t **list)
{
	listint_t *temp1, *temp2;
	listint_t *temp = *node;

	if (!(*node)->prev)
		*list = (*node)->next;

	temp = temp2 = *node;
	temp1 = temp->next;

	temp->next = temp1->next;
	temp2 = temp->prev;
	temp->prev = temp1;
	temp1->next = temp;
	temp1->prev = temp2;

	if (temp1->prev)
		temp1->prev->next = temp1;

	if (temp->next)
		temp->next->prev = temp;

	*node = temp1;
}

/**
 * cocktail_sort_list - sorts a doubly linked list of integer
 * using the Cocktail shaker sort algorithm
 * @list: list to be sorted
 * Return: void
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *head, *x;
	int i = 0, n = -1, j = -1;

	if (!list || !(*list) || (!((*list)->prev) && !((*list)->next)))
		return;

	head = *list;
	while (j >= n)
	{
		n++;
		while (head->next && i != j)
		{
			if (head->n > head->next->n)
			{
				x = head;
				_swap(&x, list);
				print_list(*list);
				head = x;
			}
			i++;
			head = head->next;
		}
		if (n == 0)
			j = i;

		j--;
		while (head->prev && i >= n)
		{
			if (head->n < head->prev->n)
			{
				x = head->prev;
				_swap(&x, list);
				print_list(*list);
				head = x->next;
			}
			i--;
			head = head->prev;
		}
	}
}
