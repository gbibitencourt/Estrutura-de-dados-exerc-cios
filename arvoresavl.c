#include <stdio.h>
#include <stdlib.h>

typedef struct sNoAVL {
	int chave;
	int fb;
	struct sNoAVL *esq;
	struct sNoAVL *dir;
} TNoAVL;

void imprime(TNoAVL *no, int tab) {
	for (int i = 0; i < tab; i++) {
		printf("-");
	}
	if (no != NULL) {
		printf("%d (fb = %d)\n", no->chave, no->fb);
		imprime(no->esq, tab + 2);
		printf("\n");
		imprime(no->dir, tab + 2);
	} else printf("vazio");
}

TNoAVL *rotacao_direita(TNoAVL *p) {
	//Faz rota��o de p para direita e retorna ponteiro para a nova raiz da sub�rvore afetada
    TNoAVL *aux;
    aux = p->esq;
    p->esq = aux->dir;
    aux->dir = p;
    p->fb = 0;
    p = aux;
    return p;
}

TNoAVL *rotacao_esquerda(TNoAVL *p) {
	//Faz rota��o de p para esquerda e retorna ponteiro para a nova raiz da sub�rvore afetada

	/*FAZER CODIGO AQUI*/

}

TNoAVL *rotacao_dupla_direita(TNoAVL *p) {

	/*FAZER CODIGO AQUI*/

}

TNoAVL *rotacao_dupla_esquerda(TNoAVL *p) {

	/*FAZER CODIGO AQUI*/

}

TNoAVL *caso1(TNoAVL *p) {
	//chave foi inserida � esquerda de p e causou fb = -2
	//verificar se a rotacao eh simples ou dupla

	/*FAZER CODIGO AQUI*/

}

TNoAVL *caso2(TNoAVL *p) {
	//chave foi inserida � direita de p e causou fb = 2
	//verificar se a rotacao eh simples ou dupla

	/*FAZER CODIGO AQUI*/

}

TNoAVL *insere(TNoAVL *p, int chave, int *flag) {
	/* Insere no em uma �rvore AVL, onde p representa a raiz da �rvore,
	chave, a chave a ser inserida e flag � um booleano que indica se � necess�rio propagar opera��o de c�lculo de fb */
	if (p == NULL) {
		p = (TNoAVL *) malloc(sizeof(TNoAVL));
		p->chave = chave;
		p->esq = NULL;
		p->dir = NULL;
		p->fb = 0;
		*flag = 1;
		printf("\nInseriu %d", p->chave);

	} else if (chave < p->chave) { //recurs�o � esquerda
		p->esq = insere(p->esq, chave, flag);
		if (*flag) { //inseriu: verificar balanceamento
			switch (p->fb) {
				case -1: /* fb(pt) = -2 */
					p = caso1(p);
					*flag = 0; //n�o propaga mais
					break;
				case 0:
					p->fb = -1; //ficou maior � esquerda
					break;
				case 1:
					p->fb = 0; // balanceou com inser��o
					*flag = 0; // n�o propaga mais
					break;
			}
		}
	} else if (chave > p->chave) { //recurs�o � direita
		p->dir = insere(p->dir, chave, flag);
		if (*flag) {
			switch (p->fb) {
				case 1: //fb(pt) = 2 e p retorna balanceado
					p = caso2(p);
					*flag = 0; //n�o propaga mais
					break;
				case 0:
					p->fb = 1;
					break;
				case -1: //era mais alto � esquerda, zera fb
					p->fb = 0;
					*flag = 0; //n�o propaga mais
					break;
			}
		}
	}
	//else if (chave == pt->chave) ==> nada a fazer!
	return p;
}


int main() {
	TNoAVL *raiz;
	raiz = NULL;
	int ok;
	//arvore do exerc�cio de inser��o feito em aula
	raiz = insere(raiz, 50, &ok);
	raiz = insere(raiz, 40, &ok);
	raiz = insere(raiz, 30, &ok);
	raiz = insere(raiz, 55, &ok);
	raiz = insere(raiz, 60, &ok);
	raiz = insere(raiz, 57, &ok);
	raiz = insere(raiz, 58, &ok);
	raiz = insere(raiz, 52, &ok);
	raiz = insere(raiz, 51, &ok);
	printf("\n");
	imprime(raiz, 0);
	printf("\n\n\n\n");
}
