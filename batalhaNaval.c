#include <stdio.h>

// Desafio Batalha Naval - MateCheck - Nível Mestre
// Sistema completo de Batalha Naval com navios e habilidades especiais

#define TAMANHO_TABULEIRO 10  // Define o tabuleiro 10x10 conforme especificação
#define TAMANHO_NAVIO 3       // Define o tamanho dos navios (3 posições)

// Função para inicializar o tabuleiro com zeros (água)
void inicializarTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Percorre todas as posições do tabuleiro
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = 0;  // 0 representa água
        }
    }
}

// Função para posicionar um navio horizontal no tabuleiro
void posicionarNavioHorizontal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linha, int colunaInicial) {
    // Coloca o navio horizontalmente a partir da posição especificada
    for (int j = 0; j < TAMANHO_NAVIO; j++) {
        tabuleiro[linha][colunaInicial + j] = 3;  // 3 representa parte do navio
    }
}

// Função para posicionar um navio vertical no tabuleiro
void posicionarNavioVertical(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int coluna) {
    // Coloca o navio verticalmente a partir da posição especificada
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][coluna] = 3;  // 3 representa parte do navio
    }
}

// Função para posicionar um navio na diagonal principal (↘)
void posicionarNavioDiagonalPrincipal(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    // Coloca o navio na diagonal principal (linha e coluna aumentam juntas)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][colunaInicial + i] = 3;  // 3 representa parte do navio
    }
}

// Função para posicionar um navio na diagonal secundária (↙)
void posicionarNavioDiagonalSecundaria(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int linhaInicial, int colunaInicial) {
    // Coloca o navio na diagonal secundária (linha aumenta, coluna diminui)
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linhaInicial + i][colunaInicial - i] = 3;  // 3 representa parte do navio
    }
}

// Função para posicionar todos os navios no tabuleiro (do nível Aventureiro + Mestre)
void posicionarTodosNavios(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    // Navio 1: Horizontal na linha 2, a partir da coluna 1
    posicionarNavioHorizontal(tabuleiro, 2, 1);
    
    // Navio 2: Vertical na coluna 5, a partir da linha 7
    posicionarNavioVertical(tabuleiro, 7, 5);
    
    // Navio 3: Diagonal principal a partir da posição (1,7)
    posicionarNavioDiagonalPrincipal(tabuleiro, 1, 7);
    
    // Navio 4: Diagonal secundária a partir da posição (6,8)
    posicionarNavioDiagonalSecundaria(tabuleiro, 6, 8);
}

// Função para exibir o tabuleiro completo no console
void exibirTabuleiro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]) {
    printf("   ");
    // Cabeçalho com números das colunas
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        printf("%2d ", j);
    }
    printf("\n");
    
    // Exibe cada linha do tabuleiro com número da linha
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d ", i);  // Número da linha
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%2d ", tabuleiro[i][j]);  // Valor da posição
        }
        printf("\n");
    }
}

// Função para aplicar habilidade em formato de cone no tabuleiro
void aplicarHabilidadeCone(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int centroLinha, int centroColuna) {
    // Padrão do cone: 1 posição na linha 0, 3 na linha 1, 5 na linha 2
    int padroes[3][5] = {
        {0, 0, 1, 0, 0},  // Linha 0: apenas centro
        {0, 1, 1, 1, 0},  // Linha 1: centro + 1 para cada lado
        {1, 1, 1, 1, 1}   // Linha 2: linha completa
    };
    
    // Aplica o padrão no tabuleiro, centralizando na posição especificada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaDestino = centroLinha - 1 + i;  // Ajusta posição relativa
            int colunaDestino = centroColuna - 2 + j;  // Ajusta posição relativa
            
            // Verifica se está dentro dos limites do tabuleiro
            if (linhaDestino >= 0 && linhaDestino < TAMANHO_TABULEIRO && 
                colunaDestino >= 0 && colunaDestino < TAMANHO_TABULEIRO && 
                padroes[i][j] == 1) {
                if (tabuleiro[linhaDestino][colunaDestino] != 3) {  // Não sobrescreve navios
                    tabuleiro[linhaDestino][colunaDestino] = 5;  // 5 representa área afetada
                }
            }
        }
    }
}

// Função para aplicar habilidade em formato de cruz no tabuleiro
void aplicarHabilidadeCruz(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int centroLinha, int centroColuna) {
    // Marca toda a linha horizontal
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        if (tabuleiro[centroLinha][j] != 3) {  // Não sobrescreve navios
            tabuleiro[centroLinha][j] = 5;  // 5 representa área afetada
        }
    }
    
    // Marca toda a coluna vertical
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][centroColuna] != 3) {  // Não sobrescreve navios
            tabuleiro[i][centroColuna] = 5;  // 5 representa área afetada
        }
    }
}

// Função para aplicar habilidade em formato de octaedro (losango) no tabuleiro
void aplicarHabilidadeOctaedro(int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO], int centroLinha, int centroColuna) {
    // Padrão do octaedro: formato de losango
    int padroes[3][5] = {
        {0, 0, 1, 0, 0},  // Linha 0: apenas centro
        {0, 1, 1, 1, 0},  // Linha 1: centro + 1 para cada lado
        {0, 0, 1, 0, 0}   // Linha 2: apenas centro novamente
    };
    
    // Aplica o padrão no tabuleiro, centralizando na posição especificada
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 5; j++) {
            int linhaDestino = centroLinha - 1 + i;  // Ajusta posição relativa
            int colunaDestino = centroColuna - 2 + j;  // Ajusta posição relativa
            
            // Verifica se está dentro dos limites do tabuleiro
            if (linhaDestino >= 0 && linhaDestino < TAMANHO_TABULEIRO && 
                colunaDestino >= 0 && colunaDestino < TAMANHO_TABULEIRO && 
                padroes[i][j] == 1) {
                if (tabuleiro[linhaDestino][colunaDestino] != 3) {  // Não sobrescreve navios
                    tabuleiro[linhaDestino][colunaDestino] = 5;  // 5 representa área afetada
                }
            }
        }
    }
}

// Função principal - ponto de entrada do programa
int main() {
    // Declaração da matriz que representa o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    
    // Cabeçalho do programa
    printf("=== Desafio Batalha Naval - Nível Mestre ===\n\n");
    
    // === FASE 1: TABULEIRO COM NAVIOS (Nível Aventureiro) ===
    printf("=== FASE 1: Tabuleiro com 4 Navios ===\n");
    printf("(0=Água, 3=Navio)\n\n");
    
    // Inicializa o tabuleiro e posiciona todos os navios
    inicializarTabuleiro(tabuleiro);
    posicionarTodosNavios(tabuleiro);
    
    // Exibe o tabuleiro com os navios posicionados
    exibirTabuleiro(tabuleiro);
    
    // === FASE 2: HABILIDADES ESPECIAIS (Nível Mestre) ===
    printf("\n=== FASE 2: Habilidades Especiais ===\n");
    printf("(0=Água, 3=Navio, 5=Área de Efeito)\n\n");
    
    // Demonstração da habilidade Cone na posição (4,4)
    printf("--- Habilidade CONE aplicada na posição (4,4) ---\n");
    aplicarHabilidadeCone(tabuleiro, 4, 4);
    exibirTabuleiro(tabuleiro);
    
    printf("\nPressione Enter para continuar para a próxima habilidade...\n");
    getchar(); // Pausa para o usuário ver o resultado
    
    // Reinicia tabuleiro para próxima demonstração
    inicializarTabuleiro(tabuleiro);
    posicionarTodosNavios(tabuleiro);
    
    // Demonstração da habilidade Cruz na posição (5,5)
    printf("\n--- Habilidade CRUZ aplicada na posição (5,5) ---\n");
    aplicarHabilidadeCruz(tabuleiro, 5, 5);
    exibirTabuleiro(tabuleiro);
    
    printf("\nPressione Enter para continuar para a próxima habilidade...\n");
    getchar(); // Pausa para o usuário ver o resultado
    
    // Reinicia tabuleiro para próxima demonstração
    inicializarTabuleiro(tabuleiro);
    posicionarTodosNavios(tabuleiro);
    
    // Demonstração da habilidade Octaedro na posição (3,6)
    printf("\n--- Habilidade OCTAEDRO aplicada na posição (3,6) ---\n");
    aplicarHabilidadeOctaedro(tabuleiro, 3, 6);
    exibirTabuleiro(tabuleiro);
    
    // Mensagem de finalização
    printf("\n=== Fim da simulação do Batalha Naval ===\n");
    printf("\nLegenda:\n");
    printf("0 = Água\n");
    printf("3 = Parte do navio\n");
    printf("5 = Área afetada por habilidade especial\n");
    
    return 0;  // Indica que o programa terminou com sucesso
}
