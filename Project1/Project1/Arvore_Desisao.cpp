#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <math.h>
#include <stdlib.h> 
#include <string.h>
#include <time.h>
#include "Arvore_Decisao.h"

Arvore* novaArvore(void) {
	Arvore *arv = new Arvore();

	arv->x = nullptr;
	arv->o = nullptr;
	arv->b = nullptr;
	strcpy(arv->posicao, "");

	return arv;
}

Arvore* criaArvore(char* pathTreino, int tam) {
	std::vector<Opcoes> opt;
	opt = leArq(pathTreino, tam);

	clock_t Ticks[2];
	Ticks[0] = clock();

	Arvore *a = novaArvore();
	recursiva(opt, a);

	Ticks[1] = clock();
	float Tempo = (Ticks[1] - Ticks[0]) / (float)CLOCKS_PER_SEC;
	printf("\nTempo gasto com treinamento: %.2f s.\n", Tempo);

	//show_rec(a);
	return a;
}

void testaArvore(char* pathTeste, char* pathResultado, int tam, Arvore *arv) {
	std::vector<Opcoes> opt;
	opt = leArq(pathTeste, tam);

	std::vector<int> resultado;
	resultado.reserve(tam);

	clock_t Ticks[2];
	Ticks[0] = clock();

	for (int i = 0; i < opt.size(); i++) {
		resultado.push_back(recTestaArvore(opt, arv, i));
	}

	Ticks[1] = clock();
	float Tempo = (Ticks[1] - Ticks[0]) / (float)CLOCKS_PER_SEC;
	printf("\nTempo gasto com testes: %.2f s.\n", Tempo);

	geraArqRes(pathResultado, resultado);
}
int recTestaArvore(std::vector<Opcoes> opt, Arvore *arv, int i) {
	if (strcmp(arv->posicao, "positive")  == 0)
		return 1;
	else if (strcmp(arv->posicao, "negative") == 0)
		return 0;

	if (strcmp(arv->posicao, "tl") == 0) {
		if (opt[i].tl == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].tl == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "tm") == 0) {
		if (opt[i].tm == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].tm == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "tr") == 0) {
		if (opt[i].tr == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].tr == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "ml") == 0) {
		if (opt[i].ml == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].ml == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "mm") == 0) {
		if (opt[i].mm == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].mm == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "mr") == 0) {
		if (opt[i].mr == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].mr == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "bl") == 0) {
		if (opt[i].bl == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].bl == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "bm") == 0) {
		if (opt[i].bm == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].bm == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}
	else if (strcmp(arv->posicao, "br") == 0) {
		if (opt[i].br == 'x') {
			Arvore *temp = arv->x;
			return recTestaArvore(opt, temp, i);
		}
		else if (opt[i].br == 'o') {
			Arvore *temp = arv->o;
			return recTestaArvore(opt, temp, i);
		}
		else {
			Arvore *temp = arv->b;
			return recTestaArvore(opt, temp, i);
		}
	}

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
		if (i < 3)
			strcpy(tipo[i].posicao, "tl");
		else if (i < 6)
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

	for (int i = 0; i < v.size(); i++) {
		char atributos[9];
		atributos[0] = v[i].tl; atributos[1] = v[i].tm; atributos[2] = v[i].tr;
		atributos[3] = v[i].ml; atributos[4] = v[i].mm; atributos[5] = v[i].mr;
		atributos[6] = v[i].bl; atributos[7] = v[i].bm; atributos[8] = v[i].br;

		if (strcmp(v[i].classe, "positive") == 0) {
			for (int j = 0; j < 9; j++) {
				if (atributos[j] == 'x')
					tipo[3 * j].qtd.positivo++;
				else if (atributos[j] == 'o')
					tipo[3 * j + 1].qtd.positivo++;
				else
					tipo[3 * j + 2].qtd.positivo++;
			}
		}
		else {
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
	float total, entAtual, entOpt1, entOpt2, entOpt3, info, info1, info2, info3, ganho;

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

std::vector<Opcoes> removeOpcoes(std::vector<Opcoes> opt, char letra, char* posicao) {

	for (int i = 0; i < opt.size(); i++) {


		if (strcmp(posicao, "tl") == 0) {
			if (opt[i].tl != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "tm") == 0) {
			if (opt[i].tm != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "tr") == 0) {
			if (opt[i].tr != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "ml") == 0) {
			if (opt[i].ml != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "mm") == 0) {
			if (opt[i].mm != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "mr") == 0) {
			if (opt[i].mr != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "bl") == 0) {
			if (opt[i].bl != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "bm") == 0) {
			if (opt[i].bm != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
		else if (strcmp(posicao, "br") == 0) {
			if (opt[i].br != letra) {
				opt.erase(opt.begin() + i);
				i--;
			}
		}
	}

	return opt;
}

void recursiva(std::vector<Opcoes> opt, Arvore *arv) {
	std::vector<TipoAtributo> tipo;
	tipo = contaPosNeg(opt);
	if (opt.size() < 200)
		int oi = opt.size();
	float melhor = calculaGanho(tipo[0], tipo[1], tipo[2]);
	int pos = 0;

	for (int i = 1; i < tipo.size() / 3; i++) {
		float teste = calculaGanho(tipo[i * 3], tipo[i * 3 + 1], tipo[i * 3 + 2]);

		if (teste > melhor) {
			melhor = teste;
			pos = i * 3;
		}
	}
	//printf("Melhor:%f\tPosicao:%s\n", melhor, tipo[pos].posicao);
	if (melhor > 0) {
		//Coloca melhor na arvore

		strcpy(arv->posicao, tipo[pos].posicao);
		arv->x = novaArvore();
		arv->o = novaArvore();
		arv->b = novaArvore();

		std::vector<Opcoes> copy;
		std::vector<TipoAtributo> teste;

		copy = removeOpcoes(opt, 'x', arv->posicao);
		teste = contaPosNeg(copy);
		if (calculaEntropia(teste[pos].qtd.positivo, teste[pos].qtd.negativo) > 0)
			recursiva(copy, arv->x);
		else if (teste[pos].qtd.positivo > teste[pos].qtd.negativo)
			strcpy(arv->x->posicao, "positive");
		else if (teste[pos].qtd.negativo > teste[pos].qtd.positivo)
			strcpy(arv->x->posicao, "negative");
		else
			strcpy(arv->x->posicao, "negative");

		copy = removeOpcoes(opt, 'o', arv->posicao);
		teste = contaPosNeg(copy);
		if (calculaEntropia(teste[pos + 1].qtd.positivo, teste[pos + 1].qtd.negativo) > 0)
			recursiva(copy, arv->o);
		else if (teste[pos + 1].qtd.positivo > teste[pos + 1].qtd.negativo)
			strcpy(arv->o->posicao, "positive");
		else if (teste[pos + 1].qtd.negativo > teste[pos + 1].qtd.positivo)
			strcpy(arv->o->posicao, "negative");
		else
			strcpy(arv->o->posicao, "negative");

		copy = removeOpcoes(opt, 'b', arv->posicao);
		teste = contaPosNeg(copy);
		if (calculaEntropia(teste[pos + 2].qtd.positivo, teste[pos + 2].qtd.negativo) > 0)
			recursiva(copy, arv->b);
		else if (teste[pos + 2].qtd.positivo > teste[pos + 2].qtd.negativo)
			strcpy(arv->b->posicao, "positive");
		else if (teste[pos + 2].qtd.negativo > teste[pos + 2].qtd.positivo)
			strcpy(arv->b->posicao, "negative");
		else
			strcpy(arv->b->posicao, "negative");
	}
	else {
		std::vector<TipoAtributo> teste;
		printf("Oi\n");
		teste = contaPosNeg(opt);
		if (teste[pos].qtd.positivo > teste[pos].qtd.negativo)
			strcpy(arv->posicao, "positive");
		else
			strcpy(arv->posicao, "negative");
	}
}

void show_rec(Arvore* arv)
{
	if (arv != nullptr)
	{
		std::cout << "<";
		std::cout << arv->posicao;
		show_rec(arv->x);
		show_rec(arv->o);
		show_rec(arv->b);
		std::cout << ">";
	}
	else
	{
		std::cout << ".";
	}
}