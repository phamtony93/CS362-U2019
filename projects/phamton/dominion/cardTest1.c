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
	//Test proper number of supply cards initialized for 2 players 
	if (G.supplyCount[curse] == 10) {
		printf("Passed Test 1.1 \n");
	}
	else {
		printf("Failed Test 1.1 \n");
	};

	if (G.supplyCount[estate] == 8) {
		printf("Passed Test 1.2 \n");
	}
	else {
		printf("Failed Test 1.2 \n");
	};

	int numCopper = 60 - (7 * numPlayer);
	if (G.supplyCount[copper] == numCopper) {
		printf("Passed Test 1.3 \n");
	}
	else {
		printf("Failed Test 1.3 \n");
	};

	if (G.supplyCount[gardens] == 8) {
		printf("Passed Test 1.4 \n");
	}
	else {
		printf("Failed Test 1.4 \n");
	};

	//Test 2
	//Check player decks have been properly initialized with copper and estate
	int numEstateInitialized = 0;
	int numCopperInitialized = 0;

	for (i = 0; i < MAX_DECK; i ++) {
		if (G.deck[0][i] == estate) {
			numEstateInitialized++;
		}
		else if (G.deck[0][i] == copper) {
			numCopperInitialized++;
		};
	};

	if (numEstateInitialized == 3) {
		printf("Passed Test 2.1 \n");
	}
	else {
		printf("Failed Test 2.1 \n");
	};

	if (numCopperInitialized == 7) {
		printf("Passed Test 2.2 \n");
	}
	else {
		printf("Failed Test 2.2 \n");
	};
	
	//Test 3
	//Test first turn initialized
	if (G.outpostPlayed == 0) {
		printf("Passed Test 3.1 \n");
	}
	else {
		printf("Failed Test 3.1 \n");
	};

	if (G.phase == 0) {
		printf("Passed Test 3.2 \n");
	}
	else {
		printf("Failed Test 3.2 \n");
	};

	if (G.numActions == 1) {
		printf("Passed Test 3.3 \n");
	}
	else {
		printf("Failed Test 3.3 \n");
	};

	if (G.numBuys == 1) {
		printf("Passed Test 3.4 \n");
	}
	else {
		printf("Failed Test 3.4 \n");
	};

	if (G.playedCardCount == 0) {
		printf("Passed Test 3.5 \n");
	}
	else {
		printf("Failed Test 3.5 \n");
	};

	if (G.whoseTurn == 0) {
		printf("Passed Test 3.6 \n");
	}
	else {
		printf("Failed Test 3.6	 \n");
	};

	system("pause");
}