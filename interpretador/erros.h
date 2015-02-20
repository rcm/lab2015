/** Identificadores dos erros */
typedef enum {
	SAIR,
	ERRO_OK,
	ERRO_CMD_NAO_EXISTE,
	ERRO_NARGS
} ERROS;

void imprime_erro(int erro);
