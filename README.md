<h1 align="center"> 🧠 Sobre o Jogo</h1>

<div align="center">
  <img src="celerebro.png" alt="Célerebro arte">
</div>

<br/>

**CÉLEREBRO** é um minigame que desenvolvi para praticar o conteúdo de programação que estava aprendendo na faculdade - e também porque gosto muito de jogos “neuróbicos”.

Tentei utilizar ao máximo diversos recursos que a poderosa linguagem C oferece, como estruturas de dados, alocação dinâmica, ponteiros, ordenação e manipulação de arquivos.

Com quase todo o sistema modelado, não gostei dos resultados da função geradora de números aleatórios. Por isso, decidi (re)começar praticamento do zero, utilizando outro método para tornar cada operação o mais esporádica possível. Para tal, fiz o uso de listas encadeadas e conceitos de produto cartesiano.

Muitas vezes, debugá-lo foi um desafio, pois não é fácil indentificar um erro de semântica, mas, graças ao _gdb_, corrigi vários problemas de _segmentation fault_. Apesar dos meus testes, pode ser que existam outros _bugs_ que deixei passar.

---

## :arrow_forward: Executando

Uma vez com o _gcc_ instalado, é só abrir o terminal na pasta **_codigo_**, onde se encontra o arquivo **_Makefile_**, e digitar o comando `make`. Assim, todos os módulos serão carregados.

Para rodar o executável gerado, basta digitar o comando `./main.x`.

Quem quiser ir além (no Linux)...

Para criar um comando para executar o jogo direto no terminal, de forma global:

1 - Criar um script com nome **_celerebro_** na pasta **_codigo_** com as seguintes linhas de comando:

```
#!/bin/bash
cd <endereço onde se encontra o ./main.x>
./main.x
```

Por exemplo:

```
#!/bin/bash
cd /home/danielbrito/games/celerebro/codigo
./main.x
```

2 - Copiar (ou mover) o script criado para a devida pasta:

```
sudo cp celerebro /usr/bin/
```

3 - Autorizar execução via linha de comando:

```
sudo chmod +x /usr/bin/celerebro
```

Pronto! Agora é só digitar o comando `celerebro` de qualquer diretório que o programa será executado.

---

## :video_game: Jogando

A tela de apresentação, bem como as outras "ilustrações" do jogo, foram todas geradas por um programa cujo algoritmo converte pixels em caracteres da tabela ASCII.

Após teclar ENTER, será exibido o menu principal, onde existem as opções de começar uma nova partida, verificar ranking, ler sobre neuróbica ou sair.

A opção principal é a "1 - Nova partida", pois ela leva a uma série de configurações que serão aplicadas nas operações a serem resolvidas, como tipo (adicão, subtração etc.), nível (fácil, médio, difícil etc.), bem como a quantidade de operações a serem respondidas.

Após o início da partida, as operações aparecem na tela e um cronômetro (em background) contabiliza o tempo.

Ao final, é exibido o resultado juntamente com uma lista de opções sobre o que fazer a seguir. Jogar novamente? Voltar ao menu? Exibir os erros? (Se houverem) Exibir ranking?

Se a opção escolhida for "Sair", é exibida uma tela de despedida com um incentivo para retornar uma próxima vez.

---

## :gear: Modificações

Para modificar o intervalo dos números em cada nível é só alterar os valores dos `#define` no arquivo **_operacao.c_**.

---

## :tv: Screencast

Configura o screencast [neste vídeo](https://www.youtube.com/watch?v=HTMflPqPcOY) que gravei para o meu canal.

![Video cover](./cover.jpg)

---

## :desktop_computer: Telas

<h3 align="center">Abertura</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/0%20-%20abertura.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Menu</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/1%20-%20menu.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Nova Partida - Operação</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/2%20-%20novaPartida_operacao.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Nova Partida - Nível</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/3%20-%20novaPartida_nivel.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Contagem</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/4%20-%20contagem.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Partida</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/5%20-%20partida.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Resultado</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/6%20-%20resultado.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Erros</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/7%20-%20erros.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Neuróbica</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/8%20-%20neurobica.png?raw=true" alt="Tela Célerebro"/>
</div>

//

<h3 align="center">Ranking</h3>

<div align="center">
  <img src="https://github.com/DanielBrito/celerebro/blob/master/prints/9%20-%20ranking.png?raw=true" alt="Tela Célerebro"/>
</div>
