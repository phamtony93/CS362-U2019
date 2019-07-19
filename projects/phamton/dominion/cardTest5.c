#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i, j, l;
	int seed = 10;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel
					, smithy, village, baron, great_hall };
	struct gameState G;
	int maxHandCount = 5;


	//initialize game
	r = initializeGame(numPlayer, k, seed, &G);

	//Test 1
	//handCount is incremented
	int oldHandCount = G.handCount[0];
	drawCard(0, &G);
	if (oldHandCount + 1 == G.handCount[0]) {
		printf("Passed Test 1 \n");
	}
	else {
		printf("Failed Test 1 \n");
	};

	//Test 2
	//If no cards remaining in deck, move discard into deck
	for (i = 0; i < MAX_DECK; i++) {
		G.discard[0][i] = G.deck[0][i];
		G.deck[0][i] = -1;
	};
	G.deckCount[0] = 0;
	G.discardCount[0] = MAX_DECK;
	drawCard(0, &G);

	if (G.deckCount[0] > 0) {
		printf("Passed Test 2.1 \n");
	}
	else {
		printf("Failed Test 2.1 \n");
	};

	if (G.discardCount[0] == 0) {
		printf("Passed Test 2.2 \n");
	}
	else {
		printf("Failed Test 2.2 \n");
	};

	//system("pause");
}