#include <stdlib.h>
#include <math.h>
#include <stdio.h>

float **allocate_matrix(const size_t rows,
                        const size_t cols)
{
    float **A = (float **)calloc(sizeof(float *), rows);

    for (size_t i = 0; i < rows; i++)
    {
        A[i] = (float *)calloc(sizeof(float), cols);
    }

    for (size_t l = 0; l < rows; l++)
    {

        for (size_t i = 0; i < cols; i++)
        {

            A[l][i] = INFINITY;
        }
    }

    return A;
}

void MatrixChainAux(int *P, float **m, float **s, size_t i, size_t j)
{
    //m[i][j] = INFINITY;

    float q;

    for (size_t k = i; k <= j - 1; k++)
    {
        q = m[i - 1][k - 1] + m[k][j - 1] + P[i - 1] * P[k] * P[j];

        if (q < m[i - 1][j - 1])
        {
            m[i - 1][j - 1] = q;
            s[i - 1][j - 1] = k;
        }
    }
}

float **matrix_chain(int *P, size_t dim)
{

    //size_t dim = (sizeof(P)/sizeof(P[0]))/2;

    float **m = allocate_matrix(dim, dim);
    float **s = allocate_matrix(dim, dim);

    for (size_t i = 0; i < dim; i++)
        m[i][i] = 0;

    for (size_t l = 1; l <= dim; l++)
    {

        for (size_t i = 1; i <= dim - l + 1; i++)
        {

            size_t j = i + l - 1;

            MatrixChainAux(P, m, s, i, j);
        }
    }
    for (size_t i = 0; i < dim; i++)
    {

        for (size_t j = 0; j < dim; j++)

            printf("%f ", m[i][j]);

        printf("\n");
    }

    return s;
}
