#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "openFile.h"
#include "Arvore_Decisao.h"

int main(void) {
	int tamTot = 958;
	float perc = 0.33;// separaTreinoRand 0.33 = 84%	separaTreinoRandPosNeg 0.7 = 87%
	Arvore *a;
	int tamTreino, tamTeste;

	tamTreino = tamTot * perc;
	tamTeste = tamTot - tamTreino;

	separaTreinoRand(perc, tamTot, "data.txt", "conjTreino.csv", "conjTeste.csv");
	//separaTreinoRandPosNeg(perc, tamTot, "data.txt", "conjTreino.txt", "conjTeste.txt");

	a = criaArvore("conjTreino.txt", tamTreino);

	testaArvore("conjTeste.txt", "resultado.txt", tamTeste, a);
	//testaArvore("data.txt", "resultado.txt", tamTot, a);

	comparaResultados("conjTeste.txt", "resultado.txt", tamTeste);
	//comparaResultados("data.txt", "resultado.txt", tamTot);
	return 0;
}