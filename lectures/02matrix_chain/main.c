#include <stdlib.h>
#include <stdio.h>
#include "matrix.h"

#define CMM(M, row, col) //macro to pass from the "full matrix" to a triangula one: the full matrix is upper triangular. I make the rows to be columns: A[i][j] = A[i][j-1]

/*
Solve the chian Matrix Multiplication Problem

Takes the array if dimentions of the matrixes

Returns the matrix
*/

size_t **ChainMatrixMul(size_t *dim, size_t n)
{
    //Initialization
    size_t **M = (size_t **)malloc(sizeof(size_t *) * n);
    size_t **S = (size_t **)malloc(sizeof(size_t *) * n); //maybe n-1

    for (size_t i = 0; i < n; i++)
    {

        M[i] = (size_t *)malloc(sizeof(size_t) * (n - i)); //I have to put the number of rows: each row represent the
                                                           //origin of the chain matrix, while the column is the last
                                                           //--> so the matrix ois of always smaller size

        S[i] = (size_t *)malloc(sizeof(size_t) * (n - i)); //Also I do wouldn't need to allocate space in the diagonal

        M[i][0] = 0;
        S[i][i] = i;
    }

    //end initialization

    //we basically moved the main diagonal of the matrix to the firts column, the second diagonal to the second colum or sth lik this.
    //This was done to avoid recurive calls.

    for (size_t l = 1; l < n; l++) //for all the diagonal up to the rightmost one
    {
        for (size_t i = 0; i < n - l; i++)
        {
            size_t j = l + i;

            M[i][j] = M[i][j - 1] + M[j][j] + (dim[i] * dim[j] * dim[j]);
            S[i][j] = j - 1;

            for (size_t k = i; k < j; k++)
            {
                size_t c = M[i][k] + M[k + 1][l] + (dim[i] * dim[j + 1] * dim[k + 1]);

                if (c < M[i][j])
                {
                    M[i][j] = c;
                    S[i][j] = k;
                }
            }
        }
    }

    for (size_t i = 0; i < n; i++)
        free(M[i]);

    free(M);

    return S;
}

void print_out_parenthesis_aux(size_t **S, size_t i, size_t j)
{
    if (i == j && S[i][j] > j)

        return;

    printf(",%zu", S[i][j]);
    print_out_parenthesis_aux(S, i, S[i][j]);
    print_out_parenthesis_aux(S, S[i][j] + 1, j);
}



void print_out_parenthesis(size_t **S, size_t n)
{
    print_out_parenthesis_aux(S, 0, n - 1);
}

size_t *build_dimensions(const size_t n)
{
    size_t *dims = (size_t *)malloc(sizeof(size_t) * (n + 1));

    for (size_t i = 0; i < n + 1; i++)
    {
        dims[i] = rand() % 500;
    }

    return dims;
}

float ***build_problem_instance(const size_t *dims, const size_t n) //return an array of matrixes whose size will be dims
{
    float ***A = (float***)malloc(sizeof(float**)*n);

    for (size_t i = 0; i < n; i++)
    {
       A[i] = allocate_matrix( dims[i],dims[i+1]); 
    }

    return A;
}

int main()
{
    size_t n = 15;
    size_t*dims = build_dimensions(n);
    float *** As = build_problem_instance(dims, n);
    size_t **S = ChainMatrixMul(dims, n);

    print_out_parenthesis(S, n);


    for(size_t i = 0; i < n; i++)
    {
        deallocate_matrix(As[i], dims[i]);
    }

    free(As);
    free(dims);
    deallocate_matrix(S,n);
    return 0;
}