#pragma once
#include <vector>

typedef struct opcoes {
	char tl, tm, tr, ml, mm, mr, bl, bm, br;
	char classe[9];
}Opcoes;

std::vector<Opcoes> leArq(char* path, int tam);