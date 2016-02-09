#include <stdio.h>
#include "console.h"
#include "print.h"

void print(Stack** line, Stack** freecell, Stack** homecell) {
	int i;
	int j;
	Card* card;

	printf("[Homecell]\n");
	for(i = 0; i < 4; ++i) {
		printf("%d", i+1);
		card = homecell[i]->head;
		for(j = 0; j < homecell[i]->numOfCard; ++j, card = card->next) {
			printf(" ");
			printConsoleFormat(card);
		}
		printf("\n");
	}

	printf("[Freecell]");
	for(i = 0; i < 4; ++i) {
		card = freecell[i]->head;
		if(card) {
			printf(" ");
			printConsoleFormat(card);
		} else {
			printf(" [ - ]");
		}
	}
	printf("\n");

	printf("[Line Stack]\n");
	for(i = 0; i < 8; ++i) {
		printf("%d", i+1);
		card = line[i]->head;
		for(j = 0; j < line[i]->numOfCard; ++j, card = card->next) {
			printf(" ");
			printConsoleFormat(card);
		}
		printf("\n");
	}
	return;
}