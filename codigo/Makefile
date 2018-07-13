all: main.x

celerebro.o: celerebro.c
	gcc -c celerebro.c -g

conversao.o: conversao.c
	gcc -c conversao.c -g
	
operacao.o: operacao.c
	gcc -c operacao.c -g	
	
partida.o: partida.c
	gcc -c partida.c -g

telas.o: telas.c
	gcc -c telas.c -g

main.x: celerebro.o conversao.o operacao.o partida.o telas.o
	gcc -o main.x celerebro.o conversao.o operacao.o partida.o telas.o

clean:
	rm -f *.x *.o
