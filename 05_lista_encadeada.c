#include <stdio.h>
#include <stdlib.h>

typedef struct lista{
    int info;
    struct lista *prox;
}Lista;

Lista* inicializa(){
    return NULL;
}

Lista* insere(Lista *l, int valor){

    Lista *novo = (Lista*) malloc(sizeof(Lista));

    novo->info = valor;
    novo->prox = l;

    return novo;
}

void imprime(Lista *l){

    Lista *p;

    for(p = l; p != NULL; p = p->prox){
        printf("%d -> ", p->info);
    }

    printf("NULL\n");
}

Lista* busca(Lista *l, int valor){

    Lista *p;

    for(p = l; p != NULL; p = p->prox){

        if(p->info == valor){
            return p;
        }

    }

    return NULL;
}

Lista* remove_ultimo(Lista *l){

    if(l == NULL){
        return NULL;
    }

    if(l->prox == NULL){
        free(l);
        return NULL;
    }

    Lista *p = l;

    while(p->prox->prox != NULL){
        p = p->prox;
    }

    free(p->prox);
    p->prox = NULL;

    return l;
}

void libera(Lista *l){

    Lista *p = l;

    while(p != NULL){

        Lista *temp = p->prox;

        free(p);

        p = temp;
    }

}

int main(){

    Lista *l = inicializa();

    int valor;

    for(int i=0;i<5;i++){

        printf("Digite um numero: ");
        scanf("%d",&valor);

        l = insere(l,valor);

    }

    printf("\nLista:\n");
    imprime(l);

    printf("\nNumero para buscar: ");
    scanf("%d",&valor);

    Lista *resultado = busca(l,valor);

    if(resultado != NULL)
        printf("Encontrado!\n");
    else
        printf("Nao encontrado.\n");

    l = remove_ultimo(l);

    printf("\nLista apos remover o ultimo:\n");
    imprime(l);

    libera(l);

    return 0;
}
