#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "openFile.h"

std::vector<Opcoes> leArq(char* path, int tam) {
	FILE *f;
	Opcoes temp;
	std::vector<Opcoes> vetor;

	vetor.reserve(tam);
	if ((f = fopen(path, "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}
	
	for (int i = 0; i < tam; i++) {
		char coma;
		fscanf(f, "%c%c%c%c%c%c%c%c%c%c", &temp.tl, &coma, &temp.tm, &coma, &temp.tr, &coma, &temp.ml, &coma, &temp.mm, &coma);
		
		fscanf(f, "%c%c%c%c%c%c%c%c%s", &temp.mr, &coma, &temp.bl, &coma, &temp.bm, &coma, &temp.br, &coma, temp.classe);
		
		temp.classe[8] = '\0';
		fscanf(f, "%c", &coma);
		vetor.push_back(temp);
	}

	fclose(f);
	return vetor;
}

void geraArqRes(char* path, std::vector<int> resultado) {
	FILE *f;

	if ((f = fopen(path, "wt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; i < resultado.size(); i++) {
		if(resultado[i] == 1)
			fprintf(f, "positive\n");
		else
			fprintf(f, "negative\n");
	}

	fclose(f);
}

void comparaResultados(char* pathTeste, char* pathResultado, int tam) {
	FILE *fteste, *fRes;
	int resCorretos = 0;
	if ((fteste = fopen(pathTeste, "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}
	if ((fRes = fopen(pathResultado, "rt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; i < tam; i++) {
		char temp, resEsp[9], resObt[9];
		fscanf(fteste, "%c%c%c%c%c%c%c%c%c%c", &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp);
		fscanf(fteste, "%c%c%c%c%c%c%c%c%s", &temp, &temp, &temp, &temp, &temp, &temp, &temp, &temp, resEsp);
		resEsp[8] = '\0';
		fscanf(fteste, "%c", &temp);

		fscanf(fRes, "%s", resObt);
		if (strcmp(resObt, resEsp) == 0)
			resCorretos++;
	}

	printf("\nResultados Corretos: %d, de: %d\nPercentual de acerto:  %f%\n\n", resCorretos, tam, resCorretos*100 / (float)tam);
}

void geraArqDado(char* path, std::vector<Opcoes> vetor) {
	FILE *f;

	if ((f = fopen(path, "wt")) == NULL) {
		printf("erro ao abrir o arquivo\n");
		exit(1);
	}

	for (int i = 0; i < vetor.size(); i++) {
		fprintf(f, "%c,%c,%c,%c,%c,%c,%c,%c,%c,%s\n", vetor[i].tl, vetor[i].tm, vetor[i].tr, vetor[i].ml, vetor[i].mm, vetor[i].mr, vetor[i].bl, vetor[i].bm, vetor[i].br, vetor[i].classe);
	}

	fclose(f);
}
void separaTreinoRand(float perc, int tam, char* pathData, char* pathTreino, char* pathTeste) {
	std::vector<Opcoes> teste, treino;
	teste = leArq(pathData, tam);
	int tamTreino = perc*tam;

	srand(1);
	treino.reserve(tamTreino);

	for (int i = 0; i < tamTreino; i++) {
		int move;
		move = rand() % teste.size();
		treino.push_back(teste[move]);
		teste.erase(teste.begin() + move);
	}

	geraArqDado(pathTreino, treino);

	geraArqDado(pathTeste, teste);
}

void separaTreinoRandPosNeg(float perc, int tam, char* pathData, char* pathTreino, char* pathTeste) {
	std::vector<Opcoes> teste, treino;
	teste = leArq(pathData, tam);
	int tamTreino = perc*tam;

	srand(1);
	treino.reserve(tamTreino);

	int cont = 0;
	for (int i = 0; i < tamTreino; i++) {
		int move;
		move = rand() % teste.size();
		if (i % 2 == 0) {
			if (strcmp(teste[move].classe, "positive") == 0 || cont > 10) {
				treino.push_back(teste[move]);
				teste.erase(teste.begin() + move);
				cont = 0;
			}
			else {
				i--;
				cont++;
			}
		}
		else {
			if (strcmp(teste[move].classe, "negative") == 0 || cont > 10) {
				treino.push_back(teste[move]);
				teste.erase(teste.begin() + move);
				cont = 0;
			}
			else {
				i--;
				cont++;
			}
		}
	}

	geraArqDado(pathTreino, treino);

	geraArqDado(pathTeste, teste);
}