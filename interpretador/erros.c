#include <stdio.h>
#include "erros.h"

/**
Estrutura interna que contém as mensagens correspondentes aos códigos dos erros
*/
typedef struct erros {
	int codigo;
	char *mensagem;
} ERROS;

ERROS erros[] = {
	{SAIR, "sair do programa"},
	{ERRO_OK, "Não há erro"},
	{ERRO_CMD_NAO_EXISTE, "Comando não existe"},
	{ERRO_NARGS, "Erro no nº de argumentos"}
};

/**
Função que imprime a mensagem de erro correspondente ao código do erro
@param erro O código do erro
*/
void imprime_erro(int erro) {
	fprintf(stderr, "%s\n", erros[erro].mensagem);
}
