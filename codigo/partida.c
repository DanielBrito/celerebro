#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "partida.h"
#include "telas.h"
#include "operacao.h"
#include "conversao.h"

#define MAX_RANK 3

enum opNum {ADICAO=1, SUBTRACAO=2, MULTIPLICACAO=3, DIVISAO=4, ALEATORIA=5};
enum nivelOp {MUITO_FACIL=1, FACIL=2, MEDIO=3, DIFICIL=4, MUITO_DIFICIL=5};

struct partida{

    char nome[30];
    int nivel;
    int tipoOperacao;
    int qtdOperacoes;
    int pontuacao;
    long int tempoPartida;
};

struct listapartidas{

    Partida* partida;
    struct listapartidas* prox;
};

void iniciarJogo(){

    telaIniciarJogo();

    iniciarMenu();
}

Partida* criarPartida(char* nome, int nivel, int operacao, int pontuacao, long int tempoPartida){

    Partida* novaPartida = (Partida*)malloc(sizeof(Partida));

    strcpy(novaPartida->nome, nome);
    novaPartida->nivel = nivel;
    novaPartida->tipoOperacao = operacao;
    novaPartida->pontuacao = pontuacao;
    novaPartida->tempoPartida = tempoPartida;

    return novaPartida;
}

ListaPartidas* criarListaPartidas(){

    return NULL;
}

ListaPartidas* inserirPartida(ListaPartidas* partidas, Partida* novaPartida){

    ListaPartidas* partidaNo = (ListaPartidas*)malloc(sizeof(ListaPartidas));
    partidaNo->partida = novaPartida;
    partidaNo->prox = partidas;

    return partidaNo;
}

void iniciarMenu(){

    int opcao;

    do{
        system("clear");

        telaMenu();

        printf("   1 - Nova partida\n");
        printf("   2 - Ranking\n");
        printf("   3 - Neurobica\n");
        printf("   0 - Sair\n\n");

        printf("   = > ");
        scanf("%d", &opcao);

    }while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=0);

    switch(opcao){

        case 1: novaPartida(); 
                break;

        case 2: telaRanking();
                mostrarRanking();
                break;

        case 3: telaNeurobica(); 
                break;

        case 0: telaSair(); 
                exit(0);
    }
}

