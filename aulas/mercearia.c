
// • Fluxo de decisão: Controle de fluxo condicional baseado em entradas do usuário e/ou valores calculados.

// • Laços de repetição: Controle de fluxo iterativo para repetição de comandos com base na necessidade do programa.

// • Funções: O código deve ser dividido em módulos isolados com chamadas por referência para alteração e/ou cálculo de valores.

// • Ponteiros: Manipulação eficiente de dados através do uso de ponteiros.

// • Estruturas e arranjos: Armazenamento estruturado de informações na memória para representar registros de dados e facilitar a organização do código.

// • Manipulação de arquivos: Criar, ler, gravar e atualizar dados em arquivos de texto de forma segura e livre de erros.

// • Interface iterativa via terminal: O programa deve exibir um menu iterativo para que o usuário possa navegar por diversas opções de uso.

// • Restrição de interação: Apenas a função main() pode interagir com o usuário (ler e escrever com terminal).

// Menu Principal:
// 1.Cadastrar novo produto
// 2.Verificar os produtos em estoque
// 3.Verificar a validade dos produtos
// 4.Atualizar estoque
// 5.Salvar atualizações
// 6.Gerar relatório completo
// 7.Busca de produtos
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#ifndef produtos_h  // para modularizar o programa
#define PRODUTOS_H
#endif  // fim

#define MAX_PRODUTOS 100
#define DATA 11

typedef struct {
    int codigo;
    char nome[50];
    int quantidade;
    float preco;
    char data_validade[DATA];
} Produto;

Produto estoque[MAX_PRODUTOS];
int total_produtos = 0;

int adicionar_produto(int codigo, const char *nome, int quantidade, float preco, const char *data_validade)
{
    if (total_produtos >= MAX_PRODUTOS) {
        return -1;
    }

    for (int i = 0; i < total_produtos; i++) {
        if (estoque[i].codigo == codigo) {
            return -2;
        }
    }

    if (quantidade <= 0) {
        return -3;
    }

    if (preco <= 0) {
        return -4;
    }

    Produto novo_produto;
    novo_produto.codigo = codigo;
    strncpy(novo_produto.nome, nome, 49);
    novo_produto.nome[49] = '\0';
    novo_produto.quantidade = quantidade;
    novo_produto.preco = preco;
    strncpy(novo_produto.data_validade, data_validade, DATA - 1);
    novo_produto.data_validade[DATA - 1] = '\0';

    estoque[total_produtos] = novo_produto;
    total_produtos++;

    return 0;
}

int verificar_validade(char *resultados[], int *total_resultados)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    char data_atual[DATA];
    sprintf(data_atual, "%02d/%02d/%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    *total_resultados = 0;
    int count = 0;

    for (int i = 0; i < total_produtos; i++) {
        if (strcmp(estoque[i].data_validade, data_atual) < 0) {
            char buffer[200];
            sprintf(buffer, "[VENCIDO] Código: %d | Nome: %s | Validade: %s",
                    estoque[i].codigo, estoque[i].nome, estoque[i].data_validade);
            resultados[count] = strcpy(buffer);
            count++;
        }
    }
