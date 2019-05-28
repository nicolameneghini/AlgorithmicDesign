#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "functions.h"

#define MAX_ELEM_VALUE 25

void randomly_fill_matrix(float **A, const size_t A_rows, const size_t A_cols)
{
  for (size_t i = 0; i < A_rows; i++)
  {
    for (size_t j = 0; j < A_cols; j++)
    {
      A[i][j] = rand() % (2 * MAX_ELEM_VALUE) - MAX_ELEM_VALUE;
    }
  }
}

int main()
{

  float ***A;

  int row1 = 3, col1 = 5;
  //A[1] = allocate_matrix(row1, col1);

  int row2 = 5, col2 = 10;
  //A[2] = allocate_matrix(row2, col2);

  int row3 = 10, col3 = 2;
  // A[3] = allocate_matrix(row3, col3);

  int row4 = 2, col4 = 3;
  //A[4] = allocate_matrix(row4, col4);

  int P[5];

  //P[0] = row1; P[1] = col1; P[2] = row2; P[3] = col2; P[4] = row3; P[5] = col3; P[6] = row4; P[7] = col4;

  P[0] = row1;
  P[1] = col1;
  P[2] = col2;
  P[3] = col3;
  P[4] = col4;

  float **s;

  s = allocate_matrix(4, 4);

  s = matrix_chain(P, 4);

  printf("\n");
  printf("\n");

  for (size_t i = 0; i < 4; i++)
  {

    for (size_t j = 0; j < 4; j++)

      printf("%f ", s[i][j]);

    printf("\n");
  }

  return 0;
}
