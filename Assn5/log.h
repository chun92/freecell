/***
 *
 * log.h
 *
 * logging
 *
 */
#ifndef LOG_H
#define LOG_H

#include "card.h"
#include <stdio.h>

void logStart(FILE* fp);
void logWin(FILE* fp);
void logLoss(FILE* fp);
void logMove(FILE* fp, int from, int fromIndex, int num, Card* card, int to, int toIndex);

#endif