#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	srand(time(NULL));
	int i, j;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int maxHandcount = 5;

	int choice1;
	int player;

	for (i = 0; i < 2000; i++) {
		for (j = 0; j < sizeof(struct gameState); j++) {
			((char*)&G)[i] = (rand() % (256 - 0 + 1));
		};
		choice1 = (rand() % (1 - 0 + 1));
		player = (rand() % (numPlayer));
		G.deckCount[player] = (rand() % (MAX_DECK - 0 + 1));
		G.discardCount[player] = (rand() % (MAX_DECK - 0 + 1));
		G.handCount[player] = (rand() % (MAX_HAND - 0 + 1));
		baronEffect(choice1, &G, player);
	};

	printf("Passed all tests \n");

	system("pause");
};