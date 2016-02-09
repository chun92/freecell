#include "file.h"
#include <assert.h>

void getCardFromFileFormat(Card* card, char* res) {
	switch(res[0]) {
	case 'S': 
		card->suit = SPADE;
		break;
	case 'D':
		card->suit = DIAMOND;
		break;
	case 'H':
		card->suit = HEART;
		break;
	case 'C':
		card->suit = CLUB;
		break;
	default:
		assert(0 && "Wrong file format");
	}

	switch(res[1]) {
	case 'A':
		card->number = 1;
		break;
	case '2':
		card->number = 2;
		break;
	case '3':
		card->number = 3;
		break;
	case '4':
		card->number = 4;
		break;
	case '5':
		card->number = 5;
		break;
	case '6':
		card->number = 6;
		break;
	case '7':
		card->number = 7;
		break;
	case '8':
		card->number = 8;
		break;
	case '9':
		card->number = 9;
		break;
	case '1':
		if(res[2] == '0')
			card->number = 10;
		else
			assert(0 && "Wrong file format");
		break;
	case 'J':
		card->number = 11;
		break;
	case 'Q':
		card->number = 12;
		break;
	case 'K':
		card->number = 13;
		break;
	}
	return;
}

void getFileFormat(Card* card, char* res) {
	switch (card->suit){
	case SPADE: 
		res[0] = 'S';
		break;
	case DIAMOND: 
		res[0] = 'D';
		break;
	case HEART: 
		res[0] = 'H';
		break;
	case CLUB:
		res[0] = 'C';
		break;
	}

	switch (card->number) {
	case 1:
		res[1] = 'A';
		res[2] = '\0';
		break;
	case 2:
		res[1] = '2';
		res[2] = '\0';
		break;
	case 3:
		res[1] = '3';
		res[2] = '\0';
		break;
	case 4:
		res[1] = '4';
		res[2] = '\0';
		break;
	case 5:
		res[1] = '5';
		res[2] = '\0';
		break;
	case 6:
		res[1] = '6';
		res[2] = '\0';
		break;
	case 7:
		res[1] = '7';
		res[2] = '\0';
		break;
	case 8:
		res[1] = '8';
		res[2] = '\0';
		break;
	case 9:
		res[1] = '9';
		res[2] = '\0';
		break;
	case 10:
		res[1] = '1';
		res[2] = '0';
		res[3] = '\0';
		break;
	case 11:
		res[1] = 'J';
		res[2] = '\0';
		break;
	case 12:
		res[1] = 'Q';
		res[2] = '\0';
		break;
	case 13:
		res[1] = 'K';
		res[2] = '\0';
		break;
	default:
		assert(0 && "wrong card number");
	}
	return;
}