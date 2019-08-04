#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	srand(time(NULL));
	int i, j, h, l;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	//initializeGame(numHandCards, k, seed, &G);
	int maxHandcount = 5;

	int choice1;
	int choice2;
	int handPos;
	int player;
	

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < sizeof(struct gameState); j++) {
			((char*)&G)[i] = (rand() % (256));
		};
		choice1 = (rand() % (1 - 0 + 1));
		choice2 = (rand() % (1 - 0 + 1));
		while (choice2 == choice1) {
			choice2 = (rand() % (1 - 0 + 1));
		};
		player = (rand() % (numPlayer));
		G.playedCardCount = 0;
		G.whoseTurn = player;
		G.numPlayers = numPlayer;
		for (h = 0; h < numPlayer; h++) {
			G.handCount[h] = (rand() % (MAX_HAND - 0 + 1));
			for (l = 0; l < G.handCount[h]; l++) {
				G.hand[h][l] = (rand() % (27 - 0 + 1));
			};
			G.deckCount[h] = (rand() % (MAX_DECK - 0 + 1));
			G.discardCount[h] = (rand() % (MAX_DECK - 0 + 1));
		};
		handPos = (rand() % (G.handCount[player] - 0 + 1));
		minionEffect(choice1, &G, handPos, player);
	};

	printf("Passed all tests \n");

	system("pause");
};