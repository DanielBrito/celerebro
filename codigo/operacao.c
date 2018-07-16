#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "operacao.h"
#include "conversao.h"
#include "partida.h"

#define ADICAO_MUITO_FACIL 50
#define ADICAO_FACIL 100
#define ADICAO_MEDIO 500
#define ADICAO_DIFICIL 1000
#define ADICAO_MUITO_DIFICIL 2000

#define SUBTRACAO_MUITO_FACIL 50
#define SUBTRACAO_FACIL 100
#define SUBTRACAO_MEDIO 500
#define SUBTRACAO_DIFICIL 1000
#define SUBTRACAO_MUITO_DIFICIL 2000

#define MULTIPLICACAO_MUITO_FACIL 10
#define MULTIPLICACAO_FACIL 20
#define MULTIPLICACAO_MEDIO 100
#define MULTIPLICACAO_DIFICIL 500
#define MULTIPLICACAO_MUITO_DIFICIL 1000

#define DIVISAO_MUITO_FACIL 100
#define DIVISAO_FACIL 500
#define DIVISAO_MEDIO 1000
#define DIVISAO_DIFICIL 3000
#define DIVISAO_MUITO_DIFICIL 5000

enum opNum {ADICAO=1, SUBTRACAO=2, MULTIPLICACAO=3, DIVISAO=4, ALEATORIA=5};
enum nivelOp {MUITO_FACIL=1, FACIL=2, MEDIO=3, DIFICIL=4, MUITO_DIFICIL=5};

int indexAleatoria = 0;

struct operacao{

    int index;
    int num1;
    int op;
    int num2;
    int resultado;
};

struct erro{

    int num1;
    int op;
    int num2;
    int resultado;
    int resposta;
};

struct listaoperacoes{

    Operacao* operacao;
    struct listaoperacoes* prox;
};

struct listaerros{

    Erro* erro;
    struct listaerros* prox;
};

Operacao* criarNovaOperacao(int index, int num1, int op, int num2, int resultado){

    Operacao* novaOperacao = (Operacao*)malloc(sizeof(Operacao));

    novaOperacao->index = index;
    novaOperacao->num1 = num1;
    novaOperacao->op = op;
    novaOperacao->num2 = num2;
    novaOperacao->resultado = resultado;

    return novaOperacao;
}

Erro* criarNovoErro(int num1, int op, int num2, int resultado, int resposta){

    Erro* novoErro = (Erro*)malloc(sizeof(Erro));

    novoErro->num1 = num1;
    novoErro->op = op;
    novoErro->num2 = num2;
    novoErro->resultado = resultado;
    novoErro->resposta = resposta;

    return novoErro;
}

ListaOperacoes* criarListaOperacoes(){

    return NULL;
}

ListaErros* criarListaErros(){

    return NULL;
}

ListaOperacoes* inserirOperacao(ListaOperacoes* operacoes, Operacao* novaOperacao){

    ListaOperacoes* operacaoNo = (ListaOperacoes*)malloc(sizeof(ListaOperacoes));
    operacaoNo->operacao = novaOperacao;
    operacaoNo->prox = operacoes;

    return operacaoNo;
}

ListaErros* inserirErro(ListaErros* erros, Erro* novoErro){

    ListaErros* erroNo = (ListaErros*)malloc(sizeof(ListaErros));
    erroNo->erro = novoErro;
    erroNo->prox = erros;

    return erroNo;
}

void imprimirErros(ListaErros* erros){

    ListaErros* aux = erros;

    while(aux!=NULL){

        printf("   [X] %d %c %d = %d\n", aux->erro->num1, imprimirTipoOperacaoChar(aux->erro->op), aux->erro->num2, aux->erro->resposta);
        printf("   [>] %d %c %d = %d\n\n", aux->erro->num1, imprimirTipoOperacaoChar(aux->erro->op), aux->erro->num2, aux->erro->resultado);

        aux = aux->prox;
    }

    printf("\n                   Tecle ENTER para continuar... ");

    char pausar;
    scanf("%c", &pausar);
    getchar();

    iniciarMenu();
}

