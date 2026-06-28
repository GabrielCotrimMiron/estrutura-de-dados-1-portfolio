#include <stdio.h>

typedef struct {
    char nome[50];
    int idade;
    float nota;
} Aluno;

void exibirAluno(Aluno a) {
    printf("\nNome: %s\n", a.nome);
    printf("Idade: %d\n", a.idade);
    printf("Nota: %.2f\n", a.nota);
}

void bonusNota(Aluno *a) {
    a->nota += 1.0;

    if (a->nota > 10.0)
        a->nota = 10.0;
}

int main() {

    Aluno turma[3];
    float soma = 0;

    for (int i = 0; i < 3; i++) {

        printf("\nAluno %d\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", turma[i].nome);

        printf("Idade: ");
        scanf("%d", &turma[i].idade);

        printf("Nota: ");
        scanf("%f", &turma[i].nota);

        soma += turma[i].nota;
    }

    printf("\n===== ALUNOS =====\n");

    for (int i = 0; i < 3; i++) {
        bonusNota(&turma[i]);
        exibirAluno(turma[i]);
    }

    printf("\nMedia da turma: %.2f\n", soma / 3);

    return 0;
}
