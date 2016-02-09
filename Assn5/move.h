/***
 *
 * move.h
 *
 * Decribe the rule to move the cards.
 *
 */

#ifndef MOVE_H
#define MOVE_H

#include "card.h"

typedef struct CardInfo {
	Card* card;
	int target;
	int index;
	int num;
} CardInfo;

// if return is -1, it means target selecting is wrong. Retry it.
int selectTarget(Stack** line, Stack** freecell, Stack** homecell, CardInfo* cardInfo);

// if return is -1, it means location selecting is wrong.
// if reutnr is 0, it means locating is canceled.
int selectLocation(Stack** line, Stack** freecell, Stack** homecell, CardInfo* cardInfo, CardInfo* res);

int getBunch(Stack** line, Stack** freecell, int emptyTargetLine);

#endif