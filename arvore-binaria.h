#include <stdio.h>
#include <stdlib.h>

typedef struct noA {
    char info;
    struct noA *esq;
    struct noA *dir;
} TNoA;

typedef struct lista {
    TNoA *info;
    struct lista *prox;
} TLista;

typedef struct pilha{
    TLista *topo;
} TPilha;

TNoA *inicializa(void) {
    return NULL;
}

TPilha *inicializaPilha() {
    TPilha *pilha = (TPilha *)malloc(sizeof(TPilha));
    pilha->topo = NULL;
    return pilha;
}

void liberaPilha(TPilha *p) {
    TLista *q = p->topo;
    TLista *r;
    while(q != NULL){
        r = q;
        q=q->prox;
        free(r);
    }
    free(p);
}

int pilha_vazia(TPilha *pilha) {
      if (pilha->topo == NULL)
      return 1; //pilha vazia
      else
      return 0; //pilha tem pelo menos 1 elemento
}

void push(TPilha *pilha, TNoA* elem) {
    TLista *novo = (TLista*) malloc(sizeof(TLista));
    novo->info = elem;
    novo->prox = pilha->topo;
    pilha->topo = novo;
}


TNoA* pop(TPilha *pilha) {
if(pilha->topo == NULL){
        exit(1);
    } else {
        TPilha *aux = pilha;
        TNoA* valor = pilha->topo->info;
        pilha->topo = pilha->topo->prox;
        free(aux);
        return valor;
    }
}

void imprime(TNoA *nodo, int tab) {
    for (int i = 0; i < tab; i++) {
        printf("-");
    }
    if (nodo != NULL) {
        printf("%c\n", nodo->info);
        imprime(nodo->esq, tab + 2);
        printf("\n");
        imprime(nodo->dir, tab + 2);
    } else printf("vazio");
}

TNoA *criaNo(char ch) {
    TNoA *novo;
    novo = (TNoA *) malloc(sizeof(TNoA));
    novo->info = ch;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}

void caminho_profundidade_pilha(TNoA *raiz){

    if(raiz == NULL) return;

    TPilha *p = inicializaPilha();

    push(p, raiz);

    while(!pilha_vazia(p)){

        TNoA *noAtual = pop(p);
        printf("%c ", noAtual->info);

        if(noAtual->dir != NULL){
            push(p, noAtual);
        }
        if(noAtual->esq != NULL){
            push(p, noAtual->esq);
        }
    }

    liberaPilha(p);
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);
};
