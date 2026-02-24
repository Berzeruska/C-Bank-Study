# Sistema Bancário em C (v2.0) - Seguro e Modular 🏦🔐

Este projeto é uma evolução do meu estudo de programação estruturada em **Linguagem C**. Nesta versão v2.0, o foco principal foi sair do básico e aplicar conceitos reais de engenharia de software: **segurança de dados, tratamento de exceções, gestão de memória com ponteiros e modularidade**.



## 🚀 O que há de novo nesta versão?

* **Modularização (Clean Code):** A função `main` agora atua apenas como um controlador (menu). Toda a regra de negócio foi dividida em funções especialistas (`realizar_saque`, `realizar_deposito`, etc.).
* **Uso de Ponteiros (`*` e `&`):** Implementação de passagem de parâmetros por referência. As funções de transação alteram o saldo diretamente no endereço de memória original, evitando o uso de variáveis globais perigosas.
* **Tratamento de Exceções (Input Seguro):** Criação da função `limpar_buffer()` para evitar loops infinitos caso o usuário digite letras (char) em vez de números (int/double).
* **Regras de Negócio Rígidas:** Bloqueio de valores negativos para saques e depósitos, impedindo fraudes matemáticas no sistema.
* **Interface Visual:** Adição de ASCII Art para melhorar a experiência do usuário no terminal.

## 🧠 Conceitos e Sintaxe Aplicados

* Manipulação de endereços de memória.
* Prevenção de *Buffer Overflow* / Falhas no `scanf`.
* Estruturas de controle (`switch/case`, `while`, `if/else`).
* Escopo de variáveis (locais vs. ponteiros).

## 🛠️ Como Executar

Para testar o sistema, você precisará de um compilador C (como o GCC) instalado na sua máquina.

1. Clone este repositório:
   ```bash
   git clone [https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git](https://github.com/SEU_USUARIO/SEU_REPOSITORIO.git)
2. Compile o código:
    '''bash

gcc sistema_bancario.c -o sistema_bancario

3. Execute:
    '''bash

./sistema_bancario
