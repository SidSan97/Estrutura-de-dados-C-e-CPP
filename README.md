# Estrutura-de-dados-C-e-CPP
Repositório com códigos de exercícios e provas da disciplina Estrutura de Dados I pelo semestre 2021.1 pela UFBA 

<H2>1. Lista, Fila e Pilha</H2>

<h4>Questão 1 - Concatenação</h4>
<p>
  Considere uma implementação de lista encadeada com cabeça e sem cauda que armazena valores reais. Implemente a função <i>conc</i>, que concatena duas listas L1 e L2 passadas como parâmetro, intercalando seus elementos. Ao final, imprima o resultado na tela.

Exemplo:

L1: 1.2 3.5 9.78

L2: 5 2.9

Saída: 1.2 5 3.5 2.9 9.78
  </p>
  <hr>
  
  <h4>Questão 2 - Insere em ordem</h4>
  <p>
  Implemente uma lista duplamente encadeada com elementos que armazenem valores inteiros. Além disso, implemente uma função que recebe um vetor de inteiros e os insere na lista de maneira ordenada. Observação: seu algoritmo não pode recomeçar a partir da cabeça a busca pela posição correta após cada inserção na lista, exceto na primeira inserção. Ex.:

Lista atual: [0 1 3 5 6] Inserir vetor: [4 2 7]

Para inserir o elemento 4, a busca deve começar a partir do elemento 0. Ao inserir o elemento 4 após o 3 [0 1 3 4 5 6], o algoritmo não deve voltar para o primeiro elemento 0 para buscar a posição do valor 2 que será inserido na sequência. O algoritmo deve fazer essa inserção usando o encadeamento para trás.
  </p>
  <hr>
  
  <h4>Questão 3 - Lista Circular</h4>
  <p>
  A turma de ED estava “batendo um baba” na praia quando um novo estudante chegou e disse “15 minutos, 2 gols!”. Após 15 minutos, o time que perdeu de 1x0 precisou escolher alguém para sair. Para decidir qual estudante deveria dar o lugar, todos do time perdedor fizeram um círculo e cada um disse um número aleatório de 0-5. Somaram, então, os números dos estudantes e, em seguida, escolheram alguém do círculo para começar a contagem. A partir desse estudante, no sentido horário, começaram a contar até chegar na soma total. A pessoa, na qual a contagem finalizou, deveria dar o lugar ao estudante que chegou.

Exemplo de entrada: [5 0 2 0 4 3] //números aleatórios escolhidos pelos estudantes time perdedor 3 //posição que deve iniciar a contagem. Posições: [0 1 2 3 4 5]

Execução [ 0 1 2 3 4 5] [ 1 2 3] [ 4 5 6 7 8 9] [10 11 12 13 14 ]

Saída: 4 // a pessoa que estava na posição 4 deve dar lugar ao novo estudante
  </p>
  <hr>
  
  <h4>Questão 4 - Pilha</h4>
  <p>
  Implemente uma pilha e suas funções de empilhar e desempilhar. Em seguida, implemente uma função que retorne uma a pilha cujo topo contém o elemento que estava na base. Utilize uma pilha auxiliar para resolver o problema. Exemplo:

Entrada
[ 4]
[17]
[ 9]
[23]

Saída [23]
[ 4]
[17]
[ 9]
  </p>
  <hr>
  
  <H2>2. Árvore Binária, Heap</H2>
  <hr>
  <h4>Questão 1 - Heap</h4>
  <hr>
   <h4>Questão 2 - Árvore Binária Estática</h4>
  <hr>
   <h4>Questão 3 - Heap + Largura</h4>
  <hr>
   <h4>Questão 4 - Heap + Profundidade</h4>
  <hr>
  
   <H2>3. Ordenação</H2>
  <hr>
  <h4>Questão 1 - Selection Sort</h4>
  <hr>
   <h4>Questão 2 - Insertion Sort</h4>
  <hr>
   <h4>Questão 3 - Bubble Sort</h4>
  <hr>
   <h4>Questão 4 - Quicksort</h4>
  <hr>
  
