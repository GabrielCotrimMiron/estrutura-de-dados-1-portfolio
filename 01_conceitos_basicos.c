#include <stdio.h>

int main() {
    int quantidade, i = 1;
    int aprovados = 0;
    float nota, soma = 0, media;
    char continuar;

    printf("Quantos alunos deseja cadastrar? ");
    scanf("%d", &quantidade);

    while (i <= quantidade) {

        printf("\nAluno %d\n", i);
        printf("Digite a nota: ");
        scanf("%f", &nota);

        soma += nota;

        if (nota >= 7.0) {
            printf("Situacao: Aprovado\n");
            aprovados++;
        }
        else if (nota >= 5.0) {
            printf("Situacao: Recuperacao\n");
        }
        else {
            printf("Situacao: Reprovado\n");
        }

        i++;
    }

    media = soma / quantidade;

    printf("\n------------------------\n");
    printf("Media da turma: %.2f\n", media);
    printf("Aprovados: %d\n", aprovados);

    printf("\nNotas de referencia:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }

    printf("\n");

    do {
        printf("\nDeseja ver a media novamente? (S/N): ");
        scanf(" %c", &continuar);

        if (continuar == 'S' || continuar == 's') {
            printf("Media: %.2f\n", media);
        }

    } while (continuar == 'S' || continuar == 's');

    printf("\nPrograma encerrado.\n");

    return 0;
}
