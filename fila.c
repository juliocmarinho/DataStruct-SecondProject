#include <stdlib.h>
#include <stdio.h>
#include "fila.h"

struct lista{

    int senha;
    struct lista *prox;

};


struct fila{

    lista *inicio;
    lista *fim;
    int tam;

};

fila* criaFila(){
    fila *new = (fila*)malloc(sizeof(fila));
    new->fim = NULL;
    new->inicio = NULL;
    new->tam = 0;
    return new;

}

void insere(fila *fila, int senha){
    lista *novo = (lista*)malloc(sizeof(lista));
    novo->senha = senha;
    novo->prox = NULL;
    fila->tam++;
    if(fila->tam > 10){
        printf("Fila cheia!.");
        exit(1);
    }
    if(fila->fim != NULL){
        fila->fim->prox = novo;
    }else{
        fila->inicio = novo;
    }
    fila->fim = novo;
}

float removee(fila *fila){
    lista *t;
    float valor;
    if(filaVazia(fila)){
        printf("Fila Vazia!\n");
        exit(1);
    }
    t = fila->inicio;
    valor = t->senha;
    fila->inicio = t->prox;
    if(fila->inicio == NULL){
        fila->fim = NULL;
    }
    free(t);
    return valor;
}

int filaVazia(fila* fila){
    return (fila->inicio == NULL);
}

void imprime(fila *fila){
    lista *aux;
    for(aux = fila->inicio ; aux != NULL ; aux = aux ->prox){
        printf("o valor eh %d \n", aux->senha);
    }
}