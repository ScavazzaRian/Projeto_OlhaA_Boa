# Projeto Bingo - Estrutura de Dados

Este projeto foi desenvolvido para a disciplina de **Estrutura de Dados** na FATEC em 2024, utilizando a linguagem de programação **C++**. O objetivo principal é simular um jogo de bingo.

---

## 🔍 **Descrição do Projeto**
O projeto consiste em criar e gerenciar cartelas de bingo. Cada cartela é composta por 5 colunas representadas pelos vetores `B`, `I`, `N`, `G` e `O`, onde cada coluna armazena números específicos. O programa oferece funcionalidades como a criação de cartelas, exibição e armazenamento em arquivos.

---

## 📋 **Funcionalidades**
1. **Criar Cartelas**  
   - Gera até 10 cartelas de bingo únicas.
   - Preenche os números de cada coluna de acordo com as regras do jogo de bingo:
     - **B:** Números entre 1 e 15.
     - **I:** Números entre 16 e 30.
     - **N:** Números entre 31 e 45 (com um espaço central `FREE` na terceira posição).
     - **G:** Números entre 46 e 60.
     - **O:** Números entre 61 e 75.
   - Cada cartela criada é salva automaticamente em um arquivo `Cartela_X.txt`, onde `X` é o número da cartela.

2. **Exibir Cartelas Criadas**  
   - Permite visualizar no console todas as cartelas criadas.

3. **Salvar Arquivo**  
   - As cartelas são armazenadas em arquivos de texto no formato tabular.

4. **Menu Interativo**  
   - Menu interativo com 3 opções.

---

## 🛠️ **Tecnologias Utilizadas**
- Linguagem de Programação: **C++**
- Estruturas de Dados:
  - Vetores (arrays).
  - Estruturas (`struct`) para representar números e cartelas.
- Manipulação de Arquivos:
  - Uso da biblioteca `<fstream>` para criação e gravação de arquivos.

---