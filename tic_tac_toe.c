#include <stdio.h>
#include <stdbool.h>

char grid[9];

/*
 * -----------------------------------------------------------------------------
 * Function: resetGrid
 * Description: Initializes the game board array with character digits '1' 
 * through '9' to represent available slot numbers.
 * -----------------------------------------------------------------------------
 */
void resetGrid()
{
    for (int k = 0; k < 9; k++)
    {
        grid[k] = (char)('1' + k);
    }
}

/*
 * -----------------------------------------------------------------------------
 * Function: render
 * Description: Draws the current state of the game board to the console using 
 * ASCII art.
 * -----------------------------------------------------------------------------
 */
void render()
{
    printf("\n");
    printf("  %c  ||  %c  ||  %c  \n", grid[0], grid[1], grid[2]);
    printf("======++=====++======\n");
    printf("  %c  ||  %c  ||  %c  \n", grid[3], grid[4], grid[5]);
    printf("======++=====++======\n");
    printf("  %c  ||  %c  ||  %c  \n", grid[6], grid[7], grid[8]);
    printf("\n");
}

/*
 * -----------------------------------------------------------------------------
 * Function: hasWon
 * Description: Checks if the specified player ('X' or 'O') has occupied any 
 * of the 8 possible winning lines (horizontal, vertical, or diagonal).
 * -----------------------------------------------------------------------------
 */
bool hasWon(char p)
{
    // Check all 8 winning lines using a compact logic
    int wins[8][3] = {
        {0,1,2}, {3,4,5}, {6,7,8}, // Horizontal
        {0,3,6}, {1,4,7}, {2,5,8}, // Vertical
        {0,4,8}, {2,4,6}           // Diagonal
    };

    for (int i = 0; i < 8; i++)
    {
        if (grid[wins[i][0]] == p && 
            grid[wins[i][1]] == p && 
            grid[wins[i][2]] == p) return true;
    }
    return false;
}

/*
 * -----------------------------------------------------------------------------
 * Function: isFull
 * Description: Scans the board to check if every slot is occupied by an 'X' 
 * or an 'O', indicating a draw state if no winner exists.
 * -----------------------------------------------------------------------------
 */
bool isFull()
{
    for (int i = 0; i < 9; i++)
    {
        if (grid[i] != 'X' && grid[i] != 'O') return false;
    }
    return true;
}

/*
 * -----------------------------------------------------------------------------
 * Function: main
 * Description: Runs the main game loop, handling player turns, input validation,
 * and checking for win/draw conditions after every move.
 * -----------------------------------------------------------------------------
 */
int main()
{
    int turn = 0;
    int slot;
    char mark;
    bool gameRunning = true;

    resetGrid();
    printf("--- Noughts & Crosses ---\n");

    while (gameRunning)
    {
        render();
        mark = (turn % 2 == 0) ? 'X' : 'O';
        printf("Player [%c] choose slot: ", mark);

        if (scanf("%d", &slot) != 1)
        {
            while(getchar() != '\n'); // flush
            continue;
        }

        if (slot < 1 || slot > 9)
        {
            printf(">> Invalid range (1-9).\n");
            continue;
        }

        int idx = slot - 1;
        if (grid[idx] == 'X' || grid[idx] == 'O')
        {
            printf(">> Slot occupied.\n");
            continue;
        }

        grid[idx] = mark;

        if (hasWon(mark))
        {
            render();
            printf("*** Player %c Victory! ***\n", mark);
            gameRunning = false;
        }
        else if (isFull())
        {
            render();
            printf("--- Stalemate ---\n");
            gameRunning = false;
        }

        turn++;
    }

    return 0;
}