#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i, j, results;
	int seed = 1000;
	int numPlayer = 3;
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

	//Initialize players 5th card to be mine
	for (i = 0; i < numPlayer; i++) {
		G.hand[i][4] = mine;
	};

	//Initialize each players 0-2 index cards to be copper, silver and gold
	for (i = 0; i < numPlayer; i++) {
		for (j = 0; j < 3; j++) {
			G.hand[i][j] = (copper + j);
		};
	};
	
	//Loop through players 0-2. Select Copper, Silver, Gold
	printf("Test 1: Loop 3 players sacrificing copper to gain copper, silver, and gold in that order. \n Gold should return error. \n");
	for (i = 0; i < 3; i++) {
		j = mineEffect(0, (copper + i), i, &G, 5);

		switch (copper + i)
		{
		case(copper):
			if (j == 0) {
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("Failed Test 1.%d \n", i + 1);
				break;
			};
		case(silver):
			if (j == 0) {
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("Failed Test 1.%d \n", i + 1);
				break;
			};
		case(gold):
			if (j == -1) {
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("Failed Test 1.%d \n", i + 1);
				break;
			};
		}
	};
	//-----------------------------------------------------------------------

	//Test 2
	//initialize game
	r = initializeGame(numPlayer, k, seed, &G);

	//Initialize players 5th card to be mine
	for (i = 0; i < numPlayer; i++) {
		G.hand[i][4] = mine;
	};

	//Choice1 not a copper, silver or gold 
	printf("Test 2: choice1 to sacrifice is not a copper, silver or gold. -1 should be returned. \n");
	G.hand[0][0] = estate;
	j = mineEffect(0, copper, 0, &G, 4);
	if (j == -1) {
		printf("Passed Test 2\n");
	} 
	else {
		printf("Failed Test 2\n");
	};

	//Test 2
	//initialize game
	r = initializeGame(numPlayer, k, seed, &G);

	//Initialize players 5th card to be mine
	for (i = 0; i < numPlayer; i++) {
		G.hand[i][4] = mine;
	};

	//Choice2 not a copper, silver or gold 
	printf("Test 3: Choice2 to gain is not copper, silver or gold. -1 should be returned. \n");
	j = mineEffect(0, estate, 0, &G, 4);
	if (j == -1) {
		printf("Passed Test 3\n");
	}
	else {
		printf("Failed Test 3\n");
	};

	//system("pause");
}