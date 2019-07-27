#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
	srand(time(NULL));
	int i, j, h;
	int seed = 1000;
	int numPlayer = 2;
	int maxBonus = 10;
	int p, r, handCount;
	int bonus;
	int k[10] = { adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall };
	struct gameState G;
	int maxHandcount = 5;

	int player;
	int nextPlayer;

	for (i = 0; i < 1000; i++) {
		for (j = 0; j < sizeof(struct gameState); j++) {
			((char*)&G)[i] = (rand() % (256 - 0 + 1));
		};
		player = (rand() % (numPlayer));
		nextPlayer = (rand() % (numPlayer));
		while (nextPlayer == player) {
			nextPlayer = (rand() % (2 - 0 + 1));
		};

		G.deckCount[player] = (rand() % (MAX_DECK - 0 + 1));
		G.discardCount[player] = (rand() % (MAX_DECK - 0 + 1));
		G.handCount[player] = (rand() % (MAX_HAND - 0 + 1));
		G.deckCount[nextPlayer] = (rand() % (MAX_DECK - 0 + 1));
		G.discardCount[nextPlayer] = (rand() % (MAX_DECK - 0 + 1));
		G.handCount[nextPlayer] = (rand() % (MAX_HAND - 0 + 1));
		G.playedCardCount = 0;

		for (h = 0; h < G.deckCount[nextPlayer]; h++) {
			G.deck[nextPlayer][h] = (rand() % (27 - 0 + 1));
		};
		for (h = 0; h < G.discardCount[nextPlayer]; h++) {
			G.discard[nextPlayer][h] = (rand() % (27 - 0 + 1));
		};

		tributeEffect(player, nextPlayer, &G);
	};

	printf("Passed all tests \n");

	system("pause");
};