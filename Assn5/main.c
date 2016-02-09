/***
 *
 * Assn5 Sample Project
 *
 * Written by Hyunjoon
 *
 **/


#include "card.h"
#include "board.h"
#include "set.h"
#include "print.h"
#include "move.h"
#include "log.h"
#include "checkWin.h"

#include <stdio.h>
#include <stdlib.h>

#define LINESTACK_NUM 8
#define FREECELL_NUM 4
#define HOMECELL_NUM 4

int main(int argc, char *argv[]) {
	Stack* lineStack[LINESTACK_NUM];
	Stack* freecell[FREECELL_NUM];
	Stack* homecell[HOMECELL_NUM];
	CardInfo moving;
	CardInfo res;
	int targetRes;
	int locationRes;
	int isMovingSuccessful = 0;
	FILE* log = fopen("log.txt", "w");
	
	// initilize the game board
	int i;
	for(i = 0; i < LINESTACK_NUM; ++i) {
		lineStack[i] = (Stack*)malloc(sizeof(Stack));
		initializeStack(lineStack[i]);
	}
	for(i = 0; i < FREECELL_NUM; ++i) {
		freecell[i] = (Stack*)malloc(sizeof(Stack));
		initializeStack(freecell[i]);
	}
	for(i = 0; i < HOMECELL_NUM; ++i) {
		homecell[i] = (Stack*)malloc(sizeof(Stack));
		initializeStack(homecell[i]);
	}

	generateSetting(argc, argv, lineStack);
	logStart(log);

	while(1) {
		print(lineStack, freecell, homecell);
		
		if(checkWin(homecell)) {
			printf("You Win\n");
			logWin(log);
			break;
		}

		isMovingSuccessful = 0;
		while(!isMovingSuccessful) {
			targetRes = selectTarget(lineStack, freecell, homecell, &moving);
			if (targetRes == -1) {
				printf("Error: Illegal card selection\n");
				continue;
			}
			locationRes = selectLocation(lineStack, freecell, homecell, &moving, &res);
			if (locationRes == -1) {
				printf("Error: Illegal Moving\n");
				continue;
			} else if (locationRes == 0) {
				continue;
			}
			isMovingSuccessful = 1;
			printf("Moving is successful\n");
			logMove(log, moving.target, moving.index, moving.num, moving.card, res.target, res.index);
		}
	}

	fclose(log);
	return 0;
}