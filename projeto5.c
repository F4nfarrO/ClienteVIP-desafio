#include <stdio.h>

char nome[50], clienteVIP[10];
int idade;
float valorCompra;
float desconto;

void dadosCliente(){

    printf("Formulário de cadastro do cliente\n\n");

    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);

    printf("Digite a idade do cliente: ");
    scanf("%d", &idade);

    printf("Digite o valor da compra: ");
    scanf("%f", &valorCompra);

    getchar(); // Limpa o buffer do teclado

    printf("O cliente é VIP? (sim/nao): ");
    fgets(clienteVIP, sizeof(clienteVIP), stdin);
}

void calcularDesconto(){ // Função para calcular o desconto com base no valor da compra e se o cliente é VIP

    if (valorCompra >=1000 || valorCompra >= 500 && (clienteVIP[0] == 's' || clienteVIP[0] == 'S')) {
        desconto = valorCompra * 0.20;
        printf("O cliente tem direito a 20%% de desconto\n");
    } else if (valorCompra <= 500 && (clienteVIP[0] == 's' || clienteVIP[0] == 'S')) {
        desconto = valorCompra * 0.10;
        printf("O cliente tem direito a 10%% de desconto\n");
    } else if (valorCompra >= 500 && valorCompra >= 1000 && (clienteVIP[0] == 'n' || clienteVIP[0] == 'N')) {
        desconto = valorCompra * 0.10;
        printf("O cliente tem direito a 10%% de desconto\n");
    } else if (valorCompra <= 500 && (clienteVIP[0] == 'n' || clienteVIP[0] == 'N')) {
        printf("O cliente não tem direito a de desconto\n");
    }

}

void exibirDadosCliente() { // Função para exibir os dados do cliente

    printf("\n===NOTA FISCAL===\n");
    printf("Nome: %s", nome); // O fgets já inclui a nova linha, então não é necessário adicionar \n
    printf("Idade: %d\n", idade); // Corrigido para exibir a idade corretamente
    printf("Valor da compra: %.2f\n", valorCompra);// Corrigido para exibir o valor da compra corretamente
    printf("Cliente VIP: %s", clienteVIP); // O fgets já inclui a nova linha, então não é necessário adicionar \n
    printf("Valor de desconto: %.2f\n", desconto);// Corrigido para exibir o desconto corretamente

}

int main() { // Função principal do programa para executar as funções de cadastro, cálculo de desconto e exibição dos dados do cliente
    dadosCliente();
    calcularDesconto();
    exibirDadosCliente();
    return 0;
}
