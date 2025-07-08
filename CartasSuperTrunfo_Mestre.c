#include <stdio.h>

// Função para ler os dados de uma cidade
void lerDadosCidade(int numCarta, char *estado, char *codigo, char *nome, 
                   unsigned long int *populacao, float *area, float *pib, 
                   int *pontosTuristicos) {
    printf("\nInforme os dados da Carta %d:\n", numCarta);
    
    printf("Estado (duas letras): ");
    scanf("%2s", estado); 
    
    printf("Código (3 caracteres): ");
    scanf("%s", codigo);
    
    printf("Nome da Cidade: ");
    scanf(" %[^\n]", nome);
    
    printf("População: ");aaaaa
    scanf("%lu", populacao);  // %lu para unsigned long int
    
    printf("Área (km²): ");
    scanf("%f", area);
    
    printf("PIB (bilhões de reais): ");
    scanf("%f", pib);
    
    printf("Número de Pontos Turísticos: ");
    scanf("%d", pontosTuristicos);
}

// Função para calcular a densidade populacional
float calcularDensidade(unsigned long int populacao, float area) {
    return populacao / area;
}

// Função para calcular o PIB per capita
float calcularPibPerCapita(float pib, unsigned long int populacao) {
    return (pib * 1000000000) / populacao;
}

// Função para calcular o Super Poder
float calcularSuperPoder(unsigned long int populacao, float area, float pib, 
                        int pontosTuristicos, float pibPerCapita, float densidade) {
    // Convertemos todos para float antes de somar
    float sp = (float)populacao + area + pib + (float)pontosTuristicos + pibPerCapita + (1/densidade);
    return sp;
}

// Função para exibir os dados de uma cidade
void exibirDadosCidade(int numCarta, char *estado, char *codigo, char *nome,
                      unsigned long int populacao, float area, float pib, 
                      int pontosTuristicos, float densidade, float pibPerCapita,
                      float superPoder) {
    printf("\nCarta %d:\n", numCarta);
    printf("Estado: %s\n", estado); 
    printf("Código: %s\n", codigo);
    printf("Nome da Cidade: %s\n", nome);
    printf("População: %lu\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Número de Pontos Turísticos: %d\n", pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidade);
    printf("PIB per Capita: %.2f reais\n", pibPerCapita);
    printf("Super Poder: %.2f\n", superPoder);
}

// Função para comparar dois valores e mostrar o resultado
void compararAtributo(char *nomeAtributo, float valor1, float valor2, int inverso) {
    int resultado;
    
    if (inverso) {
        // Para densidade: menor valor vence
        resultado = valor1 < valor2;
    } else {
        // Para outros atributos: maior valor vence
        resultado = valor1 > valor2;
    }
    
    printf("%s: Carta %d venceu (%d)\n", nomeAtributo, resultado ? 1 : 2, resultado);
}

int main() {
    // Variáveis para a primeira carta
    char estado1[3]; 
    char codigo1[4];
    char nome1[50];
    unsigned long int populacao1;
    float area1;
    float pib1;
    int pontosTuristicos1;
    float densidade1;
    float pibPerCapita1;
    float superPoder1;
    
    // Variáveis para a segunda carta
    char estado2[3]; 
    char codigo2[4];
    char nome2[50];
    unsigned long int populacao2;
    float area2;
    float pib2;
    int pontosTuristicos2;
    float densidade2;
    float pibPerCapita2;
    float superPoder2;
    
    // 1. Ler os dados das duas cidades
    lerDadosCidade(1, estado1, codigo1, nome1, &populacao1, &area1, &pib1, &pontosTuristicos1);
    lerDadosCidade(2, estado2, codigo2, nome2, &populacao2, &area2, &pib2, &pontosTuristicos2);
    
    // 2. Calcular densidade e PIB per capita
    densidade1 = calcularDensidade(populacao1, area1);
    pibPerCapita1 = calcularPibPerCapita(pib1, populacao1);
    
    densidade2 = calcularDensidade(populacao2, area2);
    pibPerCapita2 = calcularPibPerCapita(pib2, populacao2);
    
    // 3. Calcular Super Poder para cada carta
    superPoder1 = calcularSuperPoder(populacao1, area1, pib1, pontosTuristicos1, pibPerCapita1, densidade1);
    superPoder2 = calcularSuperPoder(populacao2, area2, pib2, pontosTuristicos2, pibPerCapita2, densidade2);
    
    // 4. Exibir os dados completos das cartas
    exibirDadosCidade(1, estado1, codigo1, nome1, populacao1, area1, pib1, 
                     pontosTuristicos1, densidade1, pibPerCapita1, superPoder1);
    exibirDadosCidade(2, estado2, codigo2, nome2, populacao2, area2, pib2, 
                     pontosTuristicos2, densidade2, pibPerCapita2, superPoder2);
    
    // 5. Comparar as cartas atributo por atributo
    printf("\nComparação de Cartas:\n");
    compararAtributo("População", (float)populacao1, (float)populacao2, 0);
    compararAtributo("Área", area1, area2, 0);
    compararAtributo("PIB", pib1, pib2, 0);
    compararAtributo("Pontos Turísticos", (float)pontosTuristicos1, (float)pontosTuristicos2, 0);
    compararAtributo("Densidade Populacional", densidade1, densidade2, 1);
    compararAtributo("PIB per Capita", pibPerCapita1, pibPerCapita2, 0);
    compararAtributo("Super Poder", superPoder1, superPoder2, 0);
    
    return 0;
}