#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países - Nível Mestre
// Sistema de cadastro e comparação de cartas de cidades

// Estrutura que define os atributos de uma carta de cidade
typedef struct {
    char codigo[4];               // Código da carta (ex: A01)
    char nome[50];                // Nome da cidade
    unsigned long int populacao;  // População da cidade (Nível Mestre: unsigned long int)
    float area;                   // Área em km²
    float pib;                    // PIB em bilhões
    int pontosTuristicos;         // Número de pontos turísticos
    float densidadePopulacional;  // Densidade populacional (calculada)
    float pibPerCapita;           // PIB per capita (calculado)
    float superPoder;             // Super poder total (calculado)
} Carta;

// Função para calcular as propriedades derivadas de uma carta
void calcularPropriedadesDerivadas(Carta *carta) {
    // Calcula densidade populacional (habitantes por km²)
    carta->densidadePopulacional = (float)carta->populacao / carta->area;
    
    // Calcula PIB per capita (PIB dividido pela população - conversão de tipos necessária)
    carta->pibPerCapita = carta->pib / (float)carta->populacao;
    
    // Calcula super poder (soma de todos os atributos + INVERSO da densidade populacional)
    // Nível Mestre: usa o inverso da densidade (quanto menor a densidade, maior o poder)
    float inversoDensidade = (carta->densidadePopulacional > 0) ? (1.0f / carta->densidadePopulacional) : 0.0f;
    carta->superPoder = (float)carta->populacao + carta->area + carta->pib + (float)carta->pontosTuristicos + 
                        carta->pibPerCapita + inversoDensidade;
}

