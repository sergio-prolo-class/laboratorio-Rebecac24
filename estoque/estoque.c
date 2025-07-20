#include <stdio.h>
#include <stdlib.h>
#include "estoque.h"
#include "util.h"

void ler_string(const char *msg, char *str, int tam)
{
    printf("%s", msg);
    scanf(" %49[^\n]", str);
    limpar_buffer();
}

int ler_int(const char *msg)
{
    int v;
    printf("%s", msg);
    scanf("%d", &v);
    limpar_buffer();
    return v;
}

float ler_float(const char *msg)
{
    float v;
    printf("%s", msg);
    scanf("%f", &v);
    limpar_buffer();
    return v;
}

int main()
{
    carregar_estoque();
    int opcao;
    do {
        printf("\nSistema de Controle de Estoque:\n"
               "1. Cadastrar novo produto\n2. Ver produtos\n3. Ver validade\n"
               "4. Atualizar estoque\n5. Salvar\n6. Relatório\n7. Buscar\n0. Sair\nEscolha: ");
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            continue;
        }
        limpar_buffer();

        if (opcao == 1) {
            int codigo = ler_int("Código: ");
            char nome[50];
            ler_string("Nome: ", nome, 50);
            int quantidade = ler_int("Quantidade: ");
            float preco = ler_float("Preço: ");
            char data_validade[DATA_TAMANHO];
            do {
                ler_string("Data de validade (DD/MM/AAAA): ", data_validade, DATA_TAMANHO);
                if (!validar_data(data_validade))
                    printf("Formato inválido!\n");
            } while (!validar_data(data_validade));
            int r = adicionar_produto(codigo, nome, quantidade, preco, data_validade);
            if (r == 0)
                printf("Produto adicionado!\n");
            else
                printf("Erro ao adicionar produto (%d)\n", r);
        } else if (opcao == 2) {
            printf("\n--- Produtos em Estoque ---\n");
            if (total_produtos == 0)
                printf("Nenhum produto.\n");
            for (int i = 0; i < total_produtos; i++)
                printf("[%d] %s - %d un - R$%.2f - Val: %s\n", estoque[i].codigo, estoque[i].nome, estoque[i].quantidade, estoque[i].preco, estoque[i].data_validade);
        } else if (opcao == 3) {
            char *resultados[MAX_PRODUTOS];
            int total;
            verificar_validade(resultados, &total);
            printf("\n--- Produtos Vencidos ---\n");
            if (total == 0)
                printf("Nenhum produto vencido.\n");
            for (int i = 0; i < total; i++) {
                printf("%s\n", resultados[i]);
                free(resultados[i]);
            }
        } else if (opcao == 4) {
            int sub = ler_int("1.Adicionar 2.Remover 3.Preço: ");
            int codigo = ler_int("Código: ");
            int quantidade = (sub == 1 || sub == 2) ? ler_int("Quantidade: ") : 0;
            float preco = (sub == 3) ? ler_float("Novo preço: ") : 0;
            int r = atualizar_estoque(sub, codigo, quantidade, preco);
            if (r < 0)
                printf("Erro (%d)\n", r);
            else if (sub == 3)
                printf("Preço atualizado!\n");
            else
                printf("Quantidade atualizada: %d\n", r);
        } else if (opcao == 5) {
            if (salvar_estoque() == 0)
                printf("Estoque salvo!\n");
            else
                printf("Erro ao salvar!\n");
        } else if (opcao == 6) {
            char relatorio[5000];
            gerar_relatorio(relatorio);
            printf("\n%s", relatorio);
        } else if (opcao == 7) {
            int sub = ler_int("1.Código 2.Nome: ");
            char termo[50];
            ler_string("Termo: ", termo, 50);
            char *resultados[MAX_PRODUTOS];
            int total;
            int r = buscar_produto(sub, termo, resultados, &total);
            if (r == -1 || total == 0)
                printf("Nenhum produto encontrado.\n");
            else
                for (int i = 0; i < total; i++) {
                    printf("%s\n", resultados[i]);
                    free(resultados[i]);
                }
        } else if (opcao == 0)
            printf("Saindo...\n");
        else
            printf("Opção inválida!\n");
    } while (opcao != 0);
    return 0;
}