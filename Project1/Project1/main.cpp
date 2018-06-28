#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include "openFile.h"
#include "Arvore_Decisao.h"

int main(void) {
	Arvore *a;
	a = criaArvore("data.txt", 958);

	testaArvore("data.txt", 958, a);

	return 0;
}