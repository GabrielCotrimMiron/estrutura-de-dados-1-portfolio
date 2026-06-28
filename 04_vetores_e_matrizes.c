#include <stdio.h>

int main() {

    int vetor[5];
    int matriz[2][2];
    int somaVetor = 0;
    int somaMatriz = 0;

    printf("=== VETOR ===\n");

    for (int i = 0; i < 5; i++) {
        printf("Digite o %dº numero: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nElementos do vetor:\n");

    for (int i = 0; i < 5; i++) {
        printf("vetor[%d] = %d\n", i, vetor[i]);
        somaVetor += vetor[i];
    }

    printf("Soma do vetor: %d\n", somaVetor);

    printf("\n=========================\n");
    printf("=== MATRIZ 2x2 ===\n");

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {

            printf("Digite o valor da posicao [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);

        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < 2; i++) {

        for (int j = 0; j < 2; j++) {

            printf("%d ", matriz[i][j]);
            somaMatriz += matriz[i][j];

        }

        printf("\n");
    }

    printf("\nSoma da matriz: %d\n", somaMatriz);

    return 0;
}
