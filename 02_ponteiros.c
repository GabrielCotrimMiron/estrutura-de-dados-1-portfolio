/*
---------------------------------------------------------
Portfólio - Estrutura de Dados I

Curso: Engenharia de Software
Aluno: Gabriel Cotrim Miron

Arquivo: 02_ponteiros.c

Conteúdo:
- Ponteiros
- Endereçamento
- Desreferenciação
- Passagem por referência

Descrição:
Exemplo demonstrando o uso de ponteiros em linguagem C.

---------------------------------------------------------
*/

#include <stdio.h>

void troca(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 10;
    int y = 20;
    int *p;

    p = &x;

    printf("Valor de x: %d\n", x);
    printf("Endereco de x: %p\n", &x);
    printf("Valor armazenado em p: %p\n", p);
    printf("Valor apontado por p: %d\n\n", *p);

    *p = 50;

    printf("Novo valor de x: %d\n\n", x);

    int vetor[5] = {2, 4, 6, 8, 10};

    p = vetor;

    printf("Elementos do vetor usando ponteiros:\n");

    for (int i = 0; i < 5; i++) {
        printf("vetor[%d] = %d\n", i, *(p + i));
    }

    printf("\nAntes da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    troca(&x, &y);

    printf("\nDepois da troca:\n");
    printf("x = %d\n", x);
    printf("y = %d\n", y);

    return 0;
}
