#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// here I'm defining the max position
#define WIN_POSITION 100
#define NUM_SNAKES 5
#define NUM_LADDERS 5

// Snakes and ladders positions
int snakes[NUM_SNAKES][2] = {{51, 11}, {56, 15}, {62, 57}, {92, 53}, {98, 8}};
int ladders[NUM_LADDERS][2] = {{2, 38}, {4, 14}, {9, 31}, {33, 85}, {52, 88},{80,99}};

// calling the function here
int rollDice();
void updatePosition(int *position, int roll);
void printBoard(int player1, int player2);
void checkSnakesAndLadders(int *position);

int main() {
    int player1Position = 0, player2Position = 0;
    int currentPlayer = 1;
    int roll;

    srand(time(NULL));  // for generating the random numbers

    while (player1Position < WIN_POSITION && player2Position < WIN_POSITION) {
        printf("Player %d's turn\n", currentPlayer);
        roll = rollDice();
        printf("Rolled: %d\n", roll);

        if (currentPlayer == 1) {
            updatePosition(&player1Position, roll);
            checkSnakesAndLadders(&player1Position);
            printBoard(player1Position, player2Position);

            if (player1Position >= WIN_POSITION) {
                printf("Player 1 wins!\n");
                break;
            }
            currentPlayer = 2;
        } else {
            updatePosition(&player2Position, roll);
            checkSnakesAndLadders(&player2Position);
            printBoard(player1Position, player2Position);

            if (player2Position >= WIN_POSITION) {
                printf("Player 2 wins!\n");
                break;
            }
            currentPlayer = 1;
        }
    }

    return 0;
}

int rollDice() {
    return rand() % 6 + 1;
}

void updatePosition(int *position, int roll) {
    *position += roll;
    if (*position > WIN_POSITION) {
        *position = WIN_POSITION;
    }
}

void checkSnakesAndLadders(int *position) {
    // loop for checking the snakes
    for (int i = 0; i < NUM_SNAKES; i++) {
        if (*position == snakes[i][0]) {
            printf("SHIT BHAI! %d to %d\n", *position, snakes[i][1]);
            *position = snakes[i][1];
            break;
        }
    }

    // loop for climbing the ladders
    for (int i = 0; i < NUM_LADDERS; i++) {
        if (*position == ladders[i][0]) {
            printf("WE! GOT A LADDER YAYAYYAYA %d to %d\n", *position, ladders[i][1]);
            *position = ladders[i][1];
            break;
        }
    }
}

void printBoard(int player1, int player2) {
    printf("Player 1 is at position %d\n", player1);
    printf("Player 2 is at position %d\n", player2);
    printf("---------------------------\n");
}
