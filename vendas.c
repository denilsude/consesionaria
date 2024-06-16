#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "veiculos.h"
#include "clientes.h"

typedef struct {
    int id;
    int idCliente;
    int idVeiculo;
    float valorTotal;
    float comissaoVendedor;
    char dataVenda[11];         // Aumentei o tamanho para 11 para incluir o '\0'
    char formaPagamento[21];    // Aumentei o tamanho para 21 para incluir o '\0'
    int status;  // 0: Em andamento, 1: Concluída, 2: Cancelada
} Venda;

// Funções para gerenciamento de vendas
void registrarVenda(Veiculo *veiculos, int numVeiculos, Cliente *clientes, int numClientes, Venda *vendas, int *numVendas);
void listarVendas(Venda *vendas, int numVendas);
void buscarVendaPorId(Venda *vendas, int numVendas, int idVenda);
void calcularComissaoVendedor(Venda *venda, float *comissao);
void concluirVenda(Venda *venda);
void cancelarVenda(Venda *venda);

int main() {
    // Exemplo de uso das funções de vendas
    Veiculo veiculos[10];       // Exemplo: array de veículos
    Cliente clientes[5];        // Exemplo: array de clientes
    Venda vendas[20];           // Exemplo: array de vendas
    int numVendas = 0;          // Número inicial de vendas

    // Exemplo de chamada de função para registrar uma venda
    registrarVenda(veiculos, 10, clientes, 5, vendas, &numVendas);

    // Exemplo de chamada de função para listar vendas
    listarVendas(vendas, numVendas);

    // Exemplo de chamada de função para buscar uma venda por ID
    buscarVendaPorId(vendas, numVendas, 1);

    return 0;
}

void registrarVenda(Veiculo *veiculos, int numVeiculos, Cliente *clientes, int numClientes, Venda *vendas, int *numVendas) {
    if (*numVendas >= 20) {
        printf("Limite máximo de vendas atingido.\n");
        return;
    }

    // Simulação simples: seleciona o primeiro veículo e o primeiro cliente
    if (numVeiculos > 0 && numClientes > 0) {
        // Preenche os dados da venda
        vendas[*numVendas].id = *numVendas + 1;  // ID da venda
        vendas[*numVendas].idVeiculo = veiculos[0].id;  // ID do veículo
        vendas[*numVendas].idCliente = clientes[0].id;   // ID do cliente

        vendas[*numVendas].valorTotal = veiculos[0].preco; // Exemplo: preço do veículo
        vendas[*numVendas].comissaoVendedor = 0.1 * vendas[*numVendas].valorTotal; // Exemplo: comissão de 10%
        strcpy(vendas[*numVendas].dataVenda, "2024-06-16");  // Exemplo: data da venda
        strcpy(vendas[*numVendas].formaPagamento, "À vista"); // Exemplo: forma de pagamento

        vendas[*numVendas].status = 1;  // 1: Concluída

        (*numVendas)++;  // Incrementa o número de vendas
        printf("Venda registrada com sucesso.\n");
    } else {
        printf("Não há veículos ou clientes cadastrados para realizar a venda.\n");
    }
}

void listarVendas(Venda *vendas, int numVendas) {
    if (numVendas == 0) {
        printf("Nenhuma venda registrada.\n");
        return;
    }

    printf("Lista de vendas:\n");
    printf("ID | ID Cliente | ID Veículo | Valor Total | Data | Forma de Pagamento | Status\n");
    for (int i = 0; i < numVendas; i++) {
        printf("%d | %d | %d | %.2f | %s | %s | %d\n", vendas[i].id, vendas[i].idCliente, vendas[i].idVeiculo,
            vendas[i].valorTotal, vendas[i].dataVenda, vendas[i].formaPagamento, vendas[i].status);
    }
}

void buscarVendaPorId(Venda *vendas, int numVendas, int idVenda) {
    int encontrou = 0;
    for (int i = 0; i < numVendas; i++) {
        if (vendas[i].id == idVenda) {
            printf("Venda encontrada:\n");
            printf("ID | ID Cliente | ID Veículo | Valor Total | Data | Forma de Pagamento | Status\n");
            printf("%d | %d | %d | %.2f | %s | %s | %d\n", vendas[i].id, vendas[i].idCliente, vendas[i].idVeiculo,
                vendas[i].valorTotal, vendas[i].dataVenda, vendas[i].formaPagamento, vendas[i].status);
            encontrou = 1;
            break;
        }
    }
    if (!encontrou) {
        printf("Venda com ID %d não encontrada.\n", idVenda);
    }
}

void calcularComissaoVendedor(Venda *venda, float *comissao) {
    *comissao = venda->comissaoVendedor;
    printf("Comissão do vendedor calculada: %.2f\n", *comissao);
}

void concluirVenda(Venda *venda) {
    venda->status = 1;  // Marca a venda como concluída
    printf("Venda concluída com sucesso.\n");
}

void cancelarVenda(Venda *venda) {
    venda->status = 2;  // Marca a venda como cancelada
    printf("Venda cancelada com sucesso.\n");
}
