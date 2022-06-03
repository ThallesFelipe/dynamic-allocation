// NOME: Thalles Felipe Rodrigues de Almeida Santos
// TURMA: 32
// MATRÍCULA: 21.2.4130

#include <stdio.h>
#include <stdlib.h>

void imprimirMatriz(double **matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%.0lf ", matriz[i][j]);
        }
        printf("\n");
    }
}

double **criaMatriz(int m, int n)
{
    double **A;

    A = malloc(m * sizeof(double *));

    for (int i = 0; i < m; i++)
    {
        A[i] = malloc(n * sizeof(double));
    }

    return A;
}

double **transportar(double **matriz, int m, int n)
{
    double **B;

    B = criaMatriz(n, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            B[i][j] = matriz[j][i];
        }
    }
    return B;
}

void liberarMatriz(double **A, int m)
{
    for (int i = 0; i < m; i++)
    {
        free(A[i]);
    }
    free(A);
}

int main(int argc, char const *argv[])
{
    int m, n;

    printf("Digite a quantidade de linhas: ");
    scanf("%d", &m);
    printf("Digite a quantidade de colunas: ");
    scanf("%d", &n);

    double **matriz = criaMatriz(m, n);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Matriz[%d][%d] = ", i, j);
            scanf("%lf", &matriz[i][j]);
            printf("\n");
        }
    }
    imprimirMatriz(matriz, m, n);
    printf("\n");
    double **aT = transportar(matriz, m, n);
    imprimirMatriz(aT, n, m);
    printf("\n");
    free(aT);
    free(matriz);
    return 0;
}