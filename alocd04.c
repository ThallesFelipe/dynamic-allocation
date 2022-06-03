// NOME: Thalles Felipe Rodrigues de Almeida Santos
// TURMA: 32
// MATRÍCULA: 21.2.4130

#include <stdio.h>
#include <stdlib.h>

int quadradoMagico(int **matriz, int n)
{
    int i = 0, j = 0, somaDiagonal1 = 0, somaDiagonal2 = 0;

    for (i = 0; i < n; i++)
    {
        somaDiagonal1 += matriz[i][i];
        somaDiagonal2 += matriz[i][n - 1 - i];
    }

    if (somaDiagonal1 != somaDiagonal2)
    {
        return 0;
    }

    for (i = 0; i < n; i++)
    {
        int somaLinha = 0, somaColuna = 0;
        for (j = 0; j < n; j++)
        {
            somaLinha += matriz[i][j];
            somaColuna += matriz[j][i];
        }
        if (somaLinha != somaColuna || somaColuna != somaDiagonal1)
        {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    int **matriz;

    matriz = malloc(n * sizeof(int *));

    for (int i = 0; i < n; i++)
    {
        matriz[i] = malloc(n * sizeof(double));
    }
    printf("Digite os valores da matriz n x m:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matriz[i][j]);
        }
    }

    if (quadradoMagico(matriz, n) == 1)
    {
        printf("Esta matriz é um quadrado mágico!\n");
    }
    else
        printf("Esta matriz não é um quadrado mágico :(\n");
    return 0;
}