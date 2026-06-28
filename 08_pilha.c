#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int info;
    struct no *prox;
} No;

typedef struct pilha {
    No *topo;
} Pilha;

Pilha* cria() {

    Pilha *nova = (Pilha*) malloc(sizeof(Pilha));

    nova->topo = NULL;

    return nova;
}

int vazia(Pilha *p) {
    return p->topo == NULL;
}

void push(Pilha *p, int valor) {

    No *novo = (No*) malloc(sizeof(No));

    if (novo != NULL) {

        novo->info = valor;
        novo->prox = p->topo;
        p->topo = novo;

    } else {

        printf("Erro ao alocar memoria.\n");

    }
}

int pop(Pilha *p) {

    if (vazia(p)) {

        printf("Pilha vazia.\n");
        return -1;

    }

    No *aux = p->topo;

    int valor = aux->info;

    p->topo = aux->prox;

    free(aux);

    return valor;
}

void imprimir(Pilha *p) {

    No *aux = p->topo;

    while (aux != NULL) {

        printf("[%d]\n", aux->info);

        aux = aux->prox;
    }
}

int main() {

    Pilha *p = cria();

    push(p, 4);
    push(p, 3);
    push(p, 2);

    printf("Pilha:\n");
    imprimir(p);

    printf("\nValor removido: %d\n", pop(p));

    printf("\nPilha apos o pop:\n");
    imprimir(p);

    return 0;
}
