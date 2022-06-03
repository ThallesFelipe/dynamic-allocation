// NOME: Thalles Felipe Rodrigues de Almeida Santos
// TURMA: 32
// MATRÍCULA: 21.2.4130

#include <stdio.h>
#include <stdlib.h>

float mediaValores(int n, int *vet1)
{
    printf("Digite os valores do vetor: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &vet1[i]);
    }

    float media;
    int soma = 0;

    for (int i = 0; i < n; i++)
    {
        soma += vet1[i];
    }

    media = soma / n;

    return media;
    free(vet1);
}

int main(int argc, char const *argv[])
{
    int n, *vet1, acima = 0, abaixo = 0, cimaIndex = 0, baixoIndex = 0, *vetorAcima, *vetorAbaixo;
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    vet1 = malloc(n * sizeof(int));

    float media = mediaValores(n, vet1);

    for (int i = 0; i < n; i++)
    {
        if (vet1[i] >= media)
        {
            acima++;
        }
        else
            abaixo++;
    }

    vetorAcima = malloc(acima * sizeof(int));
    vetorAbaixo = malloc(abaixo * sizeof(int));

    for (int i = 0; i < n; i++)
    {
        if (vet1[i] >= media)
        {
            vetorAcima[cimaIndex] = vet1[i];
            cimaIndex++;
        }
        else if (vet1[i] < media)
        {
            vetorAbaixo[baixoIndex] = vet1[i];
            baixoIndex++;
        }
    }

    printf("A média é: %.0lf\n", media);

    printf("Vetor com valores abaixo da média: [ ");
    for (int i = 0; i < abaixo; i++)
    {
        printf("%d ", vetorAbaixo[i]);
    }
    printf("]\n");

    printf("Vetor com valores iguais ou acima da média: [ ");
    for (int i = 0; i < acima; i++)
    {
        printf("%d ", vetorAcima[i]);
    }
    printf("]");
    free(vetorAbaixo);
    free(vetorAcima);
    free(vet1);
    return 0;
}