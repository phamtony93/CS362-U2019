#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	int i, j, l;
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


	//Test 1
	printf("Test 1: Call tribute with player next player drawing 2 actions \n");
	G.hand[1][0] = baron;
	G.hand[1][1] = baron;

	int numActionsOld = G.numActions;

	j = tributeEffect(0, 1, &G);

	if (G.numActions == numActionsOld + 2) {
		printf("Passed Test 1.1 \n");
	}
	else {
		printf("Failed Test 1.1 \n");
	};

	//Test 2
	printf("Test 2: Call tribute with player next player drawing 1 action and 1 treasure \n");
	G.hand[1][0] = baron;
	G.hand[1][1] = copper;

	numActionsOld = G.numActions;
	int numCoinsOld = G.coins;

	j = tributeEffect(0, 1, &G);

	if (G.numActions == numActionsOld + 2 && G.coins == numCoinsOld + 2) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};



	system("pause");
}