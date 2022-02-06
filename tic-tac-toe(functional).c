#include <stdio.h>

void SetBoard(char cells[], char player);
void DrawBoard(char cells[]);
int CheckWinner(char cells[], char player);

int main()
{
	int playing = 1;

	while (playing == 1)
	{
		char cells[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
		char player = 'X';
		int round = 1;

		while (round <= 9)
		{
			SetBoard(cells, player);
			DrawBoard(cells);

			if (CheckWinner(cells, player)) // Check if the player has won this game
				break; // End the game
			else if (round == 9)
				printf("Game Over!\nNobody won this game.\n");

			// Change turn
			if (player == 'X')
				player = 'O';
			else
				player = 'X';

			round++;
		}

		printf("If you want to play again enter 1, otherwise, enter 2: ");
		scanf("%d", &playing);
	}

	return 0;
}

void SetBoard(char cells[], char player)
{
	int index = -1;

	if (player == 'X')
		printf("Player 1's turn\n");
	else
		printf("Player 2's turn\n");

	while (index == -1)
	{
		int junkRead = 0;
		char junk;

		printf("Please choose a number between 1 and 9: ");
		scanf("%d", &index);
		index--; // User has to choose a number between 1 and 9 but the array index is from 0 to 8

		do
		{
			scanf("%c", &junk);
			junkRead++;
		} while (junk != '\n');

		if (junkRead > 1)
		{
			printf("\nEnter a number!\n\n");
			index = -1;
		}
		else if (index < 0 || index > 8)
		{
			printf("\nYour choice must be between 1 and 9.\n\n");
			index = -1;
		}
		else if (cells[index] != ' ')
		{
			printf("\nBlock's taken!\n\n");
			index = -1;
		}
	}

	cells[index] = player;
}

void DrawBoard(char cells[])
{
/*    ...|...|
	* .C.|.C.|.C
	* ___|___|___
	* ...|...|
	* .C.|.C.|.C
	* ___|___|___
	* ...|...|
	* .C.|.C.|.C
	* ...|...|
	*/

	printf("   |   |\n");
	printf(" %c | %c | %c\n", cells[0], cells[1], cells[2]);
	printf("___|___|___\n");
	printf("   |   |\n");
	printf(" %c | %c | %c\n", cells[3], cells[4], cells[5]);
	printf("___|___|___\n");
	printf("   |   |\n");
	printf(" %c | %c | %c\n", cells[6], cells[7], cells[8]);
	printf("   |   |\n");
}

int CheckWinner(char cells[], char player)
{
	int triple = player * 3;

	if (cells[0] + cells[1] + cells[2] == triple || cells[3] + cells[4] + cells[5] == triple
		|| cells[6] + cells[7] + cells[8] == triple || cells[0] + cells[3] + cells[6] == triple
		|| cells[1] + cells[4] + cells[7] == triple || cells[2] + cells[5] + cells[8] == triple
		|| cells[0] + cells[4] + cells[8] == triple || cells[2] + cells[4] + cells[6] == triple)
	{
		printf("Congratulations!\n");

		if (player == 'X')
			printf("Player 1 has won the game!\n\n");
		else
			printf("Player 2 has won the game!\n\n");

		return 1;
	}

	return 0;
}
