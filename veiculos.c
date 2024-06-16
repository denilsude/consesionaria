#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ACESSORIOS 10

typedef struct {
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

// Funções para gerenciamento de veículos
void cadastrarVeiculo(Veiculo *veiculos, int *numVeiculos);
void atualizarVeiculo(Veiculo *veiculos, int numVeiculos);
void buscarVeiculoPorModelo(Veiculo *veiculos, int numVeiculos, char *modelo);
void listarVeiculosDisponiveis(Veiculo *veiculos, int numVeiculos);
void reservarVeiculo(Veiculo *veiculo, int *status);
void cancelarReservaVeiculo(Veiculo *veiculo, int *status);

int main() {
    Veiculo veiculos[50];   // Exemplo: array de veículos
    int numVeiculos = 0;    // Número inicial de veículos

    // Exemplo de uso das funções de veículos
    cadastrarVeiculo(veiculos, &numVeiculos);
    listarVeiculosDisponiveis(veiculos, numVeiculos);

    return 0;
}

void cadastrarVeiculo(Veiculo *veiculos, int *numVeiculos) {
    if (*numVeiculos >= 50) {
        printf("Limite máximo de veículos atingido.\n");
        return;
    }

    // Preenche os dados do veículo (simulação simples)
    strcpy(veiculos[*numVeiculos].modelo, "Civic");
    strcpy(veiculos[*numVeiculos].marca, "Honda");
    veiculos[*numVeiculos].ano = 2020;
    strcpy(veiculos[*numVeiculos].placa, "ABC1234");
    strcpy(veiculos[*numVeiculos].cor, "Prata");
    veiculos[*numVeiculos].quilometragem = 15000.0;
    strcpy(veiculos[*numVeiculos].tipoCombustivel, "Gasolina");
    veiculos[*numVeiculos].preco = 80000.0;
    veiculos[*numVeiculos].numAcessorios = 2;  // Exemplo: 2 acessórios cadastrados
    veiculos[*numVeiculos].acessorios[0] = "Bancos de Couro";
    veiculos[*numVeiculos].acessorios[1] = "Teto Solar";
    veiculos[*numVeiculos].status = 0;  // Disponível

    (*numVeiculos)++;  // Incrementa o número de veículos
    printf("Veículo cadastrado com sucesso.\n");
}

void atualizarVeiculo(Veiculo *veiculos, int numVeiculos) {
    // Implementação a ser desenvolvida
}

void buscarVeiculoPorModelo(Veiculo *veiculos, int numVeiculos, char *modelo) {
    int encontrou = 0;
    for (int i = 0; i < numVeiculos; i++) {
        if (strcmp(veiculos[i].modelo, modelo) == 0) {
            printf("Veículo encontrado:\n");
            printf("Modelo: %s\nMarca: %s\nAno: %d\nPlaca: %s\nCor: %s\n",
                   veiculos[i].modelo, veiculos[i].marca, veiculos[i].ano,
                   veiculos[i].placa, veiculos[i].cor);
            printf("Quilometragem: %.1f\nTipo de Combustível: %s\nPreço: %.2f\n",
                   veiculos[i].quilometragem, veiculos[i].tipoCombustivel, veiculos[i].preco);
            printf("Acessórios:\n");
            for (int j = 0; j < veiculos[i].numAcessorios; j++) {
                printf("- %s\n", veiculos[i].acessorios[j]);
            }
            printf("Status: %d\n", veiculos[i].status);
            encontrou = 1;
            break;
        }
    }
    if (!encontrou) {
        printf("Veículo com modelo '%s' não encontrado.\n", modelo);
    }
}

void listarVeiculosDisponiveis(Veiculo *veiculos, int numVeiculos) {
    if (numVeiculos == 0) {
        printf("Nenhum veículo cadastrado.\n");
        return;
    }

    printf("Lista de veículos disponíveis:\n");
    printf("Modelo | Marca | Ano | Placa | Cor | Quilometragem | Combustível | Preço\n");
    for (int i = 0; i < numVeiculos; i++) {
        if (veiculos[i].status == 0) {  // Veículo disponível
            printf("%s | %s | %d | %s | %s | %.1f | %s | %.2f\n", veiculos[i].modelo, veiculos[i].marca,
                   veiculos[i].ano, veiculos[i].placa, veiculos[i].cor, veiculos[i].quilometragem,
                   veiculos[i].tipoCombustivel, veiculos[i].preco);
        }
    }
}

void reservarVeiculo(Veiculo *veiculo, int *status) {
    if (*status != 0) {
        printf("O veículo não está disponível para reserva.\n");
        return;
    }

    *status = 1;  // Marca o veículo como reservado
    printf("Veículo reservado com sucesso.\n");
}

void cancelarReservaVeiculo(Veiculo *veiculo, int *status) {
    if (*status != 1) {
        printf("Não é possível cancelar a reserva deste veículo.\n");
        return;
    }

    *status = 0;  // Cancela a reserva do veículo
    printf("Reserva do veículo cancelada com sucesso.\n");
}