ListaOperacoes* carregarListaOperacoes(ListaOperacoes* operacoes, int flag, int tipoOperacao, int nivel){

    Operacao* novaOperacao;

    int index=0, i, j;

    if(tipoOperacao==ADICAO){

        if(nivel==MUITO_FACIL){

            for(i=0; i<=ADICAO_MUITO_FACIL; i++){

                for(j=0; j<=ADICAO_MUITO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==ADICAO){

        if(nivel==FACIL){

            for(i=ADICAO_MUITO_FACIL; i<=ADICAO_FACIL; i++){

                for(j=ADICAO_MUITO_FACIL; j<=ADICAO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==ADICAO){

        if(nivel==MEDIO){

            for(i=ADICAO_FACIL; i<=ADICAO_MEDIO; i++){

                for(j=i; j<=ADICAO_MEDIO; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==ADICAO){

        if(nivel==DIFICIL){

            for(i=ADICAO_MEDIO; i<=ADICAO_DIFICIL; i++){

                for(j=i; j<=ADICAO_DIFICIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==ADICAO){

        if(nivel==MUITO_DIFICIL){

            for(i=ADICAO_DIFICIL; i<=ADICAO_MUITO_DIFICIL; i++){

                for(j=i; j<=ADICAO_MUITO_DIFICIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, ADICAO, j, i+j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==MUITO_FACIL){

            for(i=0; i<=SUBTRACAO_MUITO_FACIL; i++){

                for(j=0; j<=SUBTRACAO_MUITO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==FACIL){

            for(i=SUBTRACAO_MUITO_FACIL; i<=SUBTRACAO_FACIL; i++){

                for(j=SUBTRACAO_MUITO_FACIL; j<=SUBTRACAO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==MEDIO){

            for(i=SUBTRACAO_MEDIO; i>=SUBTRACAO_FACIL; i--){

                for(j=i; j>=SUBTRACAO_FACIL; j--){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==DIFICIL){

            for(i=SUBTRACAO_DIFICIL; i>=SUBTRACAO_MEDIO; i--){

                for(j=i; j>=SUBTRACAO_MEDIO; j--){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==MUITO_DIFICIL){

            for(i=SUBTRACAO_MUITO_DIFICIL; i>=SUBTRACAO_DIFICIL; i--){

                for(j=i; j>=SUBTRACAO_DIFICIL; j--){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, SUBTRACAO, j, i-j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==MUITO_FACIL){

            for(i=0; i<=MULTIPLICACAO_MUITO_FACIL; i++){

                for(j=0; j<=MULTIPLICACAO_MUITO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==FACIL){

            for(i=0; i<=MULTIPLICACAO_FACIL; i++){

                for(j=0; j<=MULTIPLICACAO_FACIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==MEDIO){

            for(i=0; i<=MULTIPLICACAO_MEDIO; i++){

                for(j=i; j<=MULTIPLICACAO_MEDIO; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==DIFICIL){

            for(i=0; i<=MULTIPLICACAO_DIFICIL; i++){

                for(j=i; j<=MULTIPLICACAO_DIFICIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==MUITO_DIFICIL){

            for(i=0; i<=MULTIPLICACAO_MUITO_DIFICIL; i++){

                for(j=i; j<=MULTIPLICACAO_MUITO_DIFICIL; j++){

                    if(flag==1){

                        novaOperacao = criarNovaOperacao(indexAleatoria, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++indexAleatoria;
                    }
                    else{

                        novaOperacao = criarNovaOperacao(index, i, MULTIPLICACAO, j, i*j);
                        operacoes = inserirOperacao(operacoes, novaOperacao);

                        ++index;
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==MUITO_FACIL){

            for(i=1; i<=DIVISAO_MUITO_FACIL; i++){

                for(j=1; j<=DIVISAO_MUITO_FACIL; j++){

                    if(flag==1){

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(indexAleatoria, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++indexAleatoria;
                        }
                    }
                    else{

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(index, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++index;
                        }
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==FACIL){

            for(i=1; i<=DIVISAO_FACIL; i++){

                for(j=1; j<=DIVISAO_FACIL; j++){

                    if(flag==1){

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(indexAleatoria, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++indexAleatoria;
                        }
                    }
                    else{

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(index, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++index;
                        }
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==MEDIO){

            for(i=1; i<=DIVISAO_MEDIO; i++){

                for(j=1; j<=DIVISAO_MEDIO; j++){

                    if(flag==1){

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(indexAleatoria, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++indexAleatoria;
                        }
                    }
                    else{

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(index, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++index;
                        }
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==DIFICIL){

            for(i=1; i<=DIVISAO_DIFICIL; i++){

                for(j=1; j<=DIVISAO_DIFICIL; j++){

                    if(flag==1){

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(indexAleatoria, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++indexAleatoria;
                        }
                    }
                    else{

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(index, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++index;
                        }
                    }
                }
            }

            return operacoes;
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==MUITO_DIFICIL){

            for(i=1; i<=DIVISAO_MUITO_DIFICIL; i++){

                for(j=1; j<=DIVISAO_MUITO_DIFICIL; j++){

                    if(flag==1){

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(indexAleatoria, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++indexAleatoria;
                        }
                    }
                    else{

                        if(i%j==0){

                            novaOperacao = criarNovaOperacao(index, i, DIVISAO, j, i/j);
                            operacoes = inserirOperacao(operacoes, novaOperacao);

                            ++index;
                        }
                    }
                }
            }

            return operacoes;
        }
    }
}

void reiniciarIndex(){

    indexAleatoria = 0;
}

void liberarListaOperacoes(ListaOperacoes* operacoes){

	ListaOperacoes* aux = operacoes;

	while(aux!=NULL){

		ListaOperacoes* temp = aux->prox;

        free(aux->operacao);
		free(aux);

		aux = temp;
	}
}

void liberarListaErros(ListaErros* erros){

    ListaErros* aux = erros;

    while(aux!=NULL){

        ListaErros* temp = aux->prox;

        free(aux->erro);
        free(aux);

        aux = temp;
    }
}

Operacao* sortearOperacao(ListaOperacoes* operacoes){

    int numRand;
    ListaOperacoes* aux = operacoes;

    srand(time(NULL));

    numRand = rand()%maxIndex(operacoes)+1;

    while(aux!=NULL){

        if(numRand==aux->operacao->index){

            return aux->operacao;
        }

        aux = aux->prox;
    }
}

int maxIndex(ListaOperacoes* operacoes){

    return operacoes->operacao->index;
}

int getNum1 (Operacao* operacao){

    return operacao->num1;
}

int getNum2 (Operacao* operacao){

    return operacao->num2;
}

int getTipoOperacao(Operacao* operacao){

    return operacao->op;
}

int getResultado (Operacao* operacao){

    return operacao->resultado;
}