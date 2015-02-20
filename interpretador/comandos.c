#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "erros.h"

#define UNUSED(__var) (__var = __var)

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

int sair(char * cmd, int nargs, char **args) {
	UNUSED(cmd);
	UNUSED(args);

	if(nargs != 0)
		return ERRO_NARGS;
	return SAIR;
}
