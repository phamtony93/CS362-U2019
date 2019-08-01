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


	//Test 1
	//initialize game
	r = initializeGame(numPlayer, k, seed, &G);

	//initialize player 0 to have 0 estate in hand
	for (i = 0; i < MAX_HAND; i++) {
		G.hand[0][i] = copper;
	};

	//Count number of estate in discard pile
	int numBuysOld = G.numBuys;
	int numEstate = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstate++;
		};
	};

	//Choice1 = true
	j = baronEffect(1, 0, &G);
	
	//Count number of estate in discard pile after baron effect
	//Test 1
	int numEstateNew = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstateNew++;
		};
	};

	//Test 1.1 Test 
	printf("Test 1.1: Test that player has 0 estate and tried to discard an estate. Gain an estate instead. \n");
	if (numEstate + 1 == numEstateNew) {
		printf("Passed Test 1.1 \n");
	}
	else {
		printf("Failed Test 1.1 \n");
	};

	printf("Test 1.2 Test that numBuys +1 \n");
	if (G.numBuys == numBuysOld + 1) {
		printf("Passed Test 1.2 \n");
	}
	else {
		printf("Failed Test 1.2 \n");
	};

	//Test 2
	//initialize player 0 to have 1 estate in hand
	for (i = 0; i < MAX_HAND; i++) {
		if (i == 4) {
			G.hand[0][i] = estate;
		}
		else {
			G.hand[0][i] = copper;
		};
	};

	//Count number of estate in discard pile
	numBuysOld = G.numBuys;
	numEstate = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstate++;
		};
	};

	//Choice1 = true
	j = baronEffect(1, 0, &G);

	//Count number of estate in discard pile after baron effect
	numEstateNew = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstateNew++;
		};
	};

	printf("Test 2: Test that player 1 has an estate in hand and is able to discard estate. \n");
	if (numEstate + 1 == numEstateNew) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};

	//Test 3
	//Count number of estate in discard pile
	numBuysOld = G.numBuys;
	numEstate = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstate++;
		};
	};

	//Choice1 = false
	j = baronEffect(0, 0, &G);

	//Count number of estate in discard pile after baron effect
	numEstateNew = 0;
	for (i = 0; i < MAX_DECK; i++) {
		if (G.discard[0][i] == estate) {
			numEstateNew++;
		};
	};

	printf("Test 3: Test that player 0 is able to gain an estate. \n");
	if (numEstate + 1 == numEstateNew) {
		printf("Passed Test 3 \n");
	}
	else {
		printf("Failed Test 3 \n");
	};


	//system("pause");
}