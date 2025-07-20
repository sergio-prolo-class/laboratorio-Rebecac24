#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_PRODUTOS 100
#define DATA_LENGTH 11

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    char data_validade[DATA_LENGTH];
} Produto;

Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;

// Implementações das funções que estariam em produto.c
void copiar_string(char *dest, const char *src, int n)
{
    int i;
    for (i = 0; i < n && src[i] != '\0'; i++) {
        dest[i] = src[i];
    }
    for (; i < n; i++) {
        dest[i] = '\0';
    }
}

int comparar_strings(const char *s1, const char *s2)
{
    while (*s1 && (*s1 == *s2)) {
        s1++;
        s2++;
    }
    return *(const unsigned char *)s1 - *(const unsigned char *)s2;
}

int adicionar_produto(int codigo, const char *nome, int quantidade, float preco, const char *data_validade)
{
    if (total_produtos >= MAX_PRODUTOS)
        return -1;

    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo)
            return -2;
    }

    if (quantidade <= 0)
        return -3;
    if (preco <= 0)
        return -4;

    estoque[total_produtos].codigo = codigo;
    copiar_string(estoque[total_produtos].nome, nome, 49);
    estoque[total_produtos].quantidade = quantidade;
    estoque[total_produtos].preco = preco;
    copiar_string(estoque[total_produtos].data_validade, data_validade, DATA_LENGTH - 1);

    total_produtos++;
    return 0;
}

int atualizar_estoque(int opcao, int codigo, int quantidade, float novo_preco)
{
    int index = -1;
    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            index = i;
            break;
        }
    }
    if (index == -1)
        return -1;

    switch (opcao) {
        case 1:
            if (quantidade <= 0)
                return -2;
            estoque[index].quantidade += quantidade;
            return estoque[index].quantidade;

        case 2:
            if (quantidade <= 0)
                return -2;
            if (quantidade > estoque[index].quantidade)
                return -3;
            estoque[index].quantidade -= quantidade;
            return estoque[index].quantidade;

        case 3:
            if (novo_preco <= 0)
                return -4;
            estoque[index].preco = novo_preco;
            return 0;

        default: return -5;
    }
}

// Implementações das funções que estariam em relatorio.c
int tamanho_string(const char *s)
{
    int len = 0;
    while (s[len] != '\0')
        len++;
    return len;
}

const char *encontrar_substring(const char *haystack, const char *needle)
{
    if (!*needle)
        return haystack;

    for (int i = 0; haystack[i]; i++) {
        if (haystack[i] == needle[0]) {
            int j = 1;
            while (needle[j] && haystack[i + j] == needle[j])
                j++;
            if (!needle[j])
                return haystack + i;
        }
    }
    return NULL;
}

int verificar_validade(char *resultados[], int *total_resultados)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char data_atual[DATA_LENGTH];
    sprintf(data_atual, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    int count = 0;
    for (int i = 0; i < total_produtos; i++) {
        if (comparar_strings(estoque[i].data_validade, data_atual) < 0) {
            char *buffer = malloc(200);
            sprintf(buffer, "[VENCIDO] Código: %d | Nome: %s | Validade: %s",
                    estoque[i].codigo, estoque[i].nome, estoque[i].data_validade);
            resultados[count++] = buffer;
        }
    }
    *total_resultados = count;
    return count;
}

void concatenar_string(char *dest, const char *src)
{
    int len = tamanho_string(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[len + i] = src[i];
        i++;
    }
    dest[len + i] = '\0';
}

void gerar_relatorio(char *relatorio)
{
    relatorio[0] = '\0';
    char temp[200];

    sprintf(temp, "--- Relatório Completo do Estoque ---\nTotal de produtos: %d\n\n", total_produtos);
    concatenar_string(relatorio, temp);

    concatenar_string(relatorio, "Código    Nome                Quantidade Preço     Validade\n");
    concatenar_string(relatorio, "----------------------------------------------------------\n");

    float valor_total = 0;
    for (int i = 0; i < total_produtos; i++) {
        sprintf(temp, "%-10d %-20s %-10d R$%-8.2f %-12s\n",
                estoque[i].codigo,
                estoque[i].nome,
                estoque[i].quantidade,
                estoque[i].preco,
                estoque[i].data_validade);
        concatenar_string(relatorio, temp);
        valor_total += estoque[i].quantidade * estoque[i].preco;
    }

    sprintf(temp, "\nValor total em estoque: R$%.2f\n", valor_total);
    concatenar_string(relatorio, temp);
}

int buscar_produto(int opcao, const char *termo, char *resultados[], int *total_resultados)
{
    *total_resultados = 0;
    int count = 0;

    if (opcao == 1) {
        int codigo = atoi(termo);
        for (int i = 0; i < total_produtos; i++) {
            if (estoque[i].codigo == codigo) {
                char *buffer = malloc(200);
                sprintf(buffer, "Código: %d | Nome: %s | Quantidade: %d | Preço: R$%.2f | Validade: %s",
                        estoque[i].codigo, estoque[i].nome, estoque[i].quantidade,
                        estoque[i].preco, estoque[i].data_validade);
                resultados[count++] = buffer;
                break;
            }
        }
    } else if (opcao == 2) {
        for (int i = 0; i < total_produtos; i++) {
            if (encontrar_substring(estoque[i].nome, termo) != NULL) {
                char *buffer = malloc(200);
                sprintf(buffer, "[%d] %s - %d unidades - R$%.2f - Val: %s",
                        estoque[i].codigo,
                        estoque[i].nome,
                        estoque[i].quantidade,
                        estoque[i].preco,
                        estoque[i].data_validade);
                resultados[count++] = buffer;
            }
        }
    } else {
        return -1;
    }

    *total_resultados = count;
    return count;
}

// Implementações das funções que estariam em persistencia.c
int salvar_estoque()
{
    FILE *arquivo = fopen("estoque.txt", "w");
    if (!arquivo)
        return -1;

    for (int i = 0; i < total_produtos; i++) {
        fprintf(arquivo, "%d;%s;%d;%.2f;%s\n",
                estoque[i].codigo,
                estoque[i].nome,
                estoque[i].quantidade,
                estoque[i].preco,
                estoque[i].data_validade);
    }

    fclose(arquivo);
    return 0;
}

int carregar_estoque()
{
    FILE *arquivo = fopen("estoque.txt", "r");
    if (!arquivo)
        return -1;

    total_produtos = 0;
    char linha[200];

    while (fgets(linha, sizeof(linha), arquivo) && total_produtos < MAX_PRODUTOS) {
        int i = 0, j = 0;

        // Parse do código
        estoque[total_produtos].codigo = 0;
        while (linha[i] != ';') {
            estoque[total_produtos].codigo = estoque[total_produtos].codigo * 10 + (linha[i] - '0');
            i++;
        }
        i++;

        // Parse do nome
        j = 0;
        while (linha[i] != ';' && j < 49) {
            estoque[total_produtos].nome[j++] = linha[i++];
        }
        estoque[total_produtos].nome[j] = '\0';
        i++;

        // Parse da quantidade
        estoque[total_produtos].quantidade = 0;
        while (linha[i] != ';') {
            estoque[total_produtos].quantidade = estoque[total_produtos].quantidade * 10 + (linha[i] - '0');
            i++;
        }
        i++;

        // Parse do preço
        float frac = 0.1f;
        estoque[total_produtos].preco = 0;
        while (linha[i] != ';') {
            if (linha[i] == '.') {
                i++;
                while (linha[i] != ';') {
                    estoque[total_produtos].preco += (linha[i] - '0') * frac;
                    frac *= 0.1f;
                    i++;
                }
            } else {
                estoque[total_produtos].preco = estoque[total_produtos].preco * 10 + (linha[i] - '0');
                i++;
            }
        }
        i++;

        // Parse da data
        j = 0;
        while (linha[i] != '\0' && linha[i] != '\n' && j < DATA_LENGTH - 1) {
            estoque[total_produtos].data_validade[j++] = linha[i++];
        }
        estoque[total_produtos].data_validade[j] = '\0';

        total_produtos++;
    }

    fclose(arquivo);
    return total_produtos;
}

