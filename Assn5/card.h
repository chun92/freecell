/***
 *
 * card.h
 *
 * It contains the definition of card struct
 *
 */

#ifndef CARD_H
#define CARD_H

typedef enum Suit {
	SPADE = 0,
	DIAMOND = 1,
	HEART = 2,
	CLUB = 3
} Suit;

typedef enum Color {
	BLACK = 0,
	RED = 1
} Color;

typedef struct Card {
	int number;
	Suit suit;
	struct Card *next;
} Card;

Color getCardColor(Card* card);
Card* getNextCard(Card* card);

#endif