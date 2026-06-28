#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inserirFinal(Lista *l, int valor){

    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->info = valor;

    if(l == NULL){

        novo->prox = novo;
        return novo;

    }

    Lista *p = l;

    while(p->prox != l){
        p = p->prox;
    }

    p->prox = novo;
    novo->prox = l;

    return l;
}

void imprime(Lista *l){

    if(l == NULL){
        return;
    }

    Lista *p = l;

    do{

        printf("%d -> ",p->info);

        p = p->prox;

    }while(p != l);

    printf("(volta ao inicio)\n");
}

int main(){

    Lista *l = NULL;

    int valor;

    for(int i=0;i<5;i++){

        printf("Digite um numero: ");
        scanf("%d",&valor);

        l = inserirFinal(l,valor);

    }

    printf("\nLista Circular:\n");

    imprime(l);

    return 0;
}
