#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"


struct lista{
    float senha;
    struct lista *prox;
};

struct pilha{
    lista *prim;
};


pilha *criaPilha(){
    pilha *new = (pilha*)malloc(sizeof(pilha));
    new->prim = NULL;
    return new;
}

void push(pilha *p, float senha){
    lista *novo = (lista*)malloc(sizeof(lista));
    novo->prox = p->prim;
    novo->senha = senha;
    p->prim = novo;
}

int pilhaVazia(pilha *p){
return (p->prim == NULL);
}

void imprimePilha(pilha *p){
    if(!(pilhaVazia(p))){
        lista *aux;
        for(aux = p->prim ; aux != NULL ; aux = aux ->prox){
            printf("Senhas na pilha: %f\n", aux->senha);
        }
    }else{
        printf("Pilha está vazia");
    }
}