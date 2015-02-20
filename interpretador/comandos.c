#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"

/** Macro usada para não haver warning de variáveis não utilizadas */
#define UNUSED(__var) (__var = __var)


/**
Função que implementa o comando somar que soma dois valores e imprime o resultado
@arg cmd O nome do comando
@arg nargs O nº de argumentos passados ao comando
@arg args Um array de strings com os argumentos passados ao comando
@return devolve ERRO_NARGS se o nº de argumentos não é dois e ERRO_OK se tudo corre bem
*/
int somar(char *cmd, int nargs, char **args) {
	int n1, n2;

	UNUSED(cmd);

	if(nargs != 2)
		return ERRO_NARGS;

	n1 = atoi(args[0]);
	n2 = atoi(args[1]);
	printf("%d\n", n1 + n2);
	return ERRO_OK;
}

/**
Função que implementa o comando sair
@arg cmd O nome do comando
@arg nargs O nº de argumentos passados ao comando
@arg args Um array de strings com os argumentos passados ao comando
@return devolve ERRO_NARGS se o nº de argumentos não é zero e SAIR se tudo corre bem
*/
int sair(char * cmd, int nargs, char **args) {
	UNUSED(cmd);
	UNUSED(args);

	if(nargs != 0)
		return ERRO_NARGS;
	return SAIR;
}
