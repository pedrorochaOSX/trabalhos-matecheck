#include <stdio.h>
#include <string.h>

// Desafio Super Trunfo - Países - Nível Mestre
// Sistema avançado de comparação de cartas com lógica de múltiplos atributos

// Estrutura que define os atributos de uma carta de cidade
typedef struct {
    char codigo[4];               // Código da carta (ex: A01)
    char nome[50];                // Nome da cidade
    int populacao;                // População da cidade
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
    carta->densidadePopulacional = carta->populacao / carta->area;
    
    // Calcula PIB per capita (PIB dividido pela população)
    carta->pibPerCapita = carta->pib / carta->populacao;
    
    // Calcula super poder (soma dos atributos básicos apenas)
    carta->superPoder = carta->populacao + carta->area + carta->pib + carta->pontosTuristicos;
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
    
    // Solicita e lê a população
    printf("Digite a população: ");
    scanf("%d", &carta->populacao);
    
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
    printf("População: %d habitantes\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePopulacional);
    printf("PIB per Capita: %.2f\n", carta.pibPerCapita);
    printf("Super Poder: %.2f\n", carta.superPoder);
}

// Função para exibir menu de seleção de atributos dinâmico (exclui atributo já escolhido)
int exibirMenuAtributosDinamico(int atributoExcluido) {
    int opcao;
    printf("\n=== Escolha um Atributo ===\n");
    
    if (atributoExcluido != 1) printf("1. População\n");
    if (atributoExcluido != 2) printf("2. Área\n");
    if (atributoExcluido != 3) printf("3. PIB\n");
    if (atributoExcluido != 4) printf("4. Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5. Densidade Populacional\n");
    if (atributoExcluido != 6) printf("6. PIB per Capita\n");
    if (atributoExcluido != 7) printf("7. Super Poder\n");
    
    printf("Digite sua opção: ");
    scanf("%d", &opcao);
    
    // Validação: se o usuário escolher o atributo excluído, pede nova escolha
    while (opcao == atributoExcluido || opcao < 1 || opcao > 7) {
        printf("Opção inválida ou já escolhida! Digite outra opção: ");
        scanf("%d", &opcao);
    }
    
    return opcao;
}

// Função para comparar duas cartas em um atributo específico
// Retorna: 1 se carta1 vence, 2 se carta2 vence, 0 se empate, -1 se atributo inválido
int compararAtributo(Carta carta1, Carta carta2, int atributo) {
    switch (atributo) {
        case 1: // População - maior vence
            return (carta1.populacao > carta2.populacao) ? 1 : 
                   (carta1.populacao < carta2.populacao) ? 2 : 0;
        case 2: // Área - maior vence
            return (carta1.area > carta2.area) ? 1 : 
                   (carta1.area < carta2.area) ? 2 : 0;
        case 3: // PIB - maior vence
            return (carta1.pib > carta2.pib) ? 1 : 
                   (carta1.pib < carta2.pib) ? 2 : 0;
        case 4: // Pontos Turísticos - maior vence
            return (carta1.pontosTuristicos > carta2.pontosTuristicos) ? 1 : 
                   (carta1.pontosTuristicos < carta2.pontosTuristicos) ? 2 : 0;
        case 5: // Densidade Populacional - menor vence (menos congestionamento)
            return (carta1.densidadePopulacional < carta2.densidadePopulacional) ? 1 : 
                   (carta1.densidadePopulacional > carta2.densidadePopulacional) ? 2 : 0;
        case 6: // PIB per Capita - maior vence
            return (carta1.pibPerCapita > carta2.pibPerCapita) ? 1 : 
                   (carta1.pibPerCapita < carta2.pibPerCapita) ? 2 : 0;
        case 7: // Super Poder - maior vence
            return (carta1.superPoder > carta2.superPoder) ? 1 : 
                   (carta1.superPoder < carta2.superPoder) ? 2 : 0;
        default: // Atributo inválido
            return -1;
    }
}

// Função para obter o valor de um atributo específico de uma carta
float obterValorAtributo(Carta carta, int atributo) {
    switch (atributo) {
        case 1: return (float)carta.populacao;
        case 2: return carta.area;
        case 3: return carta.pib;
        case 4: return (float)carta.pontosTuristicos;
        case 5: return carta.densidadePopulacional;
        case 6: return carta.pibPerCapita;
        case 7: return carta.superPoder;
        default: return 0.0f;
    }
}

// Função para obter o nome do atributo baseado no número
char* obterNomeAtributo(int atributo) {
    switch (atributo) {
        case 1: return "População";
        case 2: return "Área";
        case 3: return "PIB";
        case 4: return "Pontos Turísticos";
        case 5: return "Densidade Populacional";
        case 6: return "PIB per Capita";
        case 7: return "Super Poder";
        default: return "Atributo Inválido";
    }
}

// Função principal para comparar duas cartas usando dois atributos escolhidos pelo usuário (Nível Mestre)
void compararDoisAtributos(Carta carta1, Carta carta2) {
    printf("\n=== Comparação com Dois Atributos (Nível Mestre) ===\n");
    
    // Solicita escolha do primeiro atributo
    printf("Escolha o primeiro atributo:\n");
    int atributo1 = exibirMenuAtributosDinamico(-1);  // -1 = nenhum atributo excluído
    
    // Validação do primeiro atributo
    if (atributo1 < 1 || atributo1 > 7) {
        printf("Primeiro atributo inválido!\n");
        return;
    }
    
    // Solicita escolha do segundo atributo (menu dinâmico: exclui o primeiro)
    printf("Escolha o segundo atributo (diferente do primeiro):\n");
    int atributo2 = exibirMenuAtributosDinamico(atributo1);
    
    // Validação do segundo atributo
    if (atributo2 < 1 || atributo2 > 7 || atributo2 == atributo1) {
        printf("Segundo atributo inválido ou igual ao primeiro!\n");
        return;
    }
    
    // Obtém os valores dos atributos para cada carta
    float valor1_carta1 = obterValorAtributo(carta1, atributo1);
    float valor2_carta1 = obterValorAtributo(carta1, atributo2);
    float valor1_carta2 = obterValorAtributo(carta2, atributo1);
    float valor2_carta2 = obterValorAtributo(carta2, atributo2);
    
    // Executa as comparações individuais
    int resultado1 = compararAtributo(carta1, carta2, atributo1);
    int resultado2 = compararAtributo(carta1, carta2, atributo2);
    
    printf("\n=== Resultados da Comparação Individual ===\n");
    
    // Exibe resultado do primeiro atributo
    printf("%s:\n", obterNomeAtributo(atributo1));
    printf("  Carta 1 (%s): %.2f\n", carta1.nome, valor1_carta1);
    printf("  Carta 2 (%s): %.2f\n", carta2.nome, valor1_carta2);
    if (resultado1 == 1) {
        printf("  Vencedor: Carta 1 (%s)\n", carta1.nome);
    } else if (resultado1 == 2) {
        printf("  Vencedor: Carta 2 (%s)\n", carta2.nome);
    } else {
        printf("  Resultado: Empate\n");
    }
    
    // Exibe resultado do segundo atributo
    printf("\n%s:\n", obterNomeAtributo(atributo2));
    printf("  Carta 1 (%s): %.2f\n", carta1.nome, valor2_carta1);
    printf("  Carta 2 (%s): %.2f\n", carta2.nome, valor2_carta2);
    if (resultado2 == 1) {
        printf("  Vencedor: Carta 1 (%s)\n", carta1.nome);
    } else if (resultado2 == 2) {
        printf("  Vencedor: Carta 2 (%s)\n", carta2.nome);
    } else {
        printf("  Resultado: Empate\n");
    }
    
    // NÍVEL MESTRE: Soma dos atributos para determinar vencedor geral
    printf("\n=== Soma dos Atributos (Decisão Final) ===\n");
    float soma_carta1 = valor1_carta1 + valor2_carta1;
    float soma_carta2 = valor1_carta2 + valor2_carta2;
    
    printf("Soma Carta 1 (%s): %.2f + %.2f = %.2f\n", carta1.nome, valor1_carta1, valor2_carta1, soma_carta1);
    printf("Soma Carta 2 (%s): %.2f + %.2f = %.2f\n", carta2.nome, valor1_carta2, valor2_carta2, soma_carta2);
    
    // Determina o vencedor final baseado na soma (usando operador ternário)
    printf("\n🏆 RESULTADO FINAL: ");
    if (soma_carta1 > soma_carta2) {
        printf("Carta 1 (%s) venceu com soma total de %.2f!\n", carta1.nome, soma_carta1);
    } else if (soma_carta2 > soma_carta1) {
        printf("Carta 2 (%s) venceu com soma total de %.2f!\n", carta2.nome, soma_carta2);
    } else {
        printf("Empate! Ambas as cartas têm soma total de %.2f\n", soma_carta1);
    }
}

// Função principal - ponto de entrada do programa
int main() {
	// Definição das variáveis para armazenar as propriedades das cidades
    // Você pode utilizar o código do primeiro desafio

    
    // Cadastro das Cartas:
    // Implemente a lógica para solicitar ao usuário que insira os dados das cidades
    // utilizando a função scanf para capturar as entradas.
    // utilize o código do primeiro desafio

    // Exemplo:
    // printf("Digite o código da cidade: ");
    // scanf("%s", codigo);
    // 
    // (Repita para cada propriedade)

    // Comparação de Cartas:
    // Desenvolva a lógica de comparação entre duas cartas.
    // Utilize estruturas de decisão como if, if-else para comparar atributos como população, área, PIB, etc.

    // Exemplo:
    // if (populacaoA > populacaoB) {
    //     printf("Cidade 1 tem maior população.\n");
    // } else {
    //     printf("Cidade 2 tem maior população.\n");
    // }

    // Exibição dos Resultados:
    // Após realizar as comparações, exiba os resultados para o usuário.
    // Certifique-se de que o sistema mostre claramente qual carta venceu e com base em qual atributo.

    // Exemplo:
    // printf("A cidade vencedora é: %s\n", cidadeVencedora);
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
    
    // Sistema de comparação interativa com dois atributos escolhidos pelo usuário
    compararDoisAtributos(carta1, carta2);
    
    // Mensagem de finalização
    printf("\n=== Fim do programa ===\n");
    
    return 0;  // Indica que o programa terminou com sucesso
}