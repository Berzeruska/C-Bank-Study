#include <stdio.h> // Biblioteca padrão para entrada e saída.

// 1. GESTÃO DE MEMÓRIA E SEGURANÇA: Limpando o buffer
// Criei esta função para evitar um bug clássico do C. 
// Se o usuário digitar uma letra em vez de número, o 'scanf' surta e cria um loop infinito.
// Essa função varre e limpa o "lixo" deixado na memória de entrada do teclado.
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 2. ARTE ASCII
// Coloquei a arte em uma função separada para não poluir o main.
void imprimir_arte() {
    printf("\n");
    printf("    _________________\n");
    printf("   /                 \\\n");
    printf("  /   BANCO FARADAY   \\\n");
    printf(" /_____________________\\\n");
    printf("  |  [ $ ]   [ $ ]  |\n");
    printf("  |  ___      ___   |\n");
    printf("  | |   |    |   |  |\n");
    printf("  |_|___|____|___|__|\n\n");
}

// 3. FUNÇÃO DE SALDO
// Aqui passo o saldo "por valor" (uma cópia), pois só quero visualizar, não alterar.
void mostrar_saldo(double saldo) {
    printf("\n[💰] Seu saldo atual e: R$ %.2f\n", saldo);
}

// 4. FUNÇÃO DE DEPÓSITO
// Uso um ponteiro (*saldo) para acessar e modificar a variável original lá no main.
// Essa é uma ótima prática de gestão de memória, pois evito o uso perigoso de "variáveis globais".
void realizar_deposito(double *saldo) {
    double valor;
    printf("\nValor do deposito: R$ ");
    
    // Verifico se a entrada é válida (se o usuário realmente digitou um número).
    if (scanf("%lf", &valor) != 1) {
        printf("[❌] Erro de entrada! Digite apenas numeros.\n");
        limpar_buffer();
        return; // Saio da função antes de fazer besteira no saldo.
    }

    // Correção da vulnerabilidade: Impeço depósitos negativos ou zerados!
    if (valor <= 0) {
        printf("[❌] Operacao bloqueada: O valor do deposito deve ser maior que zero.\n");
    } else {
        *saldo += valor; // Uso o ponteiro para somar direto na memória original.
        printf("[✅] Deposito de R$ %.2f realizado com sucesso!\n", valor);
    }
}

// 5. FUNÇÃO DE SAQUE
// Novamente, uso ponteiro (*saldo) porque preciso alterar a conta.
void realizar_saque(double *saldo) {
    double valor;
    printf("\nValor do saque: R$ ");
    
    if (scanf("%lf", &valor) != 1) {
        printf("[❌] Erro de entrada! Digite apenas numeros.\n");
        limpar_buffer();
        return;
    }

    // Proteção Dupla de Segurança Bancária:
    // 1. O saque não pode ser negativo (senão funcionaria como um depósito falso).
    // 2. O saque não pode ser maior que o saldo disponível.
    if (valor <= 0) {
        printf("[❌] Operacao bloqueada: O valor do saque deve ser maior que zero.\n");
    } else if (valor > *saldo) {
        printf("[❌] Operacao negada: Saldo insuficiente! Voce tem R$ %.2f disponiveis.\n", *saldo);
    } else {
        *saldo -= valor;
        printf("[✅] Saque de R$ %.2f realizado com sucesso!\n", valor);
    }
}

// --- FUNÇÃO PRINCIPAL ---
int main() {
    double saldo = 0.0; 
    int opcao; 

    imprimir_arte();
    printf("--- Bem-vindo ao Sistema Bancario Seguro ---\n");

    while(1) {
        printf("\n=========================\n");
        printf("1. Saldo\n2. Depositar\n3. Sacar\n4. Sair\n");
        printf("Escolha uma opcao: ");
        
        // Proteção do menu: Se digitar uma letra, o 'scanf' falha e retorna algo diferente de 1.
        if (scanf("%d", &opcao) != 1) {
            printf("[❌] Opcao invalida! Por favor, digite um numero de 1 a 4.\n");
            limpar_buffer();
            continue; // Pula o resto do loop e mostra o menu de novo.
        }

        if(opcao == 4) {
            break; 
        }

        // Agora meu switch ficou extremamente limpo e elegante!
        // Ele apenas chama as funções especialistas que eu criei acima.
        switch(opcao) {
            case 1:
                mostrar_saldo(saldo);
                break;
            case 2:
                // Passo o ENDEREÇO da variável na memória usando o '&' (E comercial).
                realizar_deposito(&saldo);
                break;
            case 3:
                realizar_saque(&saldo);
                break;
            default:
                printf("[❌] Opcao invalida!\n");
        }
    }

    printf("\n[👋] Obrigado por usar o Banco Faraday! Ate logo!\n");
    
    return 0; 
}
