#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COMPRAS 100

typedef struct {
    int id;
    char nome[50];
    char endereco[100];
    char cpf[15];
    char telefone[20];
    char email[50];
    int historicoCompras[MAX_COMPRAS]; // Vetor para armazenar IDs das compras
    int numCompras; // Número de compras realizadas
} Cliente;

// Funções para gerenciamento de clientes
void cadastrarCliente(Cliente *clientes, int *numClientes);
void atualizarCliente(Cliente *clientes, int numClientes);
void buscarClientePorNome(Cliente *clientes, int numClientes, char *nome);
void listarClientes(Cliente *clientes, int numClientes);
void consultarHistoricoCompras(Cliente *cliente);

int main() {
    Cliente clientes[50];   // Exemplo: array de clientes
    int numClientes = 0;    // Número inicial de clientes

    // Exemplo de uso das funções de clientes
    cadastrarCliente(clientes, &numClientes);
    listarClientes(clientes, numClientes);

    return 0;
}

void cadastrarCliente(Cliente *clientes, int *numClientes) {
    if (*numClientes >= 50) {
        printf("Limite máximo de clientes atingido.\n");
        return;
    }

    // Preenche os dados do cliente (simulação simples)
    clientes[*numClientes].id = *numClientes + 1;  // ID do cliente
    strcpy(clientes[*numClientes].nome, "João da Silva");
    strcpy(clientes[*numClientes].endereco, "Rua ABC, 123");
    strcpy(clientes[*numClientes].cpf, "123.456.789-00");
    strcpy(clientes[*numClientes].telefone, "(11) 9999-8888");
    strcpy(clientes[*numClientes].email, "joao@example.com");
    clientes[*numClientes].numCompras = 0;  // Inicializa número de compras

    (*numClientes)++;  // Incrementa o número de clientes
    printf("Cliente cadastrado com sucesso.\n");
}

void atualizarCliente(Cliente *clientes, int numClientes) {
    // Implementação a ser desenvolvida
}

void buscarClientePorNome(Cliente *clientes, int numClientes, char *nome) {
    int encontrou = 0;
    for (int i = 0; i < numClientes; i++) {
        if (strcmp(clientes[i].nome, nome) == 0) {
            printf("Cliente encontrado:\n");
            printf("ID: %d\nNome: %s\nEndereço: %s\nCPF: %s\nTelefone: %s\nEmail: %s\n",
                   clientes[i].id, clientes[i].nome, clientes[i].endereco, clientes[i].cpf,
                   clientes[i].telefone, clientes[i].email);
            encontrou = 1;
            break;
        }
    }
    if (!encontrou) {
        printf("Cliente com nome '%s' não encontrado.\n", nome);
    }
}

void listarClientes(Cliente *clientes, int numClientes) {
    if (numClientes == 0) {
        printf("Nenhum cliente cadastrado.\n");
        return;
    }

    printf("Lista de clientes:\n");
    printf("ID | Nome | CPF | Telefone | Email\n");
    for (int i = 0; i < numClientes; i++) {
        printf("%d | %s | %s | %s | %s\n", clientes[i].id, clientes[i].nome, clientes[i].cpf,
               clientes[i].telefone, clientes[i].email);
    }
}

void consultarHistoricoCompras(Cliente *cliente) {
    printf("Histórico de compras do cliente %s:\n", cliente->nome);
    if (cliente->numCompras == 0) {
        printf("Nenhuma compra realizada.\n");
    } else {
        printf("Compras realizadas:\n");
        for (int i = 0; i < cliente->numCompras; i++) {
            printf("- ID da compra: %d\n", cliente->historicoCompras[i]);
        }
    }
}
