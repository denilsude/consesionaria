#include <stdio.h>
#include <stdlib.h>
#include "veiculos.c"
#include "clientes.c"

typedef struct Venda {
  int id;
  int idCliente;
  int idVeiculo;
  float valorTotal;
  float comissaoVendedor;
  char dataVenda[10];
  char formaPagamento[20];
  int status; // 0: Em andamento, 1: Concluída, 2: Cancelada
} Venda;

// Funções para gerenciamento de vendas (implementação a ser desenvolvida)
void registrarVenda(Veiculo *veiculos, int numVeiculos, Cliente *clientes, int numClientes, Venda *vendas, int *numVendas);
void listarVendas(Venda *vendas, int numVendas);
void buscarVendaPorId(Venda *vendas, int numVendas, int idVenda);
void calcularComissaoVendedor(Venda *venda, float *comissao);
void concluirVenda(Venda *venda, int *status);
void cancelarVenda(Venda *venda, int *status);