// Função para cadastrar uma nova carta com dados inseridos pelo usuário
void cadastrarCarta(Carta *carta, int numeroCarta) {
    printf("\n=== Cadastro da Carta %d ===\n", numeroCarta);
    
    // Solicita e lê o código da carta
    printf("Digite o código da carta (ex: A01): ");
    scanf("%s", carta->codigo);
    
    // Solicita e lê o nome da cidade (aceita espaços)
    printf("Digite o nome da cidade: ");
    scanf(" %[^\n]", carta->nome);
    
    // Solicita e lê a população (Nível Mestre: unsigned long int)
    printf("Digite a população: ");
    scanf("%lu", &carta->populacao);
    
    // Solicita e lê a área em km²
    printf("Digite a área (km²): ");
    scanf("%f", &carta->area);
    
    // Solicita e lê o PIB em bilhões
    printf("Digite o PIB (bilhões): ");
    scanf("%f", &carta->pib);
    
    // Solicita e lê o número de pontos turísticos
    printf("Digite o número de pontos turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
    
    // Calcula automaticamente as propriedades derivadas
    calcularPropriedadesDerivadas(carta);
}

// Função para exibir todos os dados de uma carta
void exibirCarta(Carta carta, int numeroCarta) {
    printf("\n=== Dados da Carta %d ===\n", numeroCarta);
    printf("Código: %s\n", carta.codigo);
    printf("Nome: %s\n", carta.nome);
    printf("População: %lu habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para comparar duas cartas em todos os atributos (Nível Mestre)
void compararCartas(Carta carta1, Carta carta2) {
    printf("\n=== Comparação entre as Cartas (Nível Mestre) ===\n");
    printf("Resultados: 1 = Carta 1 vence, 0 = Carta 2 vence\n");
    
    // Comparação de população (maior vence)
    printf("\nPopulação:\n");
    if (carta1.populacao > carta2.populacao) {
        printf("Carta 1 (%s) vence com %lu habitantes\n", carta1.nome, carta1.populacao);
        printf("Resultado: 1\n");
    } else if (carta2.populacao > carta1.populacao) {
        printf("Carta 2 (%s) vence com %lu habitantes\n", carta2.nome, carta2.populacao);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em população\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de área (maior vence)
    printf("\nÁrea:\n");
    if (carta1.area > carta2.area) {
        printf("Carta 1 (%s) vence com %.2f km²\n", carta1.nome, carta1.area);
        printf("Resultado: 1\n");
    } else if (carta2.area > carta1.area) {
        printf("Carta 2 (%s) vence com %.2f km²\n", carta2.nome, carta2.area);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em área\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de PIB (maior vence)
    printf("\nPIB:\n");
    if (carta1.pib > carta2.pib) {
        printf("Carta 1 (%s) vence com %.2f bilhões\n", carta1.nome, carta1.pib);
        printf("Resultado: 1\n");
    } else if (carta2.pib > carta1.pib) {
        printf("Carta 2 (%s) vence com %.2f bilhões\n", carta2.nome, carta2.pib);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em PIB\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de pontos turísticos (maior vence)
    printf("\nPontos Turísticos:\n");
    if (carta1.pontosTuristicos > carta2.pontosTuristicos) {
        printf("Carta 1 (%s) vence com %d pontos\n", carta1.nome, carta1.pontosTuristicos);
        printf("Resultado: 1\n");
    } else if (carta2.pontosTuristicos > carta1.pontosTuristicos) {
        printf("Carta 2 (%s) vence com %d pontos\n", carta2.nome, carta2.pontosTuristicos);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em pontos turísticos\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de densidade populacional (menor vence - menos congestionamento)
    printf("\nDensidade Populacional (menor vence):\n");
    if (carta1.densidadePopulacional < carta2.densidadePopulacional) {
        printf("Carta 1 (%s) vence com %.2f hab/km²\n", carta1.nome, carta1.densidadePopulacional);
        printf("Resultado: 1\n");
    } else if (carta2.densidadePopulacional < carta1.densidadePopulacional) {
        printf("Carta 2 (%s) vence com %.2f hab/km²\n", carta2.nome, carta2.densidadePopulacional);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em densidade populacional\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de PIB per capita (maior vence)
    printf("\nPIB per Capita:\n");
    if (carta1.pibPerCapita > carta2.pibPerCapita) {
        printf("Carta 1 (%s) vence com %.2f\n", carta1.nome, carta1.pibPerCapita);
        printf("Resultado: 1\n");
    } else if (carta2.pibPerCapita > carta1.pibPerCapita) {
        printf("Carta 2 (%s) vence com %.2f\n", carta2.nome, carta2.pibPerCapita);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em PIB per capita\n");
        printf("Resultado: Empate\n");
    }
    
    // Comparação de super poder (maior vence - atributo especial do Nível Mestre)
    printf("\nSuper Poder:\n");
    if (carta1.superPoder > carta2.superPoder) {
        printf("Carta 1 (%s) vence com %.2f pontos de super poder\n", carta1.nome, carta1.superPoder);
        printf("Resultado: 1\n");
    } else if (carta2.superPoder > carta1.superPoder) {
        printf("Carta 2 (%s) vence com %.2f pontos de super poder\n", carta2.nome, carta2.superPoder);
        printf("Resultado: 0\n");
    } else {
        printf("Empate em super poder\n");
        printf("Resultado: Empate\n");
    }
}

// Função principal - ponto de entrada do programa
int main() {
    // Declaração das duas cartas que serão cadastradas
    Carta carta1, carta2;
    
    // Cabeçalho do programa
    printf("=== Desafio Super Trunfo - Países - Nível Mestre ===\n\n");
    
    // Cadastro da primeira carta
    cadastrarCarta(&carta1, 1);
    
    // Cadastro da segunda carta
    cadastrarCarta(&carta2, 2);
    
    // Exibição dos dados da primeira carta
    exibirCarta(carta1, 1);
    
    // Exibição dos dados da segunda carta
    exibirCarta(carta2, 2);
    
    // Comparação entre as duas cartas em todos os atributos
    compararCartas(carta1, carta2);
    
    // Mensagem de finalização
    printf("\n=== Fim do programa ===\n");
    
    return 0;  // Indica que o programa terminou com sucesso
}