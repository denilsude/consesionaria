#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cliente {
  int id;
  char nome[50];
  char endereco[100];
  char cpf[15];
  char telefone[20];
  char email[50];
  int historicoCompras[MAX_COMPRAS]; // Vetor para armazenar IDs das compras
  int numCompras; // Número de compras realizadas
} Cliente;

// Funções para gerenciamento de clientes (implementação a ser desenvolvida)
void cadastrarCliente(Cliente *clientes, int *numClientes);
void atualizarCliente(Cliente *clientes, int numClientes);
void buscarClientePorNome(Cliente *clientes, int numClientes, char *nome);
void listarClientes(Cliente *clientes, int numClientes);
void consultarHistoricoCompras(Cliente *cliente);
