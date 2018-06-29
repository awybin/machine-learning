#pragma once
#include <vector>

typedef struct opcoes {
	char tl, tm, tr, ml, mm, mr, bl, bm, br;
	char classe[9];
}Opcoes;

std::vector<Opcoes> leArq(char* path, int tam);

void geraArq(char* path, std::vector<int> resultado);

void comparaResultados(char* pathTeste, char* pathResultado, int tam);