#include "file.h"
#include "log.h"

void logStart(FILE* fp) {
	fprintf(fp, "Start\n");
}
void logWin(FILE* fp) {
	fprintf(fp, "Win\n");
}
void logLoss(FILE* fp) {
	fprintf(fp, "Loss\n");
}
void logMove(FILE* fp, int from, int fromIndex, int num, Card* card, int to, int toIndex) {
	int i;
	Card* temp;
	char buf[4];
	if(from == 2) {
		fprintf(fp, "%d %d", from, fromIndex);
		getFileFormat(card, buf);
		fprintf(fp, " %s", buf);
		fprintf(fp, " %d %d\n", to, toIndex);
	} else {
		fprintf(fp, "%d %d %d", from, fromIndex, num);
		temp = card;
		for(i = 0; i < num; ++i) {
			getFileFormat(temp, buf);
			fprintf(fp, " %s", buf);
			temp = temp->next;
		}
		fprintf(fp, " %d %d\n", to, toIndex);
	}
}