void novaPartida(){

    char nome[30];
    int tipoOperacao;
    int nivel;
    int qtdOperacoes;
    int pontuacao=0;
    long int tempoPartida=0;
    time_t inicioPartida, fimPartida;
    int opcao;
    char pausar;
    int flagAleatoria = 1;

    Partida* p = (Partida*)malloc(sizeof(Partida));

    telaNovaPartida();

    printf("   Digite seu nome: \n\n   = > ");
    scanf(" %30[^\n]", nome);

    do{

        telaNovaPartida();

        printf("   Escolha o tipo de operação:\n\n");
        printf("   1 - Adição [+]\n");
        printf("   2 - Subtração [-]\n");
        printf("   3 - Multiplicação [*]\n");
        printf("   4 - Divisão [/]\n");
        printf("   5 - Aleatória [+-/*]\n\n");

        printf("   = > ");
        scanf("%d", &tipoOperacao);
    
    }while(tipoOperacao!=1 && tipoOperacao!=2 && tipoOperacao!=3 && tipoOperacao!=4 && tipoOperacao!=5);

    do{

        telaNovaPartida();

        printf("   Escolha o nível:\n\n");
        printf("   1 - Muito fácil\n");
        printf("   2 - Fácil\n");
        printf("   3 - Médio\n");
        printf("   4 - Difícil\n");
        printf("   5 - Muito difícil\n\n");

        printf("   = > ");
        scanf("%d", &nivel);

    }while(nivel!=1 && nivel!=2 && nivel!=3 && nivel!=4 && nivel!=5);

    do{

        telaNovaPartida();

        printf("   Digite a quantidade de operações:\n\n");

        printf("   = > ");
        scanf("%d", &qtdOperacoes);

    }while(qtdOperacoes<1);

    strcpy(p->nome, nome);
    p->tipoOperacao = tipoOperacao;
    p->nivel = nivel;
    p->qtdOperacoes = qtdOperacoes;

    ListaOperacoes* operacoes = criarListaOperacoes();
    ListaErros* erros;

    telaJogoCarregarEstatica();    

    if(tipoOperacao==ADICAO){

        if(nivel==MUITO_FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, ADICAO, MUITO_FACIL);
        }

        if(nivel==FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, ADICAO, FACIL);
        }

        if(nivel==MEDIO){

            operacoes = carregarListaOperacoes(operacoes, 0, ADICAO, MEDIO);
        }

        if(nivel==DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, ADICAO, DIFICIL);
        }

        if(nivel==MUITO_DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, ADICAO, MUITO_DIFICIL);
        }
    }

    if(tipoOperacao==SUBTRACAO){

        if(nivel==MUITO_FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, SUBTRACAO, MUITO_FACIL);
        }

        if(nivel==FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, SUBTRACAO, FACIL);
        }

        if(nivel==MEDIO){

            operacoes = carregarListaOperacoes(operacoes, 0, SUBTRACAO, MEDIO);
        }

        if(nivel==DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, SUBTRACAO, DIFICIL);
        }

        if(nivel==MUITO_DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, SUBTRACAO, MUITO_DIFICIL);
        }
    }

    if(tipoOperacao==MULTIPLICACAO){

        if(nivel==MUITO_FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, MULTIPLICACAO, MUITO_FACIL);
        }

        if(nivel==FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, MULTIPLICACAO, FACIL);
        }

        if(nivel==MEDIO){

            operacoes = carregarListaOperacoes(operacoes, 0, MULTIPLICACAO, MEDIO);
        }

        if(nivel==DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, MULTIPLICACAO, DIFICIL);
        }

        if(nivel==MUITO_DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, MULTIPLICACAO, MUITO_DIFICIL);
        }
    }

    if(tipoOperacao==DIVISAO){

        if(nivel==MUITO_FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, DIVISAO, MUITO_FACIL);
        }

        if(nivel==FACIL){

            operacoes = carregarListaOperacoes(operacoes, 0, DIVISAO, FACIL);
        }

        if(nivel==MEDIO){

            operacoes = carregarListaOperacoes(operacoes, 0, DIVISAO, MEDIO);
        }

        if(nivel==DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, DIVISAO, DIFICIL);
        }

        if(nivel==MUITO_DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 0, DIVISAO, MUITO_DIFICIL);
        }
    }

    if(tipoOperacao==ALEATORIA){

        if(nivel==MUITO_FACIL){

            operacoes = carregarListaOperacoes(operacoes, 1, ADICAO, MUITO_FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, SUBTRACAO, MUITO_FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, MULTIPLICACAO, MUITO_FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, DIVISAO, MUITO_FACIL);
        }

        if(nivel==FACIL){

            operacoes = carregarListaOperacoes(operacoes, 1, ADICAO, FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, SUBTRACAO, FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, MULTIPLICACAO, FACIL);
            operacoes = carregarListaOperacoes(operacoes, 1, DIVISAO, FACIL);
        }

        if(nivel==MEDIO){

            operacoes = carregarListaOperacoes(operacoes, 1, ADICAO, MEDIO);
            operacoes = carregarListaOperacoes(operacoes, 1, SUBTRACAO, MEDIO);
            operacoes = carregarListaOperacoes(operacoes, 1, MULTIPLICACAO, MEDIO);
            operacoes = carregarListaOperacoes(operacoes, 1, DIVISAO, MEDIO);
        }

        if(nivel==DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 1, ADICAO, DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, SUBTRACAO, DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, MULTIPLICACAO, DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, DIVISAO, DIFICIL);
        }

        if(nivel==MUITO_DIFICIL){

            operacoes = carregarListaOperacoes(operacoes, 1, ADICAO, MUITO_DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, SUBTRACAO, MUITO_DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, MULTIPLICACAO, MUITO_DIFICIL);
            operacoes = carregarListaOperacoes(operacoes, 1, DIVISAO, MUITO_DIFICIL);
        }
    }

    reiniciarIndex();

    telaJogoCarregar(0);

    telaJogoEspera();

    inicioPartida = time(NULL);

    erros = iniciarPartida(&pontuacao, p, operacoes); 

    fimPartida = time(NULL);
    
    tempoPartida = fimPartida-inicioPartida;

    p->pontuacao = pontuacao;
    p->tempoPartida = tempoPartida;

    cadastrarRanking(p);

    liberarListaOperacoes(operacoes);

    telaResultado();
    imprimirResultado(p);

    if(erros==NULL){

        do{

            telaFimDeJogo();

            printf("   Digite o que deseja fazer:\n\n");
            printf("   1 - Retornar ao menu\n");
            printf("   2 - Jogar novamente\n");
            printf("   3 - Exibir ranking\n");
            printf("   0 - Sair\n\n");

            printf("   = > ");
            scanf("%d", &opcao);
        
        }while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=0);

        switch(opcao){

            case 1: free(p); 
                    liberarListaErros(erros); 
                    iniciarMenu(); 
                    break;

            case 2: free(p); 
                    liberarListaErros(erros); 
                    novaPartida(); 
                    break;

            case 3: free(p); 
                    liberarListaErros(erros);
                    telaRanking();
                    mostrarRanking();
                    break;

            case 0: free(p); 
                    liberarListaErros(erros); 
                    telaSair();
        }
    }
    else{

        do{

            telaFimDeJogo();

            printf("   Digite o que deseja fazer:\n\n");
            printf("   1 - Retornar ao menu\n");
            printf("   2 - Jogar novamente\n");
            printf("   3 - Mostrar erros\n");
            printf("   4 - Exibir ranking\n");
            printf("   0 - Sair\n\n");

            printf("   = > ");
            scanf("%d", &opcao);
        
        }while(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=0);

        switch(opcao){

            case 1: free(p); 
                    liberarListaErros(erros); 
                    iniciarMenu(); 
                    break;

            case 2: free(p); 
                    liberarListaErros(erros); 
                    novaPartida(); 
                    break;

            case 3: free(p); 
                    telaErros(); 
                    imprimirErros(erros); 
                    liberarListaErros(erros); 
                    break;

            case 4: free(p); 
                    liberarListaErros(erros); 
                    mostrarRanking();
                    break;

            case 0: free(p); 
                    liberarListaErros(erros); 
                    telaSair();
        }
    }
}

ListaErros* iniciarPartida(int* pontuacao, Partida* p, ListaOperacoes* operacoes){

    int i, resposta=0;
    Operacao* operacaoSorteada;
    Erro* novoErro; 
    ListaErros* erros = criarListaErros();

    for(i=0; i<p->qtdOperacoes; i++){

        telaJogo();

        printf("                        OPERACAO #%.2d de %.2d:\n\n", i+1, p->qtdOperacoes);

        if(p->tipoOperacao==ALEATORIA){

            operacaoSorteada = sortearOperacao(operacoes);

            if(getTipoOperacao(operacaoSorteada)==ADICAO){

                printf("                        %d + %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), ADICAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }

            if(getTipoOperacao(operacaoSorteada)==SUBTRACAO){

                printf("                        %d - %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), SUBTRACAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }  
            }

            if(getTipoOperacao(operacaoSorteada)==MULTIPLICACAO){

                printf("                        %d * %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), MULTIPLICACAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }

            if(getTipoOperacao(operacaoSorteada)==DIVISAO){

                printf("                        %d / %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), DIVISAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }
        }
        else{

            if(p->tipoOperacao==ADICAO){

                operacaoSorteada = sortearOperacao(operacoes);

                printf("                        %d + %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), ADICAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }
                    
            if(p->tipoOperacao==SUBTRACAO){

                operacaoSorteada = sortearOperacao(operacoes);

                printf("                        %d - %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), SUBTRACAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }  
            }
            
            if(p->tipoOperacao==MULTIPLICACAO){

                operacaoSorteada = sortearOperacao(operacoes);

                printf("                        %d * %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), MULTIPLICACAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }
            
            if(p->tipoOperacao==DIVISAO){

                operacaoSorteada = sortearOperacao(operacoes);

                printf("                        %d / %d = ", getNum1(operacaoSorteada), getNum2(operacaoSorteada));
                scanf("%d", &resposta);

                if(getResultado(operacaoSorteada)==resposta){

                    ++(*pontuacao);
                }
                else{

                    novoErro = criarNovoErro(getNum1(operacaoSorteada), DIVISAO, getNum2(operacaoSorteada), getResultado(operacaoSorteada), resposta);
                    erros = inserirErro(erros, novoErro);
                }
            }
        }
    }

    return erros;
}

void imprimirResultado(Partida* p){

    printf("   Nome: %s\n", p->nome);
    printf("   Nivel: %s\n", imprimirNivel(p->nivel));
    printf("   Operação: %s\n", imprimirTipoOperacaoString(p->tipoOperacao));
    printf("   Acertos: %d de %d\n", p->pontuacao, p->qtdOperacoes);
    printf("   Tempo: "); imprimirTempo(p->tempoPartida);

    char pausar;
    printf("\n\n\t\t   Tecle ENTER para continuar... ");
    scanf("%c", &pausar);
    getchar();
}

char* getNome(Partida* p){

    return p->nome;
}

int getNivel(Partida* p){

    return p->nivel;
}

int getOperacao(Partida* p){

    return p->tipoOperacao;
}

int getPontuacao(Partida* p){

    return p->pontuacao;
}

long int getTempoPartida(Partida* p){

    return p->tempoPartida;
}

Partida* getPartida(ListaPartidas* partidas){

    return partidas->partida;
}

void cadastrarRanking(Partida* p){

    FILE* arquivo;
    FILE* ocultar;

    arquivo = fopen("ranking.txt", "a");
    ocultar = fopen(".hidden", "w");

    if(arquivo==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }

    fprintf(arquivo, "%s %d %d %d %ld\n", getNome(p), getNivel(p), getOperacao(p), getPontuacao(p), getTempoPartida(p));

    fprintf(ocultar, "ranking.txt");

    if(ocultar==NULL){

        printf("Erro na abertura do arquivo!\n");
        exit(1);
    }
    
    fclose(arquivo);
    fclose(ocultar);
}

ListaPartidas* carregarRanking(){

    FILE *arquivo = fopen("ranking.txt", "r");
    
    char nome[50];
    int nivel=0;
    int operacao=0;
    int pontuacao=0;
    long int tempo=0;

    Partida* novaPartida;
    ListaPartidas* partidas = criarListaPartidas();
	
	if(arquivo==NULL){

        arquivoRankingNull();
	}
    else{

        while(fscanf(arquivo, "%s %d %d %d %ld", nome, &nivel, &operacao, &pontuacao, &tempo)==5){

            novaPartida = criarPartida(nome, nivel, operacao, pontuacao, tempo);

            partidas = inserirPartida(partidas, novaPartida);
	    }

        fclose(arquivo);

        return partidas;
    }
}

void liberarListaRanking(ListaPartidas* partidas){

    ListaPartidas* aux = partidas;

    while(aux!=NULL){

        ListaPartidas* temp = aux->prox;

        free(aux->partida);
        free(aux);

        aux = temp;
    }
}

void mostrarRanking(){

    ListaPartidas* partidas = carregarRanking();

    if(partidas==NULL){

        rankingVazio(1);
    }
    else{

        ListaPartidas* partidasMuitoFacil = filtrarRanking(partidas, MUITO_FACIL);
        ListaPartidas* partidasFacil = filtrarRanking(partidas, FACIL);
        ListaPartidas* partidasMedio = filtrarRanking(partidas, MEDIO);
        ListaPartidas* partidasDificil = filtrarRanking(partidas, DIFICIL);
        ListaPartidas* partidasMuitoDificil = filtrarRanking(partidas, MUITO_DIFICIL);

        partidasMuitoFacil = ordenarRanking(partidasMuitoFacil);
        partidasFacil = ordenarRanking(partidasFacil);
        partidasMedio = ordenarRanking(partidasMedio);
        partidasDificil = ordenarRanking(partidasDificil);
        partidasMuitoDificil = ordenarRanking(partidasMuitoDificil);

        if(!listaVazia(partidasMuitoFacil)){

            imprimirRanking(partidasMuitoFacil);
        }
        else{

            rankingVazio(MUITO_FACIL);
        }

        if(!listaVazia(partidasFacil)){

            imprimirRanking(partidasFacil);
        }
        else{

            rankingVazio(FACIL);
        }

        if(!listaVazia(partidasMedio)){

            imprimirRanking(partidasMedio);
        }
        else{

            rankingVazio(MEDIO);
        }

        if(!listaVazia(partidasDificil)){

            imprimirRanking(partidasDificil);
        }
        else{

            rankingVazio(DIFICIL);
        }

        if(!listaVazia(partidasMuitoDificil)){

            imprimirRanking(partidasMuitoDificil);
        }
        else{

            rankingVazio(MUITO_DIFICIL);
        }

        liberarListaRanking(partidasMuitoFacil);
        liberarListaRanking(partidasFacil);
        liberarListaRanking(partidasMedio);
        liberarListaRanking(partidasDificil);
        liberarListaRanking(partidasMuitoDificil);

        char pausar;
        printf("\n\t\t   Tecle ENTER para continuar... ");
        scanf("%c", &pausar);
        getchar();

        iniciarMenu();
    }
}

void imprimirRanking(ListaPartidas* partidas){

    ListaPartidas* aux = partidas;
    int posicao = 1;

    if(aux->partida->nivel==MUITO_FACIL){

        printf("   ------------------------ MUITO FÁCIL ------------------------\n\n");

        while(aux!=NULL && posicao<=MAX_RANK){

            imprimirPosicaoRanking(aux->partida, posicao);
            ++posicao;

            aux = aux->prox;
        }

        while(posicao<=MAX_RANK){

            imprimirPosicaoVazia(posicao);
            ++posicao;
        }

        return;
    }

    if(aux->partida->nivel==FACIL){

        printf("   --------------------------- FÁCIL ---------------------------\n\n");

        while(aux!=NULL && posicao<=MAX_RANK){

            imprimirPosicaoRanking(aux->partida, posicao);
            ++posicao;

            aux = aux->prox;
        }

        while(posicao<=MAX_RANK){

            imprimirPosicaoVazia(posicao);
            ++posicao;
        }

        return;
    }

    if(aux->partida->nivel==MEDIO){

        printf("   --------------------------- MÉDIO ---------------------------\n\n");

        while(aux!=NULL && posicao<=MAX_RANK){

            imprimirPosicaoRanking(aux->partida, posicao);
            ++posicao;

            aux = aux->prox;
        }

        while(posicao<=MAX_RANK){

            imprimirPosicaoVazia(posicao);
            ++posicao;
        }

        return;
    }

    if(aux->partida->nivel==DIFICIL){

        printf("   -------------------------- DIFÍCIL --------------------------\n\n");

        while(aux!=NULL && posicao<=MAX_RANK){

            imprimirPosicaoRanking(aux->partida, posicao);
            ++posicao;

            aux = aux->prox;
        }

        while(posicao<=MAX_RANK){

            imprimirPosicaoVazia(posicao);
            ++posicao;
        }

        return;
    }

    if(aux->partida->nivel==MUITO_DIFICIL){

        printf("   ----------------------- MUITO DIFICIL -----------------------\n\n");

        while(aux!=NULL && posicao<=MAX_RANK){

            imprimirPosicaoRanking(aux->partida, posicao);
            ++posicao;

            aux = aux->prox;
        }

        while(posicao<=MAX_RANK){

            imprimirPosicaoVazia(posicao);
            ++posicao;
        }

        return;
    }
}

int listaVazia(ListaPartidas* partidas){

    return partidas==NULL;
}

ListaPartidas* filtrarRanking(ListaPartidas* partidas, int nivel){

    ListaPartidas* aux = partidas;
    ListaPartidas* partidasSelecionadas = criarListaPartidas();

    while(aux!=NULL){

        if(aux->partida->nivel==nivel){

            partidasSelecionadas = inserirPartida(partidasSelecionadas, aux->partida);
        }

        aux = aux->prox;
    }

    return partidasSelecionadas;
}

ListaPartidas* ordenarRanking(ListaPartidas* partidas){

    int qtdNos = contaNos(partidas);
	int i;

	for(i=0; i<qtdNos; i++){

		ListaPartidas* atual = partidas;
		ListaPartidas* proxElem = atual->prox;
		ListaPartidas* antElem = NULL;

		while(proxElem!=NULL){

			if(atual->partida->pontuacao<proxElem->partida->pontuacao){

				if(atual==partidas){

					partidas = proxElem;
				}
				else{

					antElem->prox = proxElem;
				}

				atual->prox = proxElem->prox;
				proxElem->prox = atual;

				antElem = proxElem;
				proxElem = atual->prox;
			}
			else{

				antElem = atual;
				atual = atual->prox;
				proxElem = atual->prox;
			}
		}
	}

	return partidas;
}

int contaNos(ListaPartidas* partidas){

	ListaPartidas* aux = partidas;
	int cont=0;

    while(aux!=NULL){

        ++cont;

        aux = aux->prox;
    }

	return cont;
}

void imprimirPosicaoRanking(Partida* partida, int posicao){

    printf("   #%d  Nome: %s\n", posicao, partida->nome);
    printf("       Nivel: %d\n", partida->nivel);
    printf("       Operacao: %s\n", imprimirTipoOperacaoString(partida->tipoOperacao));
    printf("       Pontuacao: %d\n", partida->pontuacao);
    printf("       Tempo: "); imprimirTempo(partida->tempoPartida);
    printf("\n");
}

void rankingVazio(int tipoOperacao){

    int posicao = 1;

    if(tipoOperacao==MUITO_FACIL){

        printf("   ------------------------ MUITO FÁCIL ------------------------\n\n");

        while(posicao<=MAX_RANK){

            imprimirRankingVazio(posicao);
            ++posicao;
        }
    }

    if(tipoOperacao==FACIL){

        printf("   --------------------------- FÁCIL ---------------------------\n\n");

        while(posicao<=MAX_RANK){

            imprimirRankingVazio(posicao);
            ++posicao;
        }
    }

    if(tipoOperacao==MEDIO){

        printf("   --------------------------- MÉDIO ---------------------------\n\n");
       
        while(posicao<=MAX_RANK){

            imprimirRankingVazio(posicao);
            ++posicao;
        }
    }

    if(tipoOperacao==DIFICIL){

        printf("   -------------------------- DIFÍCIL --------------------------\n\n");
        
        while(posicao<=MAX_RANK){

            imprimirRankingVazio(posicao);
            ++posicao;
        }
    }

    if(tipoOperacao==MUITO_DIFICIL){

        printf("   ----------------------- MUITO DIFICIL -----------------------\n\n");
        
        while(posicao<=MAX_RANK){

            imprimirRankingVazio(posicao);
            ++posicao;
        }
    }
}

void imprimirRankingVazio(int posicao){

    printf("   #%d  Nome:\n", posicao);
    printf("       Nivel:\n");
    printf("       Operacao:\n");
    printf("       Pontuacao:\n");
    printf("       Tempo: ");
    printf("\n\n");
}

void imprimirPosicaoVazia(int posicao){

    printf("   #%d  Nome:\n", posicao);
    printf("       Nivel:\n");
    printf("       Operacao:\n");
    printf("       Pontuacao:\n");
    printf("       Tempo: ");
    printf("\n\n");
}

void arquivoRankingNull(){

    int posicao = 1;

    printf("   ------------------------ MUITO FÁCIL ------------------------\n\n");

    while(posicao<=MAX_RANK){

        imprimirRankingVazio(posicao);
        ++posicao;
    }

    posicao = 1;
    
    printf("   --------------------------- FÁCIL ---------------------------\n\n");
    
    while(posicao<=MAX_RANK){

        imprimirRankingVazio(posicao);
        ++posicao;
    }

    posicao = 1;
    
    printf("   --------------------------- MÉDIO ---------------------------\n\n");
    
    while(posicao<=MAX_RANK){

        imprimirRankingVazio(posicao);
        ++posicao;
    }

    posicao = 1;
    
    printf("   -------------------------- DIFÍCIL --------------------------\n\n");
    
    while(posicao<=MAX_RANK){

        imprimirRankingVazio(posicao);
        ++posicao;
    }

    posicao = 1;
    
    printf("   ----------------------- MUITO DIFICIL -----------------------\n\n");
    
    while(posicao<=MAX_RANK){

        imprimirRankingVazio(posicao);
        ++posicao;
    }
    
    char pausar;
    printf("\n\n\t\t   Tecle ENTER para continuar... ");
    scanf("%c", &pausar);
    getchar();

    iniciarMenu();
}