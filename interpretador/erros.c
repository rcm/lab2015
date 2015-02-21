#include <stdio.h>
#include "erros.h"

/**
Estrutura interna que contém as mensagens correspondentes aos códigos dos erros
*/
typedef struct erros {
	int codigo;
	char *mensagem;
} MENSAGENS_ERRO;

/**
Cada linha do array contém o código do erro e a mensagem correspondente.
Para adicionar um novo erro, junta-se o novo código ao enum que está no erros.h
e uma nova linha nesta estrutura na mesma posição com a mensagem correspondente
*/
MENSAGENS_ERRO erros[] = {
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
