#include "console.h"
#include <stdio.h>
#include <assert.h>

void printConsoleFormat(Card* card) {
	printf("[");
	switch (card->suit){
	case SPADE: 
		printf("¢¼");
		break;
	case DIAMOND: 
		printf("¡Þ");
		break;
	case HEART: 
		printf("¢½");
		break;
	case CLUB:
		printf("¢À");
		break;
	}

	switch (card->number) {
	case 1:
		printf(" A");
		break;
	case 2:
		printf(" 2");
		break;
	case 3:
		printf(" 3");
		break;
	case 4:
		printf(" 4");
		break;
	case 5:
		printf(" 5");
		break;
	case 6:
		printf(" 6");
		break;
	case 7:
		printf(" 7");
		break;
	case 8:
		printf(" 8");
		break;
	case 9:
		printf(" 9");
		break;
	case 10:
		printf("10");
		break;
	case 11:
		printf(" J");
		break;
	case 12:
		printf(" Q");
		break;
	case 13:
		printf(" K");
		break;
	default:
		assert(0 && "wrong card number");
	}
	printf("]");
	return;
}