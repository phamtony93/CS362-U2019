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
	
	//Loop through player 0 cards 0, 1, & 2. Select Copper, Silver, Gold
	for (i = 0; i < 3; i++) {
		j = mineEffect(0, (copper + i), i, &G, 5);

		switch (copper + i)
		{
		case(copper):
			if (j == 0) {
				printf("j = %d - ", j);
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("j = %d - ", j);
				printf("Failed Test 1.%d \n", i + 1);
				break;
			};
		case(silver):
			if (j == 0) {
				printf("j = %d - ", j);
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("j = %d - ", j);
				printf("Failed Test 1.%d \n", i + 1);
				break;
			};
		case(gold):
			if (j == -1) {
				printf("j = %d - ", j);
				printf("Passed Test 1.%d \n", i + 1);
				break;
			}
			else {
				printf("j = %d - ", j);
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
	j = mineEffect(0, estate, 0, &G, 4);
	if (j == -1) {
		printf("Passed Test 3\n");
	}
	else {
		printf("Failed Test 3\n");
	};

	system("pause");
}