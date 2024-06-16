#include <stdio.h>
#include "veiculos.h"
#include "clientes.h"
#include "vendas.h"

#define MAX_VEICULOS 50
#define MAX_CLIENTES 50
#define MAX_VENDAS 100

int main() {
    Veiculo veiculos[MAX_VEICULOS];
    Cliente clientes[MAX_CLIENTES];
    Venda vendas[MAX_VENDAS];

    int numVeiculos = 0;
    int numClientes = 0;
    int numVendas = 0;

    int opcao;

    do {
        printf("\n### Sistema de Gerenciamento ###\n");
        printf("1. Gerenciar Veículos\n");
        printf("2. Gerenciar Clientes\n");
        printf("3. Gerenciar Vendas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                // Menu de gerenciamento de veículos
                printf("\n### Menu de Gerenciamento de Veículos ###\n");
                printf("1. Cadastrar Veículo\n");
                printf("2. Atualizar Veículo\n");
                printf("3. Buscar Veículo por Modelo\n");
                printf("4. Listar Veículos Disponíveis\n");
                printf("0. Voltar\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        cadastrarVeiculo(veiculos, &numVeiculos);
                        break;
                    case 2:
                        // Implementar função de atualizar veículo
                        break;
                    case 3: {
                        char modelo[50];
                        printf("Digite o modelo do veículo: ");
                        scanf(" %[^\n]s", modelo);
                        buscarVeiculoPorModelo(veiculos, numVeiculos, modelo);
                        break;
                    }
                    case 4:
                        listarVeiculosDisponiveis(veiculos, numVeiculos);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                break;

            case 2:
                // Menu de gerenciamento de clientes
                printf("\n### Menu de Gerenciamento de Clientes ###\n");
                printf("1. Cadastrar Cliente\n");
                printf("2. Atualizar Cliente\n");
                printf("3. Buscar Cliente por Nome\n");
                printf("4. Listar Clientes\n");
                printf("0. Voltar\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        cadastrarCliente(clientes, &numClientes);
                        break;
                    case 2:
                        // Implementar função de atualizar cliente
                        break;
                    case 3: {
                        char nome[50];
                        printf("Digite o nome do cliente: ");
                        scanf(" %[^\n]s", nome);
                        buscarClientePorNome(clientes, numClientes, nome);
                        break;
                    }
                    case 4:
                        listarClientes(clientes, numClientes);
                        break;
                    case 0:
                        break;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                break;

            case 3:
                // Menu de gerenciamento de vendas
                printf("\n### Menu de Gerenciamento de Vendas ###\n");
                printf("1. Registrar Venda\n");
                printf("2. Listar Vendas\n");
                printf("3. Buscar Venda por ID\n");
                printf("0. Voltar\n");
                printf("Escolha uma opção: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 1:
                        // Implementar função de registrar venda
                        break;
                    case 2:
                        // Implementar função de listar vendas
                        break;
                    case 3: {
                        int idVenda;
                        printf("Digite o ID da venda: ");
                        scanf("%d", &idVenda);
                        // Implementar função de buscar venda por ID
                        break;
                    }
                    case 0:
                        break;
                    default:
                        printf("Opção inválida.\n");
                        break;
                }
                break;

            case 0:
                printf("Saindo do sistema.\n");
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }

    } while (opcao != 0);

    return 0;
}
