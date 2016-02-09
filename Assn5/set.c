#include "set.h"
#include "file.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUF_SIZE 100

void generateSetting(int argc, char *argv[], Stack** line) {
	FILE* input;
	int seed;
	if (argc != 3) {
		printf("Invalid command line argument\n");
		exit(0);
	}

	if(strcmp(argv[1], "file") == 0) {
		input = fopen(argv[2], "r");
		if(!input) {
			printf("File doesn't exist\n");
			exit(0);
		}

		generateInputSetting(input, line);
		fclose(input);
	} else if(strcmp(argv[1], "random") == 0) {
		seed = sscanf("%d", argv[2]);
		generateRandomSetting(seed, line);
	} else {
		printf("Invalid command line argument\n");
		exit(0);
	}
}

void generateInputSetting(FILE* input, Stack** line) {
	char buf[MAX_BUF_SIZE];
	char in[7][4];
	int temp;
	int count = 0;
	int i;
	while(fgets(buf, MAX_BUF_SIZE, input) != NULL) {
		count++;
		if(count <= 4) {
			sscanf(buf, "%d%s%s%s%s%s%s%s", &temp, in[0], in[1], in[2], in[3], in[4], in[5], in[6]);
			for(i = 0; i < 7; ++i) {
				Card* card = (Card*)malloc(sizeof(Card));
				card->next = NULL;
				getCardFromFileFormat(card, in[i]);
				pushCardStack(line[temp-1], card);
			}
		}
		else {
			sscanf(buf, "%d%s%s%s%s%s%s", &temp, in[0], in[1], in[2], in[3], in[4], in[5]);
			for(i = 0; i < 6; ++i) {
				Card* card = (Card*)malloc(sizeof(Card));
				card->next = NULL;
				getCardFromFileFormat(card, in[i]);
				pushCardStack(line[temp-1], card);
			}
		}
		
	}

	if(feof(input)) 
		return;
	else 
		perror("file input error");
}

void generateRandomSetting(int seed, Stack** line) {
	return;
}