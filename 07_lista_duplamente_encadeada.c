/*
---------------------------------------------------------
Portfólio - Estrutura de Dados I

Curso: Engenharia de Software
Aluno: Gabriel Cotrim Miron

Arquivo: 07_lista_duplamente_encadeada.c

Conteúdo:
- Lista duplamente encadeada
- Inserção
- Percurso direto
- Percurso reverso

Descrição:
Implementação de lista duplamente encadeada em linguagem C.

---------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct lista {
    int info;
    struct lista *ant;
    struct lista *prox;
} Lista;

Lista* criarNo(int valor) {

    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->info = valor;
    novo->ant = NULL;
    novo->prox = NULL;

    return novo;
}

Lista* inserirInicio(Lista *l, int valor) {

    Lista *novo = criarNo(valor);

    novo->prox = l;

    if (l != NULL) {
        l->ant = novo;
    }

    return novo;
}

Lista* inserirFinal(Lista *l, int valor) {

    Lista *novo = criarNo(valor);

    if (l == NULL) {
        return novo;
    }

    Lista *p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }

    p->prox = novo;
    novo->ant = p;

    return l;
}

void imprimir(Lista *l) {

    Lista *p = l;

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->prox;
    }

    printf("\n");
}

void imprimirReverso(Lista *l) {

    if (l == NULL)
        return;

    Lista *p = l;

    while (p->prox != NULL) {
        p = p->prox;
    }

    while (p != NULL) {
        printf("%d ", p->info);
        p = p->ant;
    }

    printf("\n");
}

int main() {

    Lista *l = NULL;

    l = inserirInicio(l, 20);
    l = inserirInicio(l, 10);

    l = inserirFinal(l, 30);
    l = inserirFinal(l, 40);

    printf("Lista:\n");
    imprimir(l);

    printf("Lista reversa:\n");
    imprimirReverso(l);

    return 0;
}
