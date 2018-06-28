#pragma once
#include <vector>
#include "openFile.h"

typedef struct qtdAtributo {
	int positivo;
	int negativo;
}QtdAtributo;

typedef struct tipoAtributo {
	char letra;
	char posicao[3];
	QtdAtributo qtd;
}TipoAtributo;

typedef struct arvore Arvore;
struct arvore {
	char posicao[3];
	Arvore *x;
	Arvore *o;
	Arvore *b;
};


Arvore* criaArvore(char* pathTreino, int tam);

void testaArvore(char* pathTeste, int tam, Arvore *arv);

void recTestaArvore(std::vector<Opcoes> opt, Arvore *arv);

float calculaEntropia(int qtdPos, int qtdNeg);

std::vector<TipoAtributo> contaPosNeg(std::vector<Opcoes> v);

void recursiva(std::vector<Opcoes> opt, Arvore *arv);

void show_rec(Arvore* arv);