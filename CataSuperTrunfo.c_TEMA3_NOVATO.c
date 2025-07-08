#include <stdio.h>
#include <string.h> // Para usar strcmp (comparar strings)

int main() {
    // Variáveis para a Carta 1
    char estado1[3];       // 2 letras para estado + '\0' (fim da string)
    char codigo1[4];       // 3 caracteres + '\0'
    char nome1[50];        // Nome da cidade
    int populacao1;        // Número de habitantes
    float area1;           // Área em km²
    float pib1;            // PIB em bilhões
    int pontos1;           // Pontos turísticos
    float densidade1;      // Habitantes por km²
    float pib_per_capita1; // Riqueza por pessoa
    
    // Variáveis para a Carta 2 (mesmas que a Carta 1)
    char estado2[3];
    char codigo2[4];
    char nome2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos2;
    float densidade2;
    float pib_per_capita2;
    
    // Variáveis para a comparação
    char atributo[20]; // Guarda qual atributo vamos comparar
    int vencedor;      // 1 = carta1 vence, 2 = carta2 vence, 0 = empate
    
    // CADASTRO DA CARTA 1
    printf("=== CADASTRO CARTA 1 ===\n");
    
    // Lendo estado (2 letras)
    printf("Estado (2 letras): ");
    scanf("%2s", estado1); // %2s lê no máximo 2 caracteres
    
    // Lendo código (3 caracteres)
    printf("Codigo (3 letras/numeros): ");
    scanf("%3s", codigo1);
    
    // Lendo nome da cidade (pode ter espaços)
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome1); // %[^\n] lê até apertar Enter
    
    // Lendo população (número inteiro)
    printf("Populacao: ");
    scanf("%d", &populacao1);
    
    // Lendo área (número com decimal)
    printf("Area (km²): ");
    scanf("%f", &area1);
    
    // Lendo PIB (número com decimal)
    printf("PIB (bilhoes): ");
    scanf("%f", &pib1);
    
    // Lendo pontos turísticos (número inteiro)
    printf("Pontos turisticos: ");
    scanf("%d", &pontos1);
    
    // Calculando densidade populacional
    densidade1 = populacao1 / area1;
    
    // Calculando PIB per capita (convertendo bilhões para reais)
    pib_per_capita1 = (pib1 * 1000000000) / populacao1;
    
    
    // CADASTRO DA CARTA 2 (igual à Carta 1)
    printf("\n=== CADASTRO CARTA 2 ===\n");
    
    printf("Estado (2 letras): ");
    scanf("%2s", estado2);
    
    printf("Codigo (3 letras/numeros): ");
    scanf("%3s", codigo2);
    
    printf("Nome da cidade: ");
    scanf(" %[^\n]", nome2);
    
    printf("Populacao: ");
    scanf("%d", &populacao2);
    
    printf("Area (km²): ");
    scanf("%f", &area2);
    
    printf("PIB (bilhoes): ");
    scanf("%f", &pib2);
    
    printf("Pontos turisticos: ");
    scanf("%d", &pontos2);
    
    // Cálculos para Carta 2
    densidade2 = populacao2 / area2;
    pib_per_capita2 = (pib2 * 1000000000) / populacao2;
    
    
    // ESCOLHA DO ATRIBUTO PARA COMPARAR
    // Aqui definimos qual atributo será usado na comparação
    // Mude essa linha para comparar por outro atributo
    strcpy(atributo, "PIB"); // Pode ser: "Populacao", "Area", "PIB", "Densidade", "PIB_per_capita"
    
    
    // COMPARAÇÃO DAS CARTAS
    printf("\n=== RESULTADO DA COMPARACAO ===\n");
    
    // Verifica qual atributo foi escolhido
    if (strcmp(atributo, "Populacao") == 0) {
        // Comparando por população (maior vence)
        printf("Atributo: Populacao\n");
        printf("%s: %d hab.\n", nome1, populacao1);
        printf("%s: %d hab.\n", nome2, populacao2);
        
        if (populacao1 > populacao2) {
            vencedor = 1;
        } else if (populacao2 > populacao1) {
            vencedor = 2;
        } else {
            vencedor = 0; // Empate
        }
    }
    else if (strcmp(atributo, "Area") == 0) {
        // Comparando por área (maior vence)
        printf("Atributo: Area\n");
        printf("%s: %.2f km²\n", nome1, area1);
        printf("%s: %.2f km²\n", nome2, area2);
        
        if (area1 > area2) {
            vencedor = 1;
        } else if (area2 > area1) {
            vencedor = 2;
        } else {
            vencedor = 0;
        }
    }
    else if (strcmp(atributo, "PIB") == 0) {
        // Comparando por PIB (maior vence)
        printf("Atributo: PIB\n");
        printf("%s: %.2f bilhoes\n", nome1, pib1);
        printf("%s: %.2f bilhoes\n", nome2, pib2);
        
        if (pib1 > pib2) {
            vencedor = 1;
        } else if (pib2 > pib1) {
            vencedor = 2;
        } else {
            vencedor = 0;
        }
    }
    else if (strcmp(atributo, "Densidade") == 0) {
        // Comparando por densidade (MENOR vence)
        printf("Atributo: Densidade\n");
        printf("%s: %.2f hab/km²\n", nome1, densidade1);
        printf("%s: %.2f hab/km²\n", nome2, densidade2);
        
        if (densidade1 < densidade2) {
            vencedor = 1;
        } else if (densidade2 < densidade1) {
            vencedor = 2;
        } else {
            vencedor = 0;
        }
    }
    else if (strcmp(atributo, "PIB_per_capita") == 0) {
        // Comparando por PIB per capita (maior vence)
        printf("Atributo: PIB per capita\n");
        printf("%s: %.2f reais\n", nome1, pib_per_capita1);
        printf("%s: %.2f reais\n", nome2, pib_per_capita2);
        
        if (pib_per_capita1 > pib_per_capita2) {
            vencedor = 1;
        } else if (pib_per_capita2 > pib_per_capita1) {
            vencedor = 2;
        } else {
            vencedor = 0;
        }
    }
    else {
        printf("Atributo invalido!\n");
        return 1; // Termina o programa com erro
    }
    
    // MOSTRANDO O VENCEDOR
    if (vencedor == 1) {
        printf("Vencedor: %s!\n", nome1);
    } 
    else if (vencedor == 2) {
        printf("Vencedor: %s!\n", nome2);
    } 
    else {
        printf("Empate!\n");
    }
    
    return 0;
}