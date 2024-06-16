#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
  char modelo[50];
  char marca[50];
  int ano;
  char placa[10];
  char cor[20];
  float quilometragem;
  char tipoCombustivel[20];
  float preco;
  char *acessorios[MAX_ACESSORIOS]; // Vetor para armazenar acessórios
  int numAcessorios; // Número de acessórios cadastrados
  int status; // 0: Disponível, 1: Reservado, 2: Vendido
} Veiculo;

// Funções para gerenciamento de veículos (implementação a ser desenvolvida)
void cadastrarVeiculo(Veiculo *veiculos, int *numVeiculos);
void atualizarVeiculo(Veiculo *veiculos, int numVeiculos);
void buscarVeiculoPorModelo(Veiculo *veiculos, int numVeiculos, char *modelo);
void listarVeiculosDisponiveis(Veiculo *veiculos, int numVeiculos);
void reservarVeiculo(Veiculo *veiculo, int *status);
void cancelarReservaVeiculo(Veiculo *veiculo, int *status);
