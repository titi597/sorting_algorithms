#include "sort.h"
/**
 * swap_nodeahead - Swap a node in a listint_t doubly-linked list
 * @list: A pointer to the head.
 * @tail: A pointer to the tail.
 * @head: A pointer to the current swapping node of the cocktail.
 */
void swap_nodeahead(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *aptr_tmp;

	aptr_tmp = (*head)->next;

	if ((*head)->prev != NULL)
		(*head)->prev->next = aptr_tmp;
	else
		*list = aptr_tmp;
	aptr_tmp->prev = (*head)->prev;
	(*head)->next = aptr_tmp->next;
	if (aptr_tmp->next != NULL)
		aptr_tmp->next->prev = *head;
	else
		*tail = *head;
	(*head)->prev = aptr_tmp;
	aptr_tmp->next = *head;
	*head = aptr_tmp;
}
/**
 * swap_nodebehind - Swap a node in a listint_t doubly-linked.
 * @list: A pointer to the head.
 * @tail: A pointer to the tail.
 * @head: A pointer to the current swapping node of the cocktail.
 */
void swap_nodebehind(listint_t **list, listint_t **tail, listint_t **head)
{
	listint_t *aptr_tmp;

	aptr_tmp = (*head)->prev;

	if ((*head)->next != NULL)
		(*head)->next->prev = aptr_tmp;
	else
		*tail = aptr_tmp;
	aptr_tmp->next = (*head)->next;
	(*head)->prev = aptr_tmp->prev;
	if (aptr_tmp->prev != NULL)
		aptr_tmp->prev->next = *head;
	else
		*list = *head;
	(*head)->next = aptr_tmp;
	aptr_tmp->prev = *head;
	*head = aptr_tmp;
}
/**
 * cocktail_sort_list - Sort a listint_t doubly-linked list of integers in
 * ascending order.
 * @list: A pointer to the head.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *div, *head;
	bool shaking = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (div = *list; div->next != NULL;)
		div = div->next;

	while (shaking == false)
	{
		shaking = true;
		for (head = *list; head != div; head = head->next)
		{
			if (head->n > head->next->n)
			{
				swap_nodeahead(list, &div, &head);
				print_list((const listint_t *)*list);
				shaking = false;
			}
		}
		for (head = head->prev; head != *list;
				head = head->prev)
		{
			if (head->n < head->prev->n)
			{
				swap_nodebehind(list, &div, &head);
				print_list((const listint_t *)*list);
				shaking = false;
			}
		}
	}
}
