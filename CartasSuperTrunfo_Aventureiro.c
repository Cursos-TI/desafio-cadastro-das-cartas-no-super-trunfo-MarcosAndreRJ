#include <stdio.h>

// Função para ler os dados de uma cidade
// Recebe como parâmetro o número da carta (1 ou 2)
// Preenche todas as variáveis da carta
void lerDadosCidade(int numCarta, char *estado, char *codigo, char *nome, 
                   int *populacao, float *area, float *pib, int *pontosTuristicos) {
    printf("\nInforme os dados da Carta %d:\n", numCarta);
    
    // Lendo estado (uma única letra)
    printf("Estado (duas letras): ");
    scanf(" %c", estado);  // O espaço antes do %c ignora espaços em branco
    
    // Lendo código (3 caracteres)
    printf("Código (3 caracteres): ");
    scanf("%s", codigo);  // %s lê uma string até encontrar espaço ou enter
    
    // Lendo nome da cidade (pode ter espaços)
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome);  // %[^\n] lê tudo até encontrar uma quebra de linha
    
    // Lendo população (número inteiro)
    printf("População: ");
    scanf("%d", populacao);
    
    // Lendo área em km² (número com casas decimais)
    printf("Área (km²): ");
    scanf("%f", area);
    
    // Lendo PIB em bilhões de reais (número com casas decimais)
    printf("PIB (bilhões de reais): ");
    scanf("%f", pib);
    
    // Lendo número de pontos turísticos (número inteiro)
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontosTuristicos);
}

// Função para calcular a densidade populacional
// Recebe população e área, retorna a densidade
float calcularDensidade(int populacao, float area) {
    // Densidade = população dividida pela área
    return populacao / area;
}

// Função para calcular o PIB per capita
// Recebe PIB (em bilhões) e população, retorna o PIB per capita em reais
float calcularPibPerCapita(float pib, int populacao) {
    // Primeiro convertemos o PIB de bilhões para reais
    // 1 bilhão = 1.000.000.000 (um seguido de 9 zeros)
    float pibReais = pib * 1000000000;
    
    // Depois dividimos pelo número de habitantes
    return pibReais / populacao;
}

// Função para exibir os dados de uma cidade
// Recebe todos os dados da carta e mostra na tela formatados
void exibirDadosCidade(int numCarta, char estado, char *codigo, char *nome,
                      int populacao, float area, float pib, int pontosTuristicos,
                      float densidade, float pibPerCapita) {
    printf("\nCarta %d:\n", numCarta);
    printf("Estado: %c\n", estado);
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome);
    printf("População: %d\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    
    // Mostrando os novos cálculos
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita);
}

int main() {
    // Variáveis para a primeira carta
    char estado1;
    char codigo1[4];  // 3 caracteres + 1 para o '\0' que indica fim da string
    char nome1[50];   // Espaço para nomes longos
    int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    
    // Variáveis para a segunda carta
    char estado2;
    char codigo2[4];
    char nome2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    
    // 1. Ler os dados das duas cidades
    lerDadosCidade(1, &estado1, codigo1, nome1, &populacao1, &area1, &pib1, &pontosTuristicos1);
    lerDadosCidade(2, &estado2, codigo2, nome2, &populacao2, &area2, &pib2, &pontosTuristicos2);
    
    // 2. Calcular densidade e PIB per capita para cada cidade
    float densidade1 = calcularDensidade(populacao1, area1);
    float pibPerCapita1 = calcularPibPerCapita(pib1, populacao1);
    
    float densidade2 = calcularDensidade(populacao2, area2);
    float pibPerCapita2 = calcularPibPerCapita(pib2, populacao2);
    
    // 3. Exibir os resultados
    exibirDadosCidade(1, estado1, codigo1, nome1, populacao1, area1, pib1, 
                     pontosTuristicos1, densidade1, pibPerCapita1);
    exibirDadosCidade(2, estado2, codigo2, nome2, populacao2, area2, pib2, 
                     pontosTuristicos2, densidade2, pibPerCapita2);
    
    return 0;
}