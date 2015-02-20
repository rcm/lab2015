#include <stdio.h>
#include <string.h>
#include "erros.h"
#include "comandos.h"

/** Tamanho do buffer */
#define BUF_SIZE	10240

/**
Estrutura utilizada pelo intrpretador de comandos
*/
typedef struct comandos {
	char *cmd;
	int nargs;
	char *descricao;
	int (*funcao)(char *cmd, int nargs, char **args);
} comandos;

/**
	Interpretador de comandos
	@returns	Código do erro que possa ter acontecido e ERRO_OK se tudo correu bem
*/
int interpretador() {
	/*
		Lista de comandos
	Para adicionar um novo comando à lista é só adicionar mais uma linha
	nesta estrutura com a mesma forma que as anteriores antes da última linha
	*/
	comandos cmds[] = {
		{"soma", 2, "soma dois números", somar},
		{"sair", 0, "sair do programa", sair},
		{NULL, 0, NULL, NULL} /* Não colocar nada na estrutura depois desta linha */
	};
	char * delims = " \t\n";
	char *cmd;
	int nargs = 0;
	char *args[20];
	char buffer[BUF_SIZE];
	int i = 0;
	
	/* Ler linha do stdin */
	if(fgets(buffer, BUF_SIZE, stdin) == NULL)
		return 0;
	
	/* Usar o string tokenizer para ir buscar o nome do comando */
	cmd = strtok(buffer, delims);

	/* Guardar argumentos nquanto existirem */
	while((args[nargs] = strtok(NULL, delims))) {
		nargs++;
	}

	/* Procurar comando na lista de comandos */
	while(cmds[i].cmd != NULL && strcmp(cmds[i].cmd, cmd)) {
		i++;
	}

	/* Comando não existe */
	if(cmds[i].cmd == NULL)
		return ERRO_CMD_NAO_EXISTE;
	
	return cmds[i].funcao(cmd, nargs, args);
}

/**
Função principal do programa
*/
int main() {
	int erro;
	while((erro = interpretador())) {
		if(erro != SAIR && erro != ERRO_OK)
			imprime_erro(erro);
	}
	return 0;
}
