/*
---------------------------------------------------------
Portfólio - Estrutura de Dados I

Curso: Engenharia de Software
Aluno: Gabriel Cotrim Miron

Arquivo: 09_fila.c

Conteúdo:
- Fila (Queue)
- Enqueue
- Dequeue
- Impressão
- Verificação de fila vazia

Descrição:
Implementação de uma fila utilizando vetor.

---------------------------------------------------------
*/

#include <stdio.h>

#define MAX 5

typedef struct {
    int dados[MAX];
    int frente;
    int fim;
} Fila;

void inicializar(Fila *f) {
    f->frente = 0;
    f->fim = -1;
}

int filaVazia(Fila *f) {
    return f->fim < f->frente;
}

void enqueue(Fila *f, int valor) {

    if (f->fim == MAX - 1) {
        printf("Fila cheia!\n");
        return;
    }

    f->fim++;
    f->dados[f->fim] = valor;
}

int dequeue(Fila *f) {

    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    return f->dados[f->frente++];
}

void mostrar(Fila *f) {

    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return;
    }

    for (int i = f->frente; i <= f->fim; i++) {
        printf("%d ", f->dados[i]);
    }

    printf("\n");
}

int main() {

    Fila fila;

    inicializar(&fila);

    enqueue(&fila, 10);
    enqueue(&fila, 20);
    enqueue(&fila, 30);
    enqueue(&fila, 40);

    printf("Fila:\n");
    mostrar(&fila);

    printf("\nRemovido: %d\n", dequeue(&fila));

    printf("\nFila apos remover:\n");
    mostrar(&fila);

    enqueue(&fila, 50);

    printf("\nFila final:\n");
    mostrar(&fila);

    return 0;
}
