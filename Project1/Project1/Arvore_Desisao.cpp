#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <math.h>
#include <string.h>
#include "Arvore_Decisao.h"



void criaArvore(char* pathTeste, char* pathTreino, int tam) {
	std::vector<Opcoes> opt;
	opt = leArq(pathTreino, tam);

	std::vector<TipoAtributo> tipo;
	tipo = contaPosNeg(opt);

	Arvore *a = new Arvore;
	recursiva(tipo, a);

}

std::vector<TipoAtributo> contaPosNeg(std::vector<Opcoes> v) {
	std::vector<TipoAtributo> tipo;
	tipo.reserve(27);

	for (int j = 0; j < 9; j++) {
		TipoAtributo temp;
		temp.qtd.positivo = 0;
		temp.qtd.negativo = 0;
		temp.letra = 'x';
		tipo.push_back(temp);
		temp.letra = 'o';
		tipo.push_back(temp);
		temp.letra = 'b';
		tipo.push_back(temp);
	}
	for (int i = 0; i < 27; i++) {
		if(i < 3)
			strcpy(tipo[i].posicao, "tl");
		else if(i < 6)
			strcpy(tipo[i].posicao, "tm");
		else if (i < 9)
			strcpy(tipo[i].posicao, "tr");
		else if (i < 12)
			strcpy(tipo[i].posicao, "ml");
		else if (i < 15)
			strcpy(tipo[i].posicao, "mm");
		else if (i < 18)
			strcpy(tipo[i].posicao, "mr");
		else if (i < 21)
			strcpy(tipo[i].posicao, "bl");
		else if (i < 24)
			strcpy(tipo[i].posicao, "bm");
		else
			strcpy(tipo[i].posicao, "br");
	}

	for (int i = 0; i < v.size(); i++){
		char atributos[9];
		atributos[0] = v[i].tl; atributos[1] = v[i].tm; atributos[2] = v[i].tr;
		atributos[3] = v[i].ml; atributos[4] = v[i].mm; atributos[5] = v[i].mr;
		atributos[6] = v[i].bl; atributos[7] = v[i].bm; atributos[8] = v[i].br;

		if (strcmp(v[i].classe, "positive") == 0) {
			for (int j = 0; j < 9; j++) {
				if (atributos[j] == 'x')
					tipo[3*j].qtd.positivo++;
				else if (atributos[j] == 'o')
					tipo[3*j + 1].qtd.positivo++;
				else 
					tipo[3*j + 2].qtd.positivo++;
			}
		}
		else{
			for (int j = 0; j < 9; j++) {
				if (atributos[j] == 'x')
					tipo[3 * j].qtd.negativo++;
				else if (atributos[j] == 'o')
					tipo[3 * j + 1].qtd.negativo++;
				else
					tipo[3 * j + 2].qtd.negativo++;
			}
		}

	}
	return tipo;
}

float calculaGanho(TipoAtributo tipo1, TipoAtributo tipo2, TipoAtributo tipo3) {
	int opt1Pos, opt1Neg, opt2Pos, opt2Neg, opt3Pos, opt3Neg;
	int totalPos, totalNeg;
	float total, entAtual, entOpt1, entOpt2, entOpt3, info, info1, info2, info3;

	opt1Pos = tipo1.qtd.positivo; opt1Neg = tipo1.qtd.negativo;
	opt2Pos = tipo2.qtd.positivo; opt2Neg = tipo2.qtd.negativo;
	opt3Pos = tipo3.qtd.positivo; opt3Neg = tipo3.qtd.negativo;

	totalPos = opt1Pos + opt2Pos + opt3Pos;
	totalNeg = opt1Neg + opt2Neg + opt3Neg;
	total = totalPos + totalNeg;

	entAtual = calculaEntropia(totalPos, totalNeg);

	info1 = ((opt1Pos + opt1Neg) / total)*calculaEntropia(opt1Pos, opt1Neg);
	info2 = ((opt2Pos + opt2Neg) / total)*calculaEntropia(opt2Pos, opt2Neg);
	info3 = ((opt3Pos + opt3Neg) / total)*calculaEntropia(opt3Pos, opt3Neg);
	info = info1 + info2 + info3;
	return entAtual - info;
}

float calculaEntropia(int qtdPos, int qtdNeg) {
	float total = qtdPos + qtdNeg;
	float percPos, percNeg;

	if (qtdPos == 0 || qtdNeg == 0)
		return 0;

	percPos = qtdPos / total;
	percNeg = qtdNeg / total;

	return (-percPos)*log2f(percPos) + (-percNeg)*log2f(percNeg);
}

void recursiva(std::vector<TipoAtributo> tipo, Arvore *arv) {
	int pos = 0;
	float melhor = calculaGanho(tipo[0], tipo[1], tipo[2]);
	
	for (int i = 1; i < tipo.size()/3; i++) {
		float teste = calculaGanho(tipo[i*3], tipo[i*3 + 1], tipo[i*3 + 2]);

		if (teste > melhor) {
			melhor = teste;
			pos = i;
		}
	}
	printf("Melhor:%f\tPosicao:%d\n", melhor, pos);
	if (melhor > 0) {
		//Coloca maior na arvore
		strcpy(arv->posicao, tipo[pos].posicao);
		arv->x = new Arvore;
		arv->o = new Arvore;
		arv->b = new Arvore;
		printf("Melhor:%s\n", arv->posicao);

		tipo.erase(tipo.begin() + pos);
		tipo.erase(tipo.begin() + pos);
		tipo.erase(tipo.begin() + pos);

		if (tipo.size() > 0) {
			recursiva(tipo, arv->x);
			recursiva(tipo, arv->o);
			recursiva(tipo, arv->b);
		}
		else
			return;
	}
	else
		return;
}