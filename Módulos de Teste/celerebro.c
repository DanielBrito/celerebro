#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 10

int gera_operacao();
int gera_numero();

int main(){
	
    int i;
    int resposta = 0, cont_acerto = 0, resultado = 0;
    int num1 = 0, num2 = 0, num3 = 0;
    char operacao;

    for(i=0; i<MAX; i++){
    	
        num1 = gera_numero();
        num2 = gera_numero() + gera_numero();

        operacao = gera_operacao();

        if(operacao == '+'){
        	
            resultado = num1 + num2;
        }
        else
        if(operacao == '-'){
        	
            resultado = num1 - num2;
        }
        else{
        	
            resultado = num1 * num2;
        }

        printf("OPERACAO #%d: %d %c %d = ", i+1, num1, operacao, num2);
        scanf("%d", &resposta);

        if(resposta == resultado){
        	
            cont_acerto++;
        }
    }
    
    printf("\n\n");
    
    printf("PONTUACAO: %d de %d.", cont_acerto, MAX);

    printf("\n\n");

    return 0;
}


int gera_numero(){
	
    int num = 0;

    srand(time(NULL));

    num = (rand()%10);

    return num;
}

int gera_operacao(){
	
    int op = 0;

    srand(time(NULL));

    op = (rand()%3);

    if(op == 0){
    	
        return '+';
    }
    else
    if(op == 1){
    	
        return '-';
    }
    else{
    	
        return '*';
    }
}
