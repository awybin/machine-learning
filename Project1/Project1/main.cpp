#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "openFile.h"
#include "Arvore_Decisao.h"

int main(void) {
	int tamTot = 958;

	//Alterando o percentual aqui pode-se selecionar diferentes tamanhos para o treinamento
	float perc = 0.68;// Melhores resultados: separaTreinoRand 0.73 = 88.41%, separaTreinoRandPosNeg 0.68 = 88.27%

	Arvore *a;
	int tamTreino, tamTeste;

	tamTreino = tamTot * perc;
	tamTeste = tamTot - tamTreino;

	/*Aqui estão as duas funcoes que podem separar os conjuntos
	  para escolher, basta comentar uma e deixar a outra sem comentarios
	*/
	//separaTreinoRand(perc, tamTot, "data.txt", "conjTreino.txt", "conjTeste.txt");
	separaTreinoRandPosNeg(perc, tamTot, "data.txt", "conjTreino.txt", "conjTeste.txt");
	separaTreinoRandPosNeg(perc, tamTot, "data.txt", "conjTreino.csv", "conjTeste.csv");

	/*As funcoes abaixo fazem a criacao, teste e comparacao dos resultados da arvore
	  para testar usando todos os dados para o treinamento e para os testes basta
	  comentar as funcoes de cima  e descomentar as de baixo
	*/

	a = criaArvore("conjTreino.txt", tamTreino);
	//a = criaArvore("data.txt", tamTot);

	testaArvore("conjTeste.txt", "resultado.txt", tamTeste, a);
	//testaArvore("data.txt", "resultado.txt", tamTot, a);

	comparaResultados("conjTeste.txt", "resultado.txt", tamTeste);
	//comparaResultados("data.txt", "resultado.txt", tamTot);
	return 0;
}