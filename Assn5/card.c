#include "card.h"

Color getCardColor(Card* card) {
	switch (card->suit) {
	case SPADE: return BLACK;
	case DIAMOND: return RED;
	case HEART: return RED;
	case CLUB: return BLACK;
	}
}

Card* getNextCard(Card* card) {
	return card->next;
}