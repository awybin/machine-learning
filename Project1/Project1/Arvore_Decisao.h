#pragma once
#include <vector>
#include "openFile.h"

typedef struct qtdAtributo {
	int positivo;
	int negativo;
}QtdAtributo;

typedef struct tipoAtributo {
	char letra;
	char posicao[2];
	QtdAtributo qtd;
}TipoAtributo;

typedef struct arvore Arvore;
struct arvore {
	char *posicao;
	Arvore *x;
	Arvore *o;
	Arvore *b;
};


void criaArvore(char* pathTeste, char* pathTreino, int tam);

float calculaEntropia(int qtdPos, int qtdNeg);

std::vector<TipoAtributo> contaPosNeg(std::vector<Opcoes> v);

void recursiva(std::vector<TipoAtributo> tipo, Arvore* arv);