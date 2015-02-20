#include <stdio.h>
#include "erros.h"

struct erros {
	int codigo;
	char *mensagem;
} erros[] = {
	{SAIR, "sair do programa"},
	{ERRO_OK, "Não há erro"},
	{ERRO_CMD_NAO_EXISTE, "Comando não existe"},
	{ERRO_NARGS, "Erro no nº de argumentos"}
};

void imprime_erro(int erro) {
	fprintf(stderr, "%s\n", erros[erro].mensagem);
}
