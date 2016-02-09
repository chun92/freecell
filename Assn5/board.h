/***
 *
 * board.h
 *
 * It contains the definition of lineStack, Homecell, Freecell
 * which are the components of freecell game
 */

#ifndef BOARD_H
#define BOARD_H

#include "card.h"

typedef struct Stack {
	Card* head;
	Card* tail;
	int numOfCard;
} Stack;

void initializeStack(Stack* line);
Card* getCardStack(Stack* line);
void pushCardStack(Stack* line, Card* card);
int popCardStack(Stack* line, Card* card);
Card* getNthCard(Stack* line, int num);

#endif