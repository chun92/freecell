#include "card.h"
#include "board.h"
#include "move.h"
#include "print.h"
#include "console.h"
#include <stdio.h>
#include <assert.h>
#define fflush(_stm) 

int selectTarget(Stack** line, Stack** freecell, Stack** homecell, CardInfo* cardInfo) {
	// get target
	int i;
	Card* res;
	Card* temp;
	int target;
	int index;
	int num;
	int success = 0;
	printf("Please enter the target (Line stack - 1, Freecell - 2): ");
	scanf("%d", &target);
	fflush(stdin);
	if(target == 1) {
		printf("Please enter the index and a number of cards: ");
		scanf("%d%d", &index, &num);
		fflush(stdin);

		// check the condition of card bunch
		res = getNthCard(line[index-1], num);
		temp = res;
		for(i = 0; i < num-1; ++i) {
			if(getCardColor(temp) == getCardColor(temp->next)) return -1;
			if(temp->number-1 != temp->next->number) return -1;
			temp = temp->next;
		}

		//print out result
		printf("Selected Card:");
		for(temp = res; temp != NULL; temp = temp->next) {
			printf(" ");
			printConsoleFormat(temp);
		}
		printf("\n");

		cardInfo->card = res;
		cardInfo->target =target;
		cardInfo->index = index;
		cardInfo->num = num;
		return 1;
	} else if (target == 2) {
		printf("Please enter the index: ");
		scanf("%d", &index);
		fflush(stdin);
		cardInfo->card = freecell[index-1]->head;

		if(!cardInfo->card) return -1;
		printf("Selected Card:");
		printf(" ");
		printConsoleFormat(cardInfo->card);
		printf("\n");

		cardInfo->target =target;
		cardInfo->index = index;
		cardInfo->num = 1;		
		return 1;
	}

	return 0;
}
int selectLocation(Stack** line, Stack** freecell, Stack** homecell, CardInfo* cardInfo, CardInfo* res) {
	int location, index;
	int emptyTargetLine;
	printf("Please enter the location (Line stack - 1, Freecell - 2, Homecell - 3, Cancel - 4): ");
	scanf("%d", &location);
	fflush(stdin);
	if(location == 4) return 0;

	printf("Please enter the index: ");
	scanf("%d", &index);
	fflush(stdin);
	if (location == 1) {
		if(line[index-1]->numOfCard == 0) 
			emptyTargetLine = 1;
		else
			emptyTargetLine = 0;
		if(getBunch(line, freecell, emptyTargetLine) < cardInfo->num) 
			return -1;

		if(line[index-1]->numOfCard != 0 && getCardColor(cardInfo->card) == getCardColor(line[index-1]->tail)) return -1;
		if(line[index-1]->numOfCard != 0 && cardInfo->card->number != line[index-1]->tail->number-1) return -1;
	} else if (location == 2) {
		if(cardInfo->num > 1) return -1;
		if(freecell[index-1]->numOfCard != 0) return -1;
	} else if (location == 3) {
		if(cardInfo->num > 1) return -1;
		if(homecell[index-1]->numOfCard != 0 && cardInfo->card->suit != homecell[index-1]->tail->suit) return -1;
		if(homecell[index-1]->numOfCard != 0 && cardInfo->card->number-1 != homecell[index-1]->tail->number) return -1;
		if(homecell[index-1]->numOfCard == 0 && cardInfo->card->number != 1) return -1;
	} else { 
		return 0;
	}
	
	switch(cardInfo->target) {
	case 1: 
		popCardStack(line[cardInfo->index-1], cardInfo->card);
		break;
	case 2:
		popCardStack(freecell[cardInfo->index-1], cardInfo->card);
		break;
	default:
		assert(0 && "wrong target");
	}

	switch(location) {
	case 1:
		pushCardStack(line[index-1], cardInfo->card);
		break;
	case 2:
		pushCardStack(freecell[index-1], cardInfo->card);
		break;
	case 3:
		pushCardStack(homecell[index-1], cardInfo->card);
		break;
	default:
		assert(0 && "wrong target");
	}

	res->target = location;
	res->index = index;

	return 1;
}

int getBunch(Stack** line, Stack** freecell, int emptyTargetLine) {
	int emptyFreecell = 0;
	int emptyLine = 0;
	int i;
	for(i = 0; i < 8; ++i) {
		if(line[i]->numOfCard == 0) ++emptyLine;
	}
	for(i = 0; i < 4; ++i) {
		if(freecell[i]->numOfCard == 0) ++emptyFreecell;
	}

	return (emptyFreecell + 1) * (emptyLine - emptyTargetLine + 1);
}