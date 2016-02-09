#include "checkWin.h"
#include <stdlib.h>

int checkWin(Stack** homecell) {
	int i;
	for(i = 0; i < 4; ++i) {
		if(homecell[i]->numOfCard != 13) 
			return 0;
	}
	return 1;
}