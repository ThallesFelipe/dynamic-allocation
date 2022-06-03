// NOME: Thalles Felipe Rodrigues de Almeida Santos
// TURMA: 32
// MATRÍCULA: 21.2.4130

#include <stdio.h>
#include <stdlib.h>

int multiMatriz(int ***R, int **A, int n, int m, int **B, int p, int q)
{
    *R = calloc(n, sizeof(int *));
    for (int i = 0; i < n; i++)
        (*R)[i] = calloc(q, sizeof(int));

    if (m == p)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < q; j++)
                for (int k = 0; k < p; k++)
                    (*R)[i][j] += A[i][k] * B[k][j];
        return 1;
    }
    return 0;
}
int main()
{
    int n, m, p, q, resultado;

    printf("Digite os tamanhos da matriz A: ");
    scanf("%d %d", &n, &m);
    int **A = malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
        A[i] = malloc(m * sizeof(int));
    printf("Digite os dados da matriz A: \n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &A[i][j]);

    printf("Digite os tamanhos da matriz B: ");
    scanf("%d %d", &p, &q);

    int **B = malloc(p * sizeof(int *));
    for (int i = 0; i < p; i++)
        B[i] = malloc(q * sizeof(int));
    printf("Digite os dados da matriz B: \n");
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    int **R;

    resultado = multiMatriz(&R, A, n, m, B, p, q);
    if (resultado == 0)
    {
        printf("Não é possível multiplicar as matrizes A e B.\n");
    }
    else
    {
        printf("Resultado de A x B:\n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < q; j++)
            {
                printf("%d ", R[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}