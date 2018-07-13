# Sobre o jogo

CÉLEREBRO é um minigame que estou desenvolvendo para praticar o conteúdo de programação que aprendo. Também porque gosto muito de jogos “neuróbicos”.

Este é apenas um protótipo de um projeto maior, que contará com diversos outros módulos, interface gráfica e tudo mais. No entanto, para que tal jogo possa sair inteiramente do papel, preciso estudar muitas outras ferramentas que me auxiliem neste processo criativo.

Neste caso, tentei utilizar ao máximo os recursos que a (poderosa) linguagem C oferece, desde a manipulação de arquivos até estrutudas de dados e ordenação. Muitas vezes, debugá-lo foi um desafio. Não é fácil indentificar um erro de semântica. E, graças ao gdb, corrigi vários problemas de segmentation fault.

Com quase todo o sistema modelado, não gostei dos resultados da função geradora de números aleatórios. Por isso, tive que começar praticamento do zero, utilizando um método para tornar cada operação o mais esporádica possível, logo, fiz o uso de listas encadeadas e conceitos de produto cartesiano.

Apesar dos meus testes, pode ser que existam outros bugs que eu deixei passar. Mas estes eu vou corrigindo no decorrer dos meus treinos diários...

# Instruções

Uma vez com o gcc instalado, é só abrir o terminal na pasta "codigo", onde se encontra o arquivo "Makefile", e digitar o comando make. Assim, todos os módulos serão carregados. Para rodar o executável, que foi gerado na operação anterior, basta digitar o comando ./main.x
