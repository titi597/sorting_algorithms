#include <stdlib.h>
#include <string.h>
#include "deck.h"

/**
 * compare_cards - Compare two card pointers for qsort
 * @a: Pointer to the first card
 * @b: Pointer to the second card
 *
 * Return: Integer less than, equal to, or greater than zero if a is found,
 *         respectively, to be less than, to match, or be greater than b.
 */
int compare_cards(const void *a, const void *b)
{
	const deck_node_t *node_a = *(const deck_node_t **)a;
	const deck_node_t *node_b = *(const deck_node_t **)b;
	char values[] = "A2345678910JQK";
	int value_a = strchr(values, node_a->card->value[0]) - values;
	int value_b = strchr(values, node_b->card->value[0]) - values;

	if (node_a->card->kind != node_b->card->kind)
		return (node_a->card->kind - node_b->card->kind);

	/* Convert card values to numeric values for proper sorting */
	return (value_a - value_b);
}

/**
 * sort_deck - Sorts a deck of cards
 * @deck: Pointer to the head of the deck
 */
void sort_deck(deck_node_t **deck)
{
	size_t i;
	size_t count = 52;
	deck_node_t *current;
	deck_node_t **array;

	if (!deck || !*deck || !(*deck)->next)
		return;
	array = malloc(count * sizeof(deck_node_t *));
	if (!array)
		return;
	current = *deck;
	for (i = 0; i < count; i++)
	{
		array[i] = current;
		current = current->next;
	}
	qsort(array, count, sizeof(deck_node_t *), compare_cards);
	for (i = 0; i < count; i++)
	{
		array[i]->prev = (i == 0) ? NULL : array[i - 1];
		array[i]->next = (i == count - 1) ? NULL : array[i + 1];
	}
	*deck = array[0];
	free(array);
}
