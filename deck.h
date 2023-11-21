#ifndef DECK_H
#define DECK_H

#include <stddef.h>

/**
 * enum kind_e - Represents the kind of card
 * @SPADE: Spade card
 * @HEART: Heart card
 * @CLUB: Club card
 * @DIAMOND: Diamond card
 */
typedef enum kind_e
{
	SPADE,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;

deck_node_t *init_deck(const card_t cards[52]);
void print_deck(const deck_node_t *deck);
void sort_deck(deck_node_t **deck);

#endif /* DECK_H */
