#include <stdio.h>
#include <stdlib.h>

enum opNum {ADICAO=1, SUBTRACAO=2, MULTIPLICACAO=3, DIVISAO=4, ALEATORIA=5};
enum nivelOp {MUITO_FACIL=1, FACIL=2, MEDIO=3, DIFICIL=4, MUITO_DIFICIL=5};

char* imprimirNivel(int nivel){

    if(nivel==MUITO_FACIL){

       return "Muito fácil";
    }
    if(nivel==FACIL){

        return "Fácil";
    }
    if(nivel==MEDIO){

        return "Médio";
    }
    if(nivel==DIFICIL){

        return "Difícil";
    }
    if(nivel==MUITO_DIFICIL){

        return "Muito difícil";
    }
}

char* imprimirTipoOperacaoString(int tipoOperacao){

    if(tipoOperacao==ADICAO){

       return "Adição [+]";
    }
    if(tipoOperacao==SUBTRACAO){

        return "Subtração [-]";
    }
    if(tipoOperacao==MULTIPLICACAO){

        return "Multiplicação [*]";
    }
    if(tipoOperacao==DIVISAO){

        return "Divisão [/]";
    }
    if(tipoOperacao==ALEATORIA){

        return "Aleatória [+-/*]";
    }
}

char imprimirTipoOperacaoChar(int tipoOperacao){

    if(tipoOperacao==ADICAO){

       return '+';
    }
    if(tipoOperacao==SUBTRACAO){

        return '-';
    }
    if(tipoOperacao==MULTIPLICACAO){

        return '*';
    }
    if(tipoOperacao==DIVISAO){

        return '/';
    }
}

void imprimirTempo(long int tempoPartida){

  int horas=0, minutos=0, segundos=0;

	minutos = tempoPartida/60;
	segundos = tempoPartida%60;

	if(minutos>60){

		horas = minutos/60;
		minutos = minutos%60;
	}

	printf("%.2d:%.2d:%.2d\n", horas, minutos, segundos);
}
