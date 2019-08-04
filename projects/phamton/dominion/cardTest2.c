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

	//G.deck[0][9] = 9;
	//Test 1

	for (i = 0; i < MAX_DECK; i++) {
		G.deck[0][i] = i;
	};

	printf("Test 1: Shuffle player 0 cards \n");
	int oldDeck[MAX_DECK];
	for (i = 0; i < MAX_DECK; i++) {
			oldDeck[i] = G.deck[0][i];
	};

	shuffle(0, &G);

	int countSameCard = 0;

	for (i = 0; i < MAX_DECK; i++) {
		if (oldDeck[i] == G.deck[0][i]) {
			countSameCard++;
		};
	};

	if (countSameCard == MAX_DECK) {
		printf("Failed Test	1 \n");
	}
	else {
		printf("Passed Test 1 \n");
	};



	


	system("pause");
}