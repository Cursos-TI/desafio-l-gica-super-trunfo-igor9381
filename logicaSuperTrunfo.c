#include <stdio.h>
#include <string.h>

int main() {
    // Dados fixos das cartas
    char nome1[100] = "Brasil";
    char nome2[100] = "Argentina";

    unsigned long int populacao1 = 213000000, populacao2 = 45000000;
    float area1 = 8515767.0, area2 = 2780000.0;
    float pib1 = 21400.0, pib2 = 500.0;
    int pontos1 = 150, pontos2 = 80;
    float dens1 = populacao1 / area1;
    float dens2 = populacao2 / area2;

    int atributo1, atributo2;
    float valor1_1 = 0, valor2_1 = 0, valor1_2 = 0, valor2_2 = 0;

    // Menu do primeiro atributo
    printf("=== SUPER TRUNFO - COMPARAÇÃO AVANÇADA ===\n");
    printf("\nCarta 1: %s\nCarta 2: %s\n\n", nome1, nome2);

    printf("Escolha o primeiro atributo para comparação:\n");
    printf("1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Demográfica\n");
    printf("Opção: ");
    scanf("%d", &atributo1);

    // Menu do segundo atributo (dinâmico)
    printf("\nEscolha o segundo atributo (diferente do primeiro):\n");
    for (int i = 1; i <= 5; i++) {
        if (i != atributo1) {
            switch (i) {
                case 1: printf("%d - População\n", i); break;
                case 2: printf("%d - Área\n", i); break;
                case 3: printf("%d - PIB\n", i); break;
                case 4: printf("%d - Pontos Turísticos\n", i); break;
                case 5: printf("%d - Densidade Demográfica\n", i); break;
            }
        }
    }
    printf("Opção: ");
    scanf("%d", &atributo2);

    // Validar escolha de atributos
    if (atributo1 == atributo2 || atributo1 < 1 || atributo1 > 5 || atributo2 < 1 || atributo2 > 5) {
        printf("\nErro: Atributos inválidos ou repetidos. Encerrando programa.\n");
        return 1;
    }

    // Obter valores para os dois atributos escolhidos
    switch (atributo1) {
        case 1: valor1_1 = populacao1; valor2_1 = populacao2; break;
        case 2: valor1_1 = area1; valor2_1 = area2; break;
        case 3: valor1_1 = pib1; valor2_1 = pib2; break;
        case 4: valor1_1 = pontos1; valor2_1 = pontos2; break;
        case 5: valor1_1 = dens1; valor2_1 = dens2; break;
        default: break;
    }
    switch (atributo2) {
        case 1: valor1_2 = populacao1; valor2_2 = populacao2; break;
        case 2: valor1_2 = area1; valor2_2 = area2; break;
        case 3: valor1_2 = pib1; valor2_2 = pib2; break;
        case 4: valor1_2 = pontos1; valor2_2 = pontos2; break;
        case 5: valor1_2 = dens1; valor2_2 = dens2; break;
        default: break;
    }

    // Mostrar valores escolhidos
    printf("\n=== Comparando ===\n");
    printf("Carta 1 (%s):\n", nome1);
    printf(" - Atributo %d: %.2f\n", atributo1, valor1_1);
    printf(" - Atributo %d: %.2f\n", atributo2, valor1_2);
    printf("Carta 2 (%s):\n", nome2);
    printf(" - Atributo %d: %.2f\n", atributo1, valor2_1);
    printf(" - Atributo %d: %.2f\n", atributo2, valor2_2);

    // Comparações individuais com regras (densidade menor vence)
    int vitoria1 = 0, vitoria2 = 0;

    // Comparação do primeiro atributo
    if (atributo1 == 5) {
        vitoria1 += (valor1_1 < valor2_1) ? 1 : 0;
        vitoria2 += (valor2_1 < valor1_1) ? 1 : 0;
    } else {
        vitoria1 += (valor1_1 > valor2_1) ? 1 : 0;
        vitoria2 += (valor2_1 > valor1_1) ? 1 : 0;
    }

    // Comparação do segundo atributo
    if (atributo2 == 5) {
        vitoria1 += (valor1_2 < valor2_2) ? 1 : 0;
        vitoria2 += (valor2_2 < valor1_2) ? 1 : 0;
    } else {
        vitoria1 += (valor1_2 > valor2_2) ? 1 : 0;
        vitoria2 += (valor2_2 > valor1_2) ? 1 : 0;
    }

    // Soma total dos atributos
    float soma1 = valor1_1 + valor1_2;
    float soma2 = valor2_1 + valor2_2;

    // Resultado final
    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", nome1, soma1);
    printf("%s: %.2f\n", nome2, soma2);

    if (soma1 > soma2) {
        printf("\nResultado final: %s venceu!\n", nome1);
    } else if (soma2 > soma1) {
        printf("\nResultado final: %s venceu!\n", nome2);
    } else {
        printf("\nResultado final: Empate!\n");
    }

    return 0;
}


