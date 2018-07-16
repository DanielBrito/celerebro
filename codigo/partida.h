#include "operacao.h"

typedef struct partida Partida;
typedef struct listapartidas ListaPartidas;

void iniciarJogo();
void iniciarMenu();
void novaPartida();
ListaErros* iniciarPartida(int* pontuacao, Partida* p, ListaOperacoes* operacoes);
void imprimirResultado(Partida* p);
Partida* criarPartida(char* nome, int nivel, int operacao, int pontuacao, long int tempoPartida);
ListaPartidas* inserirPartida(ListaPartidas* partidas, Partida* novaPartida);
ListaPartidas* criarListaPartidas();

void cadastrarRanking(Partida* p);
void mostrarRanking();
ListaPartidas* carregarRanking();
void liberarListaRanking(ListaPartidas* partidas);
void imprimirRanking(ListaPartidas* partidas);
ListaPartidas* filtrarRanking(ListaPartidas* partidas, int nivel);
ListaPartidas* ordenarRanking(ListaPartidas* partidas);
int contaNos(ListaPartidas* partidas);
void imprimirPosicaoRanking(Partida* partida, int posicao);
void imprimirRankingVazio(int posicao);
void rankingVazio(int tipoOperacao);
void arquivoRankingNull();
int listaVazia(ListaPartidas* partidas);