#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i, j, results;
	int seed = 1000;
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

	//Initialize players 5th card to be minion
	for (i = 0; i < numPlayer; i++) {
		G.hand[i][4] = minion;
	};

	//Test 1. Choice 1 selected. Action should be incremented and coins +2
	int oldCoinCount = G.coins;
	int oldActionCount = G.numActions;
	j = minionEffect(1, 0, 0, &G, 4);

	if (j == 0) {
		printf("Test 1.1 passed \n");
	}
	else {
		printf("Test 1.1 failed \n");
	};

	if (G.numActions == oldActionCount + 1) {
		printf("Test 1.2 passed \n");
	}
	else {
		printf("Test 1.2 failed \n");
	};

	//Test 2. Coins is +2 after option 1 selected
	if (G.coins == oldCoinCount + 2) {
		printf("Test 2.1 passed \n");
	}
	else {
		printf("Test 2.1 failed \n");
	};

	//Test 3. Hand discarded and redraw 4 cards
	G.hand[0][4] = minion;
	int oldDiscardCount = G.discardCount;
	int oldHandCount = G.handCount;
	j = minionEffect(0, 1, 0, &G, 4);
	if (G.discardCount == oldDiscardCount + oldHandCount) {
		printf("Test 3.1 passed \n");
	}
	else {
		printf("Test 3.1 failed \n");
	};

	if (G.handCount == 4) {
		printf("Test 3.2 passed \n");
	}
	else {
		printf("Test 3.2 failed \n");
	};

	system("pause");
}