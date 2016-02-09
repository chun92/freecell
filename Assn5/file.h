/***
 *
 * file.h
 *
 * Make a file I/O format of cards.
 *
 */

#ifndef FILE_H
#define FILE_H

#include "card.h"

void getFileFormat(Card* card, char* res); // size of res is fixed at 4.
void getCardFromFileFormat(Card* card, char* res);

#endif