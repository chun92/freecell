#include "board.h"
#include <stdlib.h>
#include <assert.h>

void initializeStack(Stack* line) {
	line->head = NULL;
	line->tail = NULL;
	line->numOfCard = 0;
	return;
}

Card* getCardStack(Stack* line) {
	return line->tail;
}

void pushCardStack(Stack* line, Card* card) {
	Card* temp = card;
	if(line->tail != NULL) line->tail->next = card;
	while(temp != NULL) {
		if(!line->head) {
			line->head = temp;
			line->tail = temp;
		} else {
			line->tail = temp;
		}
		temp = temp->next;
		line->numOfCard++;
	}
	return;
}

int popCardStack(Stack* line, Card* card) {
	Card* temp= NULL;
	Card* tempBefore= NULL;
	int i;
	int poppingNum;
	assert(line->numOfCard > 0 && "line stack is empty");
	for(i = 0, temp = line->head; i < line->numOfCard; temp = temp->next, ++i) {
		if(temp == card)
			break;
		tempBefore = temp;
	}
	poppingNum = line->numOfCard - i;
	if(poppingNum == line->numOfCard) {
		line->head = NULL;
		line->tail = NULL;
	} else {
		line->tail = tempBefore;
		tempBefore->next = NULL;
	}
	line->numOfCard = line->numOfCard - poppingNum;
	
	return poppingNum;
}

Card* getNthCard(Stack* line, int num) {
	Card* temp;
	int i;
	if(line->numOfCard < num) return NULL;

	temp = line->head;
	for(i = 0; i < line->numOfCard - num; ++i, temp = temp->next);
	return temp;
}