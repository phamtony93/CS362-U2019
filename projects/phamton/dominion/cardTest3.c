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
	//Test that player 0 turn ended. Hand is discarded and whose turn is updated
	for (i = 0; i < 5; i++) {
		G.hand[0][i] = copper;
	};
	G.handCount[0] = 5;

	int lastPlayer = G.whoseTurn;
	endTurn(&G);

	//Test that player 0 hand is discarded and handCount is 0
	int testHandLastPlayer = 0;

	for (i = 0; i < 5; i++) {
		(testHandLastPlayer += G.hand[0][i]);
	};

	if (testHandLastPlayer == -5) {
		printf("Passed Test 1.2 \n");
	}
	else {
		printf("Failed Test 1.2 \n");
	};

	if (lastPlayer + 1 == G.whoseTurn) {
		printf("Passed Test 1.2 \n");
	}
	else {
		printf("Failed Test 1.2 \n");
	};

	//Test 2
	//Check whose turn is properly looped to beginning if currentPlayer is 
	//last in array and draws 5 cards
	G.whoseTurn = numPlayer - 1;
	endTurn(&G);

	if (G.whoseTurn == 0) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};

	if (G.handCount[G.whoseTurn] == 5) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};

	system("pause");
}