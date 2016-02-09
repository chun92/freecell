/***
 *
 * set.h
 *
 * Make a setting for freecell game.
 * It has two mode, first one is to read file input, 
 * second one is to generate random setting.
 *
 */

#ifndef SET_H
#define SET_H

#include <stdio.h>
#include "board.h"

void generateSetting(int argc, char *argv[], Stack** line);
void generateInputSetting(FILE* input, Stack** line);
void generateRandomSetting(int seed, Stack** line);
void verifySetting(Stack** line);

#endif