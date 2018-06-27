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
		
		fscanf(f, "%c%c%c%c%c%c%c%c%s", &temp.mr, &coma, &temp.bl, &coma, &temp.mm, &coma, &temp.br, &coma, temp.classe);
		
		temp.classe[8] = '\0';
		fscanf(f, "%c", &coma);
		vetor.push_back(temp);
	}

	fclose(f);
	return vetor;
}