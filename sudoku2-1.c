//Lance Boza
#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define EMPTY 0

int board[16][48];
int solution[16][16];

// majority of the program comes from Meade's sudoku code
void readBoard(int size);
void printBoard(int size);
int isValid(int size);
int backTrack(int r, int, int size);
void printSolution(int size);



int main()
{
  int row, col;
  int size;
  scanf("%d", &size);

  readBoard(size);

  // fills the array with 0's
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      solution[row][col] = 0;
    }
  }

  if (backTrack(0, 0, size))
  {
    //printBoard(size);
    printSolution(size);
  }
  else
  {
    printf("No Solution found.\n");
  }

  return 0;
}

int isValid(int size)
{
    int row, col, value;

    // Check each row
    for (row = 0; row < size; row++)
    {
        // Set that no value exists
        int contains[size];
        for (value = 0; value < size; value++)
        {
            contains[value] = FALSE;
        }

        // Loop through the col
        for (col = 0; col < size; col++)
        {
            // Check if a value is present
              if (solution[row][col] != EMPTY)
            {
                // Check if the value is already in the row
                if (contains[solution[row][col] - 1])
                {
                    return FALSE;
                }

                // Set the value is in the row
                contains[solution[row][col] - 1] = TRUE;
            }
        }
    }

    // Check each column
    for (col = 0; col < size; col++)
    {
        // Set that no value exists
        int contains[size];
        for (value = 0; value < size; value++)
        {
            contains[value] = FALSE;
        }

        // Loop through the row
        for (row = 0; row < size; row++)
        {
            // Check if a value is present
            if (solution[row][col] != EMPTY)
            {
                // Check if the value is already in the row
                if (contains[solution[row][col] - 1])
                {
                    return FALSE;
                }

                // Set the value is in the row
                contains[solution[row][col] - 1] = TRUE;
            }
        }
    }

    // No invalid row, column, or nonet was found
    return TRUE;
}

int backTrack(int r, int c, int size)
{
    // THIS IS BACKTRACKING : Check validity
    if (!isValid(size))
    {
        return FALSE;
    }

    // Check if col index (c) is off the board
    if (c == size)
    {
        return backTrack(r + 1, 0, size);
    }

    // Check if row index (r) is off the board
    if (r == size)
    {
        return TRUE;
    }

    // Try all possible decisions
    int attempt;
    // instead of going through 1 - 9 on attempts, start at col * 3 to get the first position of the
    // corresponding hat and get the next 3 numbers
    for (attempt = c * 3; attempt < (c * 3) + 3; attempt++)
    {
      solution[r][c] = board[r][attempt];
      if (backTrack(r, c + 1, size))
        return TRUE;

      // Undo the choice
      solution[r][c] = EMPTY;
    }

    // No solution found
    return FALSE;
}

void printBoard(int size)
{
    int i, j, row, col;
    int colSize = size * 3;
    for (i = 0; i < size; i++)
    {
        for (j = 0; j < colSize; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }


}

void readBoard(int size)
{
    int i, j;
    int colSize = size * 3;
    for (i = 0; i < size; i++)
        for (j = 0; j < colSize; j++)
            scanf("%d", &board[i][j]);
}

void printSolution(int size){
  int row, col;
  for(row = 0; row < size; row++){
    for(col = 0; col < size; col++){
      printf("%d ", solution[row][col]);
    }
    printf("\n");
  }
}
