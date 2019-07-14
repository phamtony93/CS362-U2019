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
	//Test player 1 chosen as winner
	for (i = 0; i < numPlayer; i++) {
		for (j = 0; j < MAX_HAND; j++) {
			G.hand[i][j] = copper;
		};
	};

	for (i = 0; i < numPlayer; i++) {
		for (j = 0; j < MAX_DECK; j++) {
			G.deck[i][j] = copper;
		};
	};

	for (i = 0; i < numPlayer; i++) {
		for (j = 0; j < MAX_DECK; j++) {
			G.discard[i][j] = copper;
		};
	};
	
	G.hand[1][0] = estate;
	int players[MAX_PLAYERS];
	getWinners(players, &G);

	if (players[1] == 1) {
		printf("Passed Test 1 \n");
	}
	else {
		printf("Failed Test 1 \n");
	};

	//Test 2
	//Test that ties show both as winners
	G.hand[0][0] = estate;
	players[MAX_PLAYERS];
	getWinners(players, &G);

	if (players[0] == players[1]) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};



	system("pause");
}