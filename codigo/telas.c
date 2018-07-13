#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "telas.h"
#include "partida.h"

#define MAX 59

void telaIniciarJogo(){

    system("clear"); system("clear");

    printf("\n");

    printf("                     ,,#####################,\n");
    printf("                ,####################,,#######,\n");
    printf("              #########,,,,               ,########,\n");
    printf("          ,#######,###        ***********    ########,\n");
    printf("        ########    ###      ***********    ###  ,#####\n");
    printf("      ,#####,       ####,,  ***********   ####     ,#####,\n");
    printf("     ,####        ########  **********   ,##,      ########,\n");
    printf("     ####     #,   ,       *********           ,, ###   ####,\n");
    printf("   ,####     ,##          *********           #######,   ####,\n");
    printf("  ######,    ,#######,   *****************      ,, ,##,   #####,\n");
    printf(" ####,,################  ***************             ,     ,####\n");
    printf(" ###,    ,,#,,       ,  **************      ###,             ###,\n");
    printf(" ###                   ************** ,#,   ,####      ,,    ###,\n");
    printf(" #######,     ,#,            ******   ###      ##     ##########\n");
    printf(" ########     ###  ,####    ******    ###     ####,,    ,,#,####\n");
    printf(" ###,       ,#########      ****    ######,#########         ####\n");
    printf(" ####     #####  ,,        ***      ##  ######,     ###      ####\n");
    printf(" ####    ,##        ,##   ***   ,##                ,##      ,###,\n");
    printf("  ####,            ####  ***   ####    ,##     ,   ,##   ,,#####\n");
    printf("   ##########,,   ,##    *    ###      ###   #####,###########,\n");
    printf("    ,#################,,      ,##       ######################\n");
    printf("            ,################,###,     ,######, ,,#,,      ###,\n");
    printf("                     ,######################              ,###\n");
    printf("                         ,####,,#######,####            ,####,\n");
    printf("                          ####          ####          ,#####,\n");
    printf("                          ,###,         ,###,       ######,\n");
    printf("      D4n13l_8r1+0         ####          #####,,,#######,\n");
    printf("                            ####,         ,##########,\n");
    printf("       4pr353n+4:            ######,       #####,,,\n");
    printf("                              ,#######      ####\n");
    printf("    C É L 3 R 3 8 R 0            ,#####,     ####\n");
    printf("                                     #####,,,,####\n");
    printf("                                     ,##########,\n");
    printf("                                       ,######,\n\n\n\n");

    pausarTela();
}

void pausarTela(){

    printf("\t\t  Tecle ENTER para continuar... ");
    
    char pausar;
    scanf("%c", &pausar);
}

void telaMenu(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                          _---~~~~~-_,                         #\n");
    printf(" #                        _{ -, ???? ,- )                        #\n");
    printf(" #                      ,   )- ????  ,-´ )                       #\n");
    printf(" #                     (  `-, ???????? (`_,)                     #\n");
    printf(" #                    ( ` _+ (,  ???? - `+  }                    #\n");
    printf(" #                    (_-  _ ~_  ??? ,`, ,` )                    #\n");
    printf(" #                      `~ -^(,. ?? ;-,((/))                     #\n");
    printf(" #                            ~~+~-{_ -_(()                      #\n");
    printf(" #                                   `\\ }                        #\n");
    printf(" #                                    { }                        #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                                MENU\n");
    printf("                                ^^^^\n\n");
}

void telaNovaPartida(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                               *                               #\n");
    printf(" #                              ***                              #\n");
    printf(" #                              ***                              #\n");
    printf(" #                             *****                             #\n");
    printf(" #                       *****************                       #\n");
    printf(" #                          ***********                          #\n");
    printf(" #                            *******                            #\n");
    printf(" #                           *********                           #\n");
    printf(" #                          ***     ***                          #\n");
    printf(" #                          *         *                          #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                           NOVA PARTIDA\n");
    printf("                           ^^^^ ^^^^^^^\n\n");
}

void telaJogoCarregarEstatica(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                             .-.-.                             #\n");
    printf(" #                        ((  (__I__)  ))                        #\n");
    printf(" #                          .'_....._'.                          #\n");
    printf(" #                         / /   #   \\ \\                         #\n");
    printf(" #                        | |    |    | |                        #\n");
    printf(" #                        | | #  /  # | |                        #\n");
    printf(" #                        | |   /     | |                        #\n");
    printf(" #                         \\ \\   #   / /                         #\n");
    printf(" #                          '.`-...-'.'                          #\n");
    printf(" #                          '========='                          #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                            CARREGANDO\n");
    printf("                            ^^^^^^^^^^\n\n");

    printf("   [                                                           ]\n\n");

    nanosleep((const struct timespec[]){{0, 30000000L}}, NULL); 
}

void telaJogoCarregar(int t){

    int i, j;

    if(t>MAX){

        return;
    }
    else{

        system("clear"); system("clear");

        printf("\n");

        printf(" + ############################################################# -\n");
        printf(" #                                                               #\n");
        printf(" #                             .-.-.                             #\n");
        printf(" #                        ((  (__I__)  ))                        #\n");
        printf(" #                          .'_....._'.                          #\n");
        printf(" #                         / /   #   \\ \\                         #\n");
        printf(" #                        | |    |    | |                        #\n");
        printf(" #                        | | #  /  # | |                        #\n");
        printf(" #                        | |   /     | |                        #\n");
        printf(" #                         \\ \\   #   / /                         #\n");
        printf(" #                          '.`-...-'.'                          #\n");
        printf(" #                          '========='                          #\n");
        printf(" #                                                               #\n");
        printf(" * ############################################################# /\n\n");

        printf("                            CARREGANDO\n");
        printf("                            ^^^^^^^^^^\n\n");

        printf("   [");

        for(i=0; i<t; i++){

        	printf("#");
        }

        for(j=i; j<MAX; j++){

        	printf(" ");
        }

        printf("]\n\n");

        nanosleep((const struct timespec[]){{0, 30000000L}}, NULL); 
    }

    telaJogoCarregar(++t);
}

void telaJogoEspera(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                             .-.-.                             #\n");
    printf(" #                        ((  (__I__)  ))                        #\n");
    printf(" #                          .'_....._'.                          #\n");
    printf(" #                         / /   #   \\ \\                         #\n");
    printf(" #                        | |    |    | |                        #\n");
    printf(" #                        | | #  /  # | |                        #\n");
    printf(" #                        | |   /     | |                        #\n");
    printf(" #                         \\ \\   #   / /                         #\n");
    printf(" #                          '.`-...-'.'                          #\n");
    printf(" #                          '========='                          #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                             CÉLEREBRO\n");
    printf("                             ^^^^^^^^^\n\n");

    printf("                    Sua partida irá começar em:\n\n");

    int i;

    for(i=3; i>0; i--){

        printf("                                 %d\n\n", i);
        sleep(1);
    }
}

void telaJogo(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                            //////                             #\n");
    printf(" #                           //////                              #\n");
    printf(" #                          //////                               #\n");
    printf(" #                         /////////////                         #\n");
    printf(" #                        /////////////                          #\n");
    printf(" #                              /////                            #\n");
    printf(" #                             /////                             #\n");
    printf(" #                             ///                               #\n");
    printf(" #                            //                                 #\n");
    printf(" #                           /                                   #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                             CÉLEREBRO\n");
    printf("                             ^^^^^^^^^\n\n");
}

void telaResultado(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                                ´:`                            #\n");
    printf(" #                               ´:/`                            #\n");
    printf(" #                              ´:/:`                            #\n");
    printf(" #                             .///,                             #\n");
    printf(" #                           .://///::::-)                       #\n");
    printf(" #                     :///`////////////:-)                      #\n");
    printf(" #                     ////`////////////:`)                      #\n");
    printf(" #                     ////`////////////-)                       #\n");
    printf(" #                     //-:`///////////-)                        #\n");
    printf(" #                     `..`  `..........`                        #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                             RESULTADO\n");
    printf("                             ^^^^^^^^^\n\n");
}

void telaFimDeJogo(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                           /@@@@@@@@\\                          #\n");
    printf(" #                          /@@@@@@@@@@\\                         #\n");
    printf(" #                         |@@@    /@@@@                         #\n");
    printf(" #                         |@@@    /@@@@                         #\n");
    printf(" #                               /@@@@/                          #\n");
    printf(" #                              /@@@/                            #\n");
    printf(" #                              @@@/                             #\n");
    printf(" #                                                               #\n");
    printf(" #                              @@@@                             #\n");
    printf(" #                              @@@@                             #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                            FIM DE JOGO\n");
    printf("                            ^^^^^^^^^^^\n\n");
}

void telaErros(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                       xxxx          xxxx                      #\n");
    printf(" #                        xxxxx      xxxxx                       #\n");
    printf(" #                         xxxxxx  xxxxxx                        #\n");
    printf(" #                           xxxxxxxxxx                          #\n");
    printf(" #                             xxxxxx                            #\n");
    printf(" #                             xxxxxx                            #\n");
    printf(" #                           xxxxxxxxxx                          #\n");
    printf(" #                         xxxxxx  xxxxxx                        #\n");
    printf(" #                        xxxxx      xxxxx                       #\n");
    printf(" #                       xxxx          xxxx                      #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                               ERROS\n");
    printf("                               ^^^^^\n\n");
}

void telaRanking(){

    system("clear"); system("clear");

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                         '._==_==_=_.'                         #\n");
    printf(" #                         .-\\:      /-.                         #\n");
    printf(" #                        | (|:.     |) |                        #\n");
    printf(" #                         '-|:. *   |-'                         #\n");
    printf(" #                           \\::.    /                           #\n");
    printf(" #                            '::. .'                            #\n");
    printf(" #                              ) (                              #\n");
    printf(" #                            _.' '._                            #\n");
    printf(" #                           '''''''''                           #\n");
    printf(" #                           '''''''''                           #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                              RANKING\n");
    printf("                              ^^^^^^^\n\n");
}

void telaNeurobica(){

    system("clear"); system("clear");

    char pausar;

    printf("\n");

    printf(" + ############################################################# -\n");
    printf(" #                                                               #\n");
    printf(" #                     .+++*/         /*+++.                     #\n");
    printf(" #                   --*|  /|         |/  |*--                   #\n");
    printf(" #                   |-+|  :|         |:  |+-|                   #\n");
    printf(" #                -+|+ /|  :+++++++++++:  |/ +|+-                #\n");
    printf(" #                -+|+ /|  /|         |/  |/ +|+-                #\n");
    printf(" #                -+|+ /|  :+++++++++++/  |/ +|+-                #\n");
    printf(" #                   + /|  /|         |:  |+ /                   #\n");
    printf(" #                   --+|  /|         |/  |+--                   #\n");
    printf(" #                     .+++*/         /*+++.                     #\n");
    printf(" #                       ```           ```                       #\n");
    printf(" #                                                               #\n");
    printf(" * ############################################################# /\n\n");

    printf("                             NEURÓBICA\n");
    printf("                             ^^^^^^^^^\n\n");

    printf("    O termo neuróbica foi criado pelo neurocientista Larry Katz\n");
    printf("      e, como se trata do cérebro, tem como princípio a velha\n");
    printf("      máxima \"use-o ou perca-o\". Isso acontece pois, quanto\n");
    printf("   mais ativas, as diferentes regiões do nosso cérebro, bem como\n");
    printf("           suas conexões, ficam mais fortes e saudáveis.\n\n");

    printf("     É uma prática que, além de estimular os sentidos por meio\n");
    printf("        de certas atividades, fazendo com que prestemos mais\n");
    printf("     atenção nas nossas ações, consiste também na resolução de\n");
    printf("       exercícios de raciocínio lógico ou qualquer outro que\n");
    printf("         desenvolva a nossa memória e capacidade cognitiva.\n\n");

    printf("     Katz explica que o declínio das funções mentais pode não\n");
    printf("        resultar da morte de células nervosas, que ocorre,\n");
    printf("    inevitavelmente, com a idade, mas sim da redução do número\n");
    printf("      de conexões entre elas. Os exercícios, portanto, servem\n");
    printf("        para estimular a formação de sinapses - regiões dos\n");
    printf("        neurônios responsáveis pela transmissão de impulsos\n");
    printf("                    nervosos entre as células.\n\n\n");

    printf("                    Tecle ENTER para voltar... ");

    scanf("%c", &pausar);
    getchar();

    iniciarMenu();
}

void telaSair(){

    system("clear"); system("clear");

    printf("\n");

    printf("                                ```        .`.`.\n");
    printf("                              `#####.     -#####`\n");
    printf("                              -######    `######-\n");
    printf("                              -######`   .######.\n");
    printf("                              .######.   -######`\n");
    printf("                              `######.   .######\n");
    printf("                               ######-   ######.\n");
    printf("                               ######.  `######-\n");
    printf("                               .######  .######.\n");
    printf("                               -######  -######\n");
    printf("                        ..`.`. .######` .######\n");
    printf("                 .`.`. .###### .######. ######.\n");
    printf("                `#####-.######.`######-`######-\n");
    printf("                .######-######--######..######`\n");
    printf("                .######-######..##############\n");
    printf("                .######.#######-##############\n");
    printf("                .######..######-#############-\n");
    printf("                .#####...######-#######.......-`\n");
    printf("                ......###......#####...#########.`\n");
    printf("                .##################.#############.\n");
    printf("                .#################-###############`\n");
    printf("                .#################-#######..######\n");
    printf("                -#################........#######.\n");
    printf("                .################################.\n");
    printf("                `###############################.\n");
    printf("                 .#############################.\n");
    printf("                  -###########################-\n");
    printf("                   .#########################.\n");
    printf("                    `-......................\n");
    printf("                  ..#######################..\n");
    printf("                 `###########################\n");
    printf("                  .#########################.\n");
    printf("                   `-----------------------`\n");
    printf("                    '----------------------'\n\n\n");

    printf("                         ATÉ A PRÓXIMA!\n");
    printf("                         ^^^ ^ ^^^^^^^^\n\n");

    sleep(2);

    system("clear"); system("clear");
}