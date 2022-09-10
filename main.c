//Davi Baechtold Campos - PEDA - Arvores 

#include <stdio.h>
#include <stdlib.h>

struct Item {
  struct Item *esquerda;
  int valor;
  struct Item *direita;
};

struct Item *novoItem(int valor) {
  struct Item *Item = (struct Item *)malloc(sizeof(struct Item));
  Item->esquerda = NULL;
  Item->valor = valor;
  Item->direita = NULL;

  return Item;
}
void PreOrder(struct Item *raiz) {
  if (raiz == NULL)
    return;

  printf("%d ", raiz->valor);
  PreOrder(raiz->esquerda);
  PreOrder(raiz->direita);
}

void InOrder(struct Item *raiz) {
  if (raiz == NULL)
    return;

  InOrder(raiz->esquerda);
  printf("%d ", raiz->valor);
  InOrder(raiz->direita);
}

void PostOrder(struct Item *raiz) {
  if (raiz == NULL)
    return;

  PostOrder(raiz->esquerda);
  PostOrder(raiz->direita);
  printf("%d ", raiz->valor);
}

struct Item *insereArvore(struct Item *raiz, int valor) {
  if (raiz == NULL)
    raiz = novoItem(valor);

  else if (valor <= raiz->valor)
    raiz->esquerda = insereArvore(raiz->esquerda, valor);

  else
    raiz->direita = insereArvore(raiz->direita, valor);

  return raiz;
}

void transversal(struct Item *raiz) {
  printf("\n\nPreOrder:\t");
  PreOrder(raiz);
  
  printf("\n\nInorder:\t");
  InOrder(raiz);
  
  printf("\n\nPostOrder:\t");
  PostOrder(raiz);
}

int main() {
  struct Item *raiz = NULL;
  int aleatorio = rand() % 17 + 10;
  if (aleatorio < 120)
    aleatorio = 10;
  int arrayVertices[aleatorio];

  printf("\nArray de Vertices:\n [");
  for (int i = 0; i <= aleatorio; i++) {
    int numAleatorio = rand() % 1000000;
    arrayVertices[i] = numAleatorio;
    printf("%d, ", arrayVertices[i]);
    raiz = insereArvore(raiz, numAleatorio);
  }
  printf("]\n");
  transversal(raiz);
  

  return 0;
}