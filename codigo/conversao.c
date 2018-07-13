#include <stdio.h>
#include <stdlib.h>

enum opNum {ADICAO=1, SUBTRACAO=2, MULTIPLICACAO=3, DIVISAO=4};
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

    if(tipoOperacao==1){

       return "Adição [+]";
    }
    if(tipoOperacao==2){

        return "Subtração [-]";
    }
    if(tipoOperacao==3){

        return "Multiplicação [*]";
    }
    if(tipoOperacao==4){

        return "Divisão [/]";
    }
    if(tipoOperacao==5){

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
		minutos = 0;
	}

	printf("%.2d:%.2d:%.2d\n", horas, minutos, segundos);
}