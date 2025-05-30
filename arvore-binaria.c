#include "arvore-binaria.h"

TNoA *inicializa(void) {
    return NULL;
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

void *profundidade_recursivo(TNoA *a){
    if(a != NULL){
        printf("%c\n", a->info);
        profundidade_recursivo(a->esq);
        profundidade_recursivo(a->dir);
    }
}

void *simetrico_recursivo(TNoA *a){
    if(a!= NULL){
        simetrico_recursivo(a->esq);
        printf("%c\n", a->info);
        simetrico_recursivo(a->dir);
    }
}
void *posordem_recursivo(TNoA *a){
    if(a != NULL){
        posordem_recursivo(a->esq);
        posordem_recursivo(a->dir);
        printf("%c\n", a->info);
    }
}
int qnt_nos(TNoA *a){
    if (a == NULL){
        return 0;
    }
    else{
        return 1 + qnt_nos(a->esq) + qnt_nos(a->dir);
    }
}
TNoA *largura_fila(TNoA *a){
    if(a == NULL){
        return;
    }
    TFila *fila = inicializa();
    insere(fila, (int)(a));
    while(!fila_vazia(fila)){
        TNoA *atual = (TNoA*) retira(fila);
        printf("%c\n", atual->info);
        if(atual->esq != NULL){
            insere(fila, (int)(atual->esq));
        }
        if(atual->dir != NULL){
            insere(fila, (int)(atual->dir));
        }
   }
   libera(fila);
}
TNoA *profundidade_pilha(TNoA *a){
    if(a == NULL){return;}
    TPilha *pilha = inicializa_pilha();
    TPilha *aux = inicializa();
    push(aux, (int)(a))
    while(!pilha_vazia(aux)){
        TNoA *atual = (TNoA*) pop(aux);
        push(pilha, atual->info);
        if(atual->esq != NULL){
            push(aux, (int) (atual->esq));
        }
        if(atual->dir != NULL){
            push(aux, (int)(atual->dir));
        }
    }
    while(!pilha_vazia(pilha)){
        int valor = pop(pilha);
        printf("%c\n", valor);
    }
    libera_pilha(pilha);
}

int main(void) {
    TNoA *raiz;
    raiz = criaNo('A');
    raiz->esq = criaNo('B');
    raiz->dir = criaNo('C');
    raiz->dir->esq = criaNo('D');
    raiz->dir->dir = criaNo('E');
    imprime(raiz, 0);

    printf("Árvore impressa em profundidade:\n");
    profundidade_recursivo(raiz);
    printf("Árvore impressa em simetria:\n");
    simetrico_recursivo(raiz);
    printf("Árvore impressa em pós ordem:\n");
    posordem_recursivo(raiz);

    printf("Quantidade de nós na árvore: %d\n", qnt_nos(raiz));

    printf("Percurso em profundidade com pilha:\n");
    profundidade_pilha(raiz);

    printf("Percurso em largura com fila:\n");
    largura_fila(raiz);
};
