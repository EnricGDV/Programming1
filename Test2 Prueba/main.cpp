/**********************************************************************
 *                        TYPE YOUR NAME HERE                         *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "UnitTest.h"

// Type definition for a byte
typedef unsigned char byte;

// Struct for the player status
struct Candy
{
	byte flags;   // bit 3 tells whether or not the piece will blast
	              // bit 4 tells whether or not the piece is invalid
	int points;   // value of the candy piece
};

// Use this function if you want to check the bits of a number
void printBits(byte bits)
{
	for (int i = 8; i > 0; --i)
	{
		printf("%d", (bits >> (i - 1)) & 1);
	}
	printf("\n");
}

int explodeCandies(Candy candies[], int numCandies)
{
	// TODO: Type your code here
	int totalScore = 0;
	for (int i = 0; i < numCandies; i++)
		if (((candies[i].flags & (1 << 4)) == 0) && ((candies[i].flags & (1 << 3)) != 0))
		{
			candies[i].flags = candies[i].flags | (1 << 4);
			candies[i].flags = candies[i].flags & ~(1 << 3);
			totalScore += candies[i].points;
		}
	return totalScore;
}

void resetCandy(Candy candies[], int candyIndex, int points)
{
	// TODO: Type your code here
	candies[candyIndex].flags = candies[candyIndex].flags & ~(1 << 4);
	candies[candyIndex].flags = candies[candyIndex].flags | (1 << 3);
	candies[candyIndex].points = points;

}

void testExercise();

int main()
{
	testExercise();

	system("pause");
	return 0;
}


int areCandiesEqual(Candy candies1[], Candy candies2[])
{
	for (int i = 0; i < 5; ++i)
	{
		if (candies1[i].flags != candies2[i].flags) return 0;
		if (candies1[i].points != candies2[i].points) return 0;
	}
	return 1;
}

void testExercise()
{
	const byte BlastFlag = 1 << 3;
	const byte InvalidFlag = 1 << 4;

	// Initial state of players
	Candy candies1[5] = {
	{ BlastFlag, 1 },
	{ BlastFlag, 1 },
	{ BlastFlag, 1 },
	{ BlastFlag, 1 },
	{ BlastFlag, 1 },
	};
	// After explodeCandies
	Candy candies2[5] = {
	{ InvalidFlag, 1 },
	{ InvalidFlag, 1 },
	{ InvalidFlag, 1 },
	{ InvalidFlag, 1 },
	{ InvalidFlag, 1 },
	};
	// After candyReset
	Candy candies3[5] = {
	{ InvalidFlag, 1 },
	{ BlastFlag,   5 },
	{ InvalidFlag, 1 },
	{ BlastFlag,   5 },
	{ InvalidFlag, 1 },
	};
	// After explodeCandies
	Candy candies4[5] = {
	{ InvalidFlag, 1 },
	{ InvalidFlag, 5 },
	{ InvalidFlag, 1 },
	{ InvalidFlag, 5 },
	{ InvalidFlag, 1 },
	};
	// After explodeCandies
	byte stubFlag = 1 << 7;
	Candy candies5[5] = {
	{ stubFlag | BlastFlag,   1 },
	{ stubFlag | BlastFlag,   5 },
	{ stubFlag | InvalidFlag, 1 },
	{ stubFlag | BlastFlag,   7 },
	{ stubFlag | InvalidFlag, 1 },
	};
	// After explodeCandies
	Candy candies6[5] = {
	{ stubFlag | InvalidFlag, 1 },
	{ stubFlag | InvalidFlag, 5 },
	{ stubFlag | InvalidFlag, 1 },
	{ stubFlag | InvalidFlag, 7 },
	{ stubFlag | InvalidFlag, 1 },
	};
	// After resetCandy
	Candy candies7[5] = {
	{ stubFlag | BlastFlag, 1 },
	{ stubFlag | BlastFlag, 2 },
	{ stubFlag | BlastFlag, 3 },
	{ stubFlag | BlastFlag, 4 },
	{ stubFlag | BlastFlag, 5 },
	};
	// After explodeCandies
	Candy candies8[5] = {
	{ stubFlag | InvalidFlag, 1 },
	{ stubFlag | InvalidFlag, 2 },
	{ stubFlag | InvalidFlag, 3 },
	{ stubFlag | InvalidFlag, 4 },
	{ stubFlag | InvalidFlag, 5 },
	};

	int score = explodeCandies(candies1, 5);
	bool equals = areCandiesEqual(candies1, candies2);
	TEST("explodeCandies", score == 5 && equals == true);

	resetCandy(candies2, 1, 5);
	resetCandy(candies2, 3, 5);
	equals = areCandiesEqual(candies2, candies3);
	TEST("resetCandy", equals == true);

	score = explodeCandies(candies3, 5);
	equals = areCandiesEqual(candies3, candies4);
	TEST("explodeCandies", score == 10 && equals == true);

	score = explodeCandies(candies5, 5);
	equals = areCandiesEqual(candies5, candies6);
	TEST("explodeCandies", score == 13 && equals == true);

	resetCandy(candies6, 0, 1);
	resetCandy(candies6, 1, 2);
	resetCandy(candies6, 2, 3);
	resetCandy(candies6, 3, 4);
	resetCandy(candies6, 4, 5);
	equals = areCandiesEqual(candies6, candies7);
	TEST("resetCandy", equals == true);

	score = explodeCandies(candies6, 5);
	equals = areCandiesEqual(candies7, candies7);
	TEST("explodeCandies", score == 15 && equals == true);

	PRINT_TEST_REPORT();
}