/*
	Name :- Dishank Gandhi
	PRN :- 1032232071
	Problem Statement :- Write a C program for sparse matrix realization and operations on it- Simple Transpose, Fast Transpose.
*/

#include <stdio.h>
#include <stdlib.h>

void acceptMatrix(int A[100][100], int m, int n)
{
    printf("\nEnter data for matrix:\n\n");

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter element for index (%d, %d): ", i, j);
            scanf("%d", &A[i][j]);
        }
        printf("\n");
    }
}

void displayMatrix(int A[100][100], int m, int n)
{
    printf("\nInput matrix:\n\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void compact(int A[100][100], int m, int n, int B[100][3])
{
    B[0][0] = m;
    B[0][1] = n;

    int k = 1;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (A[i][j] != 0)
            {
                B[k][0] = i;
                B[k][1] = j;
                B[k][2] = A[i][j];
                k++;
            }
        }
    }

    B[0][2] = k - 1;

    printf("\nCompact form of the matrix:\n\n");
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

void simpleTranspose(int B[100][3], int C[100][3])
{
    C[0][0] = B[0][1];
    C[0][1] = B[0][0];
    C[0][2] = B[0][2];

    if (B[0][2] <= 0)
    {
        return;
    }

    int q = 1;
    
    for (int col = 0; col < B[0][1]; col++)
    {
        for (int p = 1; p <= B[0][2]; p++)
        {
            if (B[p][1] == col)
            {
                C[q][0] = B[p][1];
                C[q][1] = B[p][0];
                C[q][2] = B[p][2];
                q++;
            }
        }
    }

    printf("\nTransposed compact form of the matrix:\n\n");
    for (int i = 0; i <= C[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void fastTranspose(int B[100][3] , int C[100][3])
{
    int S[B[0][1]];
    int T[B[0][1] + 1];

    C[0][0] = B[0][1];
    C[0][1] = B[0][0];
    C[0][2] = B[0][2];

    if (B[0][2] <= 0)
    {
        return;
    }

    for (int i = 0 ; i < B[0][1] ; i++)
    {
        S[i] = 0;
    }

    for(int i = 1 ; i <= B[0][2] ; i++)
    {
        S[B[i][1]] = S[B[i][1]] + 1;
    }

    T[0] = 1;

    for (int i = 1 ; i <= B[0][1] ; i++)
    {
        T[i] = T[i-1] + S[i-1];
    }
    
    for(int i = 1 ; i <= B[0][2] ; i++)
    {
        int j = B[i][1];
        int k = T[j];
        
        C[k][0] = B[i][1];
        C[k][1] = B[i][0];
        C[k][2] = B[i][2];
        
        T[j]++;
    }

     printf("\nFast Transposed compact form of the matrix:\n\n");
    for (int i = 0; i <= C[0][2]; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}

int main(void)
{
    int m, n;
    printf("\nEnter number of rows: ");
    scanf("%d", &m);
    printf("Enter number of columns: ");
    scanf("%d", &n);
    int A[m][n], B[m * n][3], C[m * n][3];

    acceptMatrix(A, m, n);
    displayMatrix(A, m, n);

    compact(A, m, n, B);
    simpleTranspose(B, C);
    fastTranspose(B, C);

    return 0;
}