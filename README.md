# SOBRE O JOGO

CÉLEREBRO é um minigame que estou desenvolvendo para praticar o conteúdo de programação que aprendo, e também porque gosto muito de jogos “neuróbicos”.

Este é apenas um protótipo de um projeto maior, que contará com diversos outros módulos, interface gráfica e tudo mais. No entanto, para que tal jogo possa sair inteiramente do papel, preciso estudar muitas outras ferramentas que me auxiliem neste processo criativo.

Neste caso, tentei utilizar ao máximo os recursos que a poderosa linguagem C oferece, desde a manipulação de arquivos até estruturas de dados e ordenação. 

Muitas vezes, debugá-lo foi um desafio, pois não é fácil indentificar um erro de semântica. Mas, graças ao gdb, corrigi vários problemas de segmentation fault.

Com quase todo o sistema modelado, não gostei dos resultados da função geradora de números aleatórios. Assim, tive que começar praticamento do zero, utilizando outro método para tornar cada operação o mais esporádica possível. Para isso, fiz o uso de listas encadeadas e conceitos de produto cartesiano.

Apesar dos meus testes, pode ser que existam outros bugs que deixei passar. Mas estes eu vou corrigindo no decorrer dos meus treinos diários...

# EXECUTANDO

Uma vez com o gcc instalado, é só abrir o terminal na pasta ***codigo***, onde se encontra o arquivo ***Makefile***, e digitar o comando `make`. Assim, todos os módulos serão carregados. Para rodar o executável gerado, basta digitar o comando `./main.x`.

Quem quiser ir além...

Para criar um comando para executar o jogo direto no terminal, de forma global:

1 - Criar um script com nome ***celerebro*** na pasta ***codigo*** com as seguintes linhas de comando:

```
#!/bin/bash
cd <endereço onde se encontra o ./main.x>
./main.x
```

2 - Copiar script criado para a devida pasta:

```
sudo cp celerebro /usr/bin/
```
3 - Autorizar execução via linha de comando:

```
sudo chmod +x /usr/bin/celerebro
```

Pronto! Agora é só digitar o comando `celerebro` de qualquer diretório que o programa será executado.

# JOGANDO

A tela de apresentação, bem como as outras "ilustrações" do jogo, foram todas geradas por um programa cujo algoritmo converte pixels em caracteres da tabela ASCII.

Após teclar ENTER, será exibido o Menu Principal, onde existem as opções de começar uma nova partida, verificar ranking, ler sobre neuróbica ou sair.

A opção principal é a "1 - Nova partida", pois ela leva a uma série de configurações que serão aplicadas nas operações a serem resolvidas, como tipo (adicão, subtração etc.), nível (fácil, médio, difícil etc.), bem como a quantidade de operações a serem respondidas. 

Após o início da partida, as operações aparecem na tela e um cronômetro (em background) contabiliza o tempo. Ao final, é exibido o resultado juntamente com uma lista de opções sobre o que fazer a seguir. Jogar novamente? Voltar ao menu? Exibir os erros? (Se houverem) Exibir ranking? Se a opção escolhida for "Sair", é exibida uma tela de despedida com um incentivo para retornar uma próxima vez.

# MODIFICAÇÕES

Para modificar o intervalo dos números em cada nível é só alterar os valores dos #define's no arquivo ***operacao.c***. No entanto, para valores muitos altos, o consumo de memória para criar as listas tende a aumentar. Analise o processo no System Monitor.

# TELAS

### Abertura

![](https://github.com/DanielBrito/celerebro/blob/master/prints/0%20-%20abertura.png)

### Menu

![](https://github.com/DanielBrito/celerebro/blob/master/prints/1%20-%20menu.png)

### Nova Partida - Operação

![](https://github.com/DanielBrito/celerebro/blob/master/prints/2%20-%20novaPartida_operacao.png)

### Nova Partida - Nível

![](https://github.com/DanielBrito/celerebro/blob/master/prints/3%20-%20novaPartida_nivel.png)

### Contagem

![](https://github.com/DanielBrito/celerebro/blob/master/prints/4%20-%20contagem.png)

### Partida

![](https://github.com/DanielBrito/celerebro/blob/master/prints/5%20-%20partida.png)

### Resultado

![](https://github.com/DanielBrito/celerebro/blob/master/prints/6%20-%20resultado.png)

### Erros

![](https://github.com/DanielBrito/celerebro/blob/master/prints/7%20-%20erros.png)

### Neuróbica

![](https://github.com/DanielBrito/celerebro/blob/master/prints/8%20-%20neurobica.png)

### Ranking

![](https://github.com/DanielBrito/celerebro/blob/master/prints/9%20-%20ranking.png)
