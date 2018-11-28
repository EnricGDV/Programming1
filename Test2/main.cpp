/**********************************************************************
 *                     Enric-Guillem Durán Vilar                      *
 **********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "UnitTest.h"

// Type definition for a byte
typedef unsigned char byte;

// Constants
#define MAX_LIVES 3
#define MAX_HEALTH 10

// Struct for the player status
struct Player
{
	byte flags;   // bit 5 tells whether or not the player is active
	int health;   // remaining health
	int numLives; // remaining number of lives
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

void applyDamageToPlayers(Player players[], int numPlayers, int damage)
{
	// TODO: Type your code here
	for (int i = 0; i < numPlayers; i++)
	{
		if ((players[i].flags & (1 << 5)) != 0)
		{
			players[i].health -= damage;

			if (players[i].health <= 0)
			{
				players[i].numLives--;
				if (players[i].numLives == 0)
				{
					players[i].health = 0;
					players[i].flags &= ~(1 << 5);
				}else {
					players[i].health = MAX_HEALTH;
				}
			}
		}
	}
}

void resurrectPlayers(Player players[], int numPlayers)
{
	// TODO: Type your code here
	for (int i = 0; i < numPlayers; i++)
	{
		if ((players[i].flags & (1 << 5)) == 0)
		{
			players[i].flags |= (1 << 5);
			players[i].numLives = MAX_LIVES;
			players[i].health = MAX_HEALTH;
		}
	}
}










void testExercise();

int main()
{
	testExercise();

	system("pause");
	return 0;
}

int arePlayersEquals(Player players1[], Player players2[])
{
	for (int i = 0; i < 5; ++i)
	{
		if (players1[i].flags != players2[i].flags) return 0;
		if (players1[i].health != players2[i].health) return 0;
		if (players1[i].numLives != players2[i].numLives) return 0;
	}
	return 1;
}

void testExercise()
{
	// Initial state of players
	Player players1[5] = {
	{32, 1,  1},
	{32, 10, 1},
	{32, 5,  2},
	{32, 4,  3},
	{32, 10, 3}
	};
	// After applyDamage 6
	Player players2[5] = {
	{0,  0,  0},
	{32, 4,  1},
	{32, 10, 1},
	{32, 10, 2},
	{32, 4,  3}
	};
	// After applyDamage 5
	Player players3[5] = {
	{0,  0,  0},
	{0,  0,  0},
	{32, 5,  1},
	{32, 5,  2},
	{32, 10, 2}
	};
	// After resurrect
	Player players4[5] = {
	{32, 10, 3},
	{32, 10, 3},
	{32, 5,  1},
	{32, 5,  2},
	{32, 10, 2}
	};
	// After resurrect - with mixed flags
	Player players4b[5] = {
	{0xb8, 10, 3},
	{0xb8, 10, 3},
	{0xb8, 5,  1},
	{0xb8, 5,  2},
	{0xb8, 10, 2}
	};
	// After applyDamage 5
	Player players5[5] = {
	{0xb8, 5,  3},
	{0xb8, 5,  3},
	{0x98,  0,  0},
	{0xb8, 10, 1},
	{0xb8, 5, 2}
	};
	// After applyDamage 11
	Player players6[5] = {
	{0xb8, 10, 2},
	{0xb8, 10, 2},
	{0x98,  0,  0},
	{0x98,  0,  0},
	{0xb8, 10, 1}
	};
	// After resurrect
	Player players7[5] = {
	{0xb8, 10, 2},
	{0xb8, 10, 2},
	{0xb8, 10, 3},
	{0xb8, 10, 3},
	{0xb8, 10, 1}
	};
	// After applyDamage 10
	Player players8[5] = {
	{0xb8, 10, 1},
	{0xb8, 10, 1},
	{0xb8, 10, 2},
	{0xb8, 10, 2},
	{0x98,   0, 0}
	};

	applyDamageToPlayers(players1, 5, 6);
	TEST("applyDamageToPlayers", arePlayersEquals(players1, players2));

	applyDamageToPlayers(players2, 5, 5);
	TEST("applyDamageToPlayers", arePlayersEquals(players2, players3));

	resurrectPlayers(players3, 5);
	TEST("resurrectPlayers", arePlayersEquals(players3, players4));

	applyDamageToPlayers(players4b, 5, 5);
	TEST("applyDamageToPlayers", arePlayersEquals(players4b, players5));

	applyDamageToPlayers(players5, 5, 11);
	TEST("applyDamageToPlayers", arePlayersEquals(players5, players6));

	resurrectPlayers(players6, 5);
	TEST("resurrectPlayers", arePlayersEquals(players6, players7));

	applyDamageToPlayers(players7, 5, 10);
	TEST("applyDamageToPlayers", arePlayersEquals(players7, players8));

	PRINT_TEST_REPORT();
}