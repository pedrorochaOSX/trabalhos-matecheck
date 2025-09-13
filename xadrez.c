#include <stdio.h>

// Desafio de Xadrez - MateCheck - Nível Mestre
// Sistema completo de movimentação de peças usando recursão e loops complexos

// Constantes que definem o número de casas que cada peça pode se mover
const int BISPO_CASAS = 5;    // Bispo move 5 casas na diagonal
const int TORRE_CASAS = 5;    // Torre move 5 casas horizontalmente
const int RAINHA_CASAS = 8;   // Rainha move 8 casas

// Função recursiva para movimentar o Bispo na diagonal (direita e cima)
void moverBispoRecursivo(int casasRestantes) {
    // Condição de parada da recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Movimento diagonal: uma casa para direita e uma para cima
    printf("Cima\n");
    printf("Direita\n");
    
    // Chamada recursiva com uma casa a menos
    moverBispoRecursivo(casasRestantes - 1);
}

// Função recursiva para movimentar a Torre horizontalmente (apenas direita)
void moverTorreRecursivo(int casasRestantes) {
    // Condição de parada da recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Movimento horizontal: uma casa para a direita
    printf("Direita\n");
    
    // Chamada recursiva com uma casa a menos
    moverTorreRecursivo(casasRestantes - 1);
}

// Função recursiva para movimentar a Rainha horizontalmente (esquerda)
void moverRainhaRecursivo(int casasRestantes) {
    // Condição de parada da recursão
    if (casasRestantes <= 0) {
        return;
    }
    
    // Movimento horizontal: uma casa para a esquerda
    printf("Esquerda\n");
    
    // Chamada recursiva com uma casa a menos
    moverRainhaRecursivo(casasRestantes - 1);
}

// Função para movimentar o Bispo usando loops aninhados (conforme requisito do Mestre)
// Loop externo: vertical, loop interno: horizontal
void moverBispoLoopsAninhados() {
    printf("=== Movimentação do Bispo com Loops Aninhados ===\n");
    
    // Loop externo: controla o movimento vertical (5 movimentos)
    for (int vertical = 0; vertical < BISPO_CASAS; vertical++) {
        // Loop interno: controla o movimento horizontal (1 movimento por vertical)
        for (int horizontal = 0; horizontal < 1; horizontal++) {
            printf("Cima\n");
            printf("Direita\n");
        }
    }
}

// Função para movimentar o Cavalo em formato L usando loops complexos (Nível Mestre)
// Cavalo move em L: 2 casas para cima + 1 casa para direita
void moverCavaloComplexo() {
    printf("=== Movimentação do Cavalo em L (Nível Mestre: 2 cima + 1 direita) ===\n");
    
    // Loop externo: controla as etapas do movimento em L
    for (int etapa = 1; etapa <= 2; etapa++) {
        // Loop interno: controla as repetições e condições múltiplas
        for (int movimento = 1; movimento <= 3; movimento++) {
            
            // Primeira etapa: mover 2 casas para cima
            if (etapa == 1) {
                if (movimento > 2) {
                    break;  // Sai do loop quando já moveu 2 casas para cima
                }
                printf("Cima\n");
                continue;  // Continua para a próxima iteração
            }
            
            // Segunda etapa: mover 1 casa para direita
            if (etapa == 2) {
                if (movimento > 1) {
                    break;  // Sai do loop quando já moveu 1 casa para direita
                }
                printf("Direita\n");
                continue;  // Continua para a próxima iteração
            }
        }
    }
}

// === FUNÇÕES DO NÍVEL AVENTUREIRO (para comparação) ===

// Função para movimentar o Cavalo do nível Aventureiro (2 baixo + 1 esquerda)
void moverCavaloAventureiro() {
    printf("=== Movimentação do Cavalo (Nível Aventureiro: 2 baixo + 1 esquerda) ===\n");
    
    // Primeiro movimento: 2 casas para baixo usando for
    for (int i = 0; i < 2; i++) {
        printf("Baixo\n");
    }
    
    // Segundo movimento: 1 casa para esquerda usando while
    int esquerda = 1;
    while (esquerda > 0) {
        printf("Esquerda\n");
        esquerda--;
    }
}

// === FUNÇÕES DO NÍVEL NOVATO (para comparação) ===

// Função do nível Novato: Torre com loop for
void moverTorreNovato() {
    printf("=== Movimentação da Torre (Nível Novato: 5 direita) ===\n");
    for (int i = 0; i < TORRE_CASAS; i++) {
        printf("Direita\n");
    }
}

// Função do nível Novato: Bispo com loop while  
void moverBispoNovato() {
    printf("=== Movimentação do Bispo (Nível Novato: 5 diagonal) ===\n");
    int casas = BISPO_CASAS;
    while (casas > 0) {
        printf("Cima\n");
        printf("Direita\n");
        casas--;
    }
}

// Função do nível Novato: Rainha com loop do-while
void moverRainhaNovato() {
    printf("=== Movimentação da Rainha (Nível Novato: 8 esquerda) ===\n");
    int casas = RAINHA_CASAS;
    do {
        printf("Esquerda\n");
        casas--;
    } while (casas > 0);
}

// Função principal - ponto de entrada do programa
int main() {
    // Cabeçalho do programa
    printf("=== Desafio de Xadrez - MateCheck - Todos os Níveis ===\n\n");
    
    // === DEMONSTRAÇÃO NÍVEL MESTRE (PRINCIPAL) ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                    NÍVEL MESTRE                         ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    // Movimentações com recursão (Torre, Bispo, Rainha)
    printf("--- Movimentação da Torre (5 casas para a direita) - RECURSIVO ---\n");
    moverTorreRecursivo(TORRE_CASAS);
    printf("\n");
    
    printf("--- Movimentação do Bispo (5 casas na diagonal) - RECURSIVO ---\n");
    moverBispoRecursivo(BISPO_CASAS);
    printf("\n");
    
    printf("--- Movimentação da Rainha (8 casas para a esquerda) - RECURSIVO ---\n");
    moverRainhaRecursivo(RAINHA_CASAS);
    printf("\n");
    
    // Bispo com loops aninhados (requisito específico do Mestre)
    moverBispoLoopsAninhados();
    printf("\n");
    
    // Cavalo com loops complexos (Mestre: 2 cima + 1 direita)
    moverCavaloComplexo();
    printf("\n");
    
    // === DEMONSTRAÇÃO DOS NÍVEIS ANTERIORES (para comparação) ===
    printf("╔══════════════════════════════════════════════════════════╗\n");
    printf("║                NÍVEIS ANTERIORES                        ║\n");
    printf("╚══════════════════════════════════════════════════════════╝\n\n");
    
    printf("--- NÍVEL NOVATO ---\n");
    moverTorreNovato();
    printf("\n");
    moverBispoNovato();
    printf("\n");
    moverRainhaNovato();
    printf("\n");
    
    printf("--- NÍVEL AVENTUREIRO ---\n");
    moverCavaloAventureiro();
    printf("\n");
    
    // Mensagem de finalização
    printf("=== Fim da simulação de movimentação das peças ===\n");
    printf("\nResumo dos Níveis:\n");
    printf("• Novato: Torre (for), Bispo (while), Rainha (do-while)\n");
    printf("• Aventureiro: + Cavalo (loops aninhados: for + while)\n");
    printf("• Mestre: Torre/Bispo/Rainha (recursivos) + Cavalo (loops complexos) + Bispo (loops aninhados)\n");
    
    return 0;  // Indica que o programa terminou com sucesso
}