// Função principal
void limpar_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int main()
{
    carregar_estoque();

    int opcao;
    do {
        printf("\n=== Sistema de Controle de Estoque ===\n");
        printf("1. Cadastrar novo produto\n");
        printf("2. Verificar produtos em estoque\n");
        printf("3. Verificar validade dos produtos\n");
        printf("4. Atualizar estoque\n");
        printf("5. Salvar atualizações\n");
        printf("6. Gerar relatório completo\n");
        printf("7. Buscar produtos\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limpar_buffer();

        switch (opcao) {
            case 1: {
                int codigo, quantidade;
                char nome[50], data_validade[DATA_LENGTH];
                float preco;

                printf("Código: ");
                scanf("%d", &codigo);
                limpar_buffer();
                printf("Nome: ");
                scanf(" %[^\n]", nome);
                printf("Quantidade: ");
                scanf("%d", &quantidade);
                printf("Preço: ");
                scanf("%f", &preco);
                printf("Data de validade (DD/MM/AAAA): ");
                scanf("%10s", data_validade);

                int resultado = adicionar_produto(codigo, nome, quantidade, preco, data_validade);
                if (resultado == -1)
                    printf("Erro: Estoque cheio!\n");
                else if (resultado == -2)
                    printf("Erro: Código já existe!\n");
                else if (resultado == -3)
                    printf("Erro: Quantidade inválida!\n");
                else if (resultado == -4)
                    printf("Erro: Preço inválido!\n");
                else
                    printf("Produto adicionado com sucesso!\n");
                break;
            }

            case 2: {
                printf("\n--- Produtos em Estoque ---\n");
                for (int i = 0; i < total_produtos; i++) {
                    printf("[%d] %s - %d unidades\n",
                           estoque[i].codigo, estoque[i].nome, estoque[i].quantidade);
                }
                break;
            }

            case 3: {
                char *resultados[MAX_PRODUTOS];
                int total;

                verificar_validade(resultados, &total);
                printf("\n--- Produtos Vencidos ---\n");
                if (total == 0)
                    printf("Nenhum produto vencido.\n");
                else {
                    for (int i = 0; i < total; i++) {
                        printf("%s\n", resultados[i]);
                        free(resultados[i]);
                    }
                }
                break;
            }

            case 4: {
                int sub_opcao, codigo, quantidade;
                float novo_preco;

                printf("\n--- Atualização de Estoque ---\n");
                printf("1. Adicionar quantidade\n2. Remover quantidade\n3. Alterar preço\n");
                printf("Escolha: ");
                scanf("%d", &sub_opcao);
                printf("Código do produto: ");
                scanf("%d", &codigo);

                if (sub_opcao == 1 || sub_opcao == 2) {
                    printf("Quantidade: ");
                    scanf("%d", &quantidade);
                    novo_preco = 0;
                } else if (sub_opcao == 3) {
                    printf("Novo preço: ");
                    scanf("%f", &novo_preco);
                    quantidade = 0;
                }

                int resultado = atualizar_estoque(sub_opcao, codigo, quantidade, novo_preco);
                if (resultado == -1)
                    printf("Produto não encontrado!\n");
                else if (resultado == -2)
                    printf("Quantidade inválida!\n");
                else if (resultado == -3)
                    printf("Quantidade maior que estoque!\n");
                else if (resultado == -4)
                    printf("Preço inválido!\n");
                else if (resultado == -5)
                    printf("Opção inválida!\n");
                else if (sub_opcao == 1 || sub_opcao == 2)
                    printf("Quantidade atualizada: %d\n", resultado);
                else
                    printf("Preço atualizado!\n");
                break;
            }

            case 5: {
                if (salvar_estoque() == -1)
                    printf("Erro ao salvar!\n");
                else
                    printf("Estoque salvo com sucesso!\n");
                break;
            }

            case 6: {
                char relatorio[5000];
                gerar_relatorio(relatorio);
                printf("\n%s", relatorio);
                break;
            }

            case 7: {
                int sub_opcao;
                char termo[50];
                char *resultados[MAX_PRODUTOS];
                int total;

                printf("\n--- Busca ---\n");
                printf("1. Por código\n2. Por nome\nEscolha: ");
                scanf("%d", &sub_opcao);
                limpar_buffer();
                printf("Termo: ");
                scanf(" %[^\n]", termo);

                if (buscar_produto(sub_opcao, termo, resultados, &total) == -1) {
                    printf("Opção inválida!\n");
                } else if (total == 0) {
                    printf("Nenhum resultado.\n");
                } else {
                    for (int i = 0; i < total; i++) {
                        printf("%s\n", resultados[i]);
                        free(resultados[i]);
                    }
                    printf("Total: %d\n", total);
                }
                break;
            }

            case 0: printf("Saindo...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while (opcao != 0);

    return 0;
}