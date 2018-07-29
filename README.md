# Sobre o jogo

CÉLEREBRO é um minigame que estou desenvolvendo para praticar o conteúdo de programação que aprendo. Também porque gosto muito de jogos “neuróbicos”.

Este é apenas um protótipo de um projeto maior, que contará com diversos outros módulos, interface gráfica e tudo mais. No entanto, para que tal jogo possa sair inteiramente do papel, preciso estudar muitas outras ferramentas que me auxiliem neste processo criativo.

Neste caso, tentei utilizar ao máximo os recursos que a (poderosa) linguagem C oferece, desde a manipulação de arquivos até estruturas de dados e ordenação. Muitas vezes, debugá-lo foi um desafio. Não é fácil indentificar um erro de semântica. E, graças ao gdb, corrigi vários problemas de segmentation fault.

Com quase todo o sistema modelado, não gostei dos resultados da função geradora de números aleatórios. Tive que começar praticamento do zero, utilizando outro método para tornar cada operação o mais esporádica possível. Para isso, fiz o uso de listas encadeadas e conceitos de produto cartesiano.

Apesar dos meus testes, pode ser que existam outros bugs que deixei passar. Mas estes eu vou corrigindo no decorrer dos meus treinos diários...

# Executando

Uma vez com o gcc instalado, é só abrir o terminal na pasta "codigo", onde se encontra o arquivo "Makefile", e digitar o comando "make". Assim, todos os módulos serão carregados. Para rodar o executável gerado, basta digitar o comando "./main.x".

Além disso...

Para criar um comando para executar o jogo direto no terminal:

1 - Criar um script com nome "celerebro" na pasta "codigo" com as seguintes linhas de comando:

`#!/bin/bash`
`cd <endereço onde se encontra o ./main.x>`
`./main.x`

2 - Copiar script criado para a pasta /usr/bin/:

`sudo cp celerebro /usr/bin/`

Pronto! Agora é só digitar o comando celerebro de qualquer diretório que o programa será executado.

# Jogando

A tela de apresentação, bem como as outras "ilustrações" do jogo, foram todas geradas por um programa cujo algoritmo converte pixels em caracteres da tabela ASCII, bem divertido por sinal.

Após teclar ENTER, será exibido o menu principal, onde existem as opções de começar uma nova partida, verificar ranking, ler sobre neuróbica ou sair.

A opção principal é a "1 - Nova partida", pois ela leva a uma série de configurações que serão aplicadas nas operações a serem resolvidas, como tipo (adicão, subtração etc.), nível (fácil, médio, difícil etc.), bem como a quantidade de operações a serem respondidas. 

Após o início da partida, as operações aparecem na tela e um cronômetro (em background) contabiliza o tempo. Ao final, é exibido o resultado juntamente com uma lista de opções sobre o que fazer a seguir. Jogar novamente? Voltar ao menu? Exibir os erros? (Se houverem)? Exibir ranking? Se a opção escolhida for "Sair", é exibida uma tela de despedida com um incentivo para retornar uma próxima vez.

# Modificações

Para modificar o intervalo dos números em cada nível é só alterar os valores dos #define's no arquivo "operacao.c". No entanto, para valores muitos altos, o consumo de memória para criar as listas (com aplicação do produto cartesiano) tende a aumentar.
