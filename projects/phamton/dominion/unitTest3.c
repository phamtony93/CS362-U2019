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
	printf("Test 1: Call Ambassador effect sacrificing 1 silver card, while having 3 copies in hand \n");
	//Set all players to have copper in discard
	for (i = 0; i < MAX_PLAYERS; i++) {
		for (j = 0; j < MAX_DECK; j++) {
			G.discard[i][j] = copper;
		};
	};

	//Set player 0 to have 3 silver and 1 ambassador
	int silverCountOld = 3;
	int silverCountNew = 0;
	for (i = 0; i < 3; i++) {
		G.hand[0][i] = silver;
	};
	G.hand[0][4] = ambassador;

	//Sacrifice 1 silver but have 3 in hand
	j = ambassadorEffect(0, 1, 0, &G, 4);

	printf("Test 1.1: Check that function returns 0 \n");
	if (j == 0) {
		printf("Passed Test 1.1 \n");
	}
	else {
		printf("Failed Test 1.1 \n");
	};

	for (i = 0; i < MAX_HAND; i++) {
		if (G.hand[0][i] == silver) {
			silverCountNew++;
		}
	};

	printf("Test 1.2: Check that number of silver in hand decremented by 1 \n");
	if (silverCountOld - 1 == silverCountNew) {
		printf("Passed Test 1.2 \n");
	}
	else {
		printf("Failed Test 1.2 \n");
	};

	int numPlayerWithSilver = 0;
	for (i = 0; i < MAX_PLAYERS; i++) {
		for (l = 0; l < MAX_DECK; l++) {
			if (G.discard[i][l] == silver) {
				numPlayerWithSilver++;
				break;
			};
		};
	};

	printf("Test 1.3: Test that number of players with silver in discard is 1 \n");
	if (numPlayerWithSilver == 1) {
		printf("%d \n", numPlayerWithSilver);
		printf("Passed Test 1.3 \n");
	}
	else {
		printf("%d \n", numPlayerWithSilver);
		printf("Failed Test 1.3 \n");
	};

	//Test 2
	printf("Test 2: Call Ambassador effect sacrificing 2 silver card, while having 1 copy in hand \n");
	//Set all players to have copper in discard
	for (i = 0; i < MAX_PLAYERS; i++) {
		for (j = 0; j < MAX_DECK; j++) {
			G.discard[i][j] = copper;
		};
	};

	//Set player 0 to have 1 silver and 1 ambassador
	silverCountOld = 3;
	silverCountNew = 0;
	for (i = 0; i < 2; i++) {
		G.hand[0][i] = copper;
	};
	G.hand[0][4] = ambassador;
	G.hand[0][3] = silver;

	//Sacrifice 2 silver but have 1 in hand
	j = ambassadorEffect(0, 2, 0, &G, 4);

	printf("Test 2: Only 1 player with silver in discard \n");
	if (j == -1) {
		printf("Passed Test 2 \n");
	}
	else {
		printf("Failed Test 2 \n");
	};

	


	//system("pause");
}