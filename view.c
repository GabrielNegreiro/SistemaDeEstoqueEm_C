#include <stdio.h>
#include <string.h>
//#include <stdbool.h>
//#include <stdlib.h>
//#include <ctype.h>

#define MAX_CODIGO 20
#define MAX_PRODUTOS 100
#define MAX_NOME 100
#define MAX_TIPO 100

typedef struct{
    char codigo[MAX_CODIGO] ;
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    float precovenda;
    float precocompra;
    //int estoqueBaixo; 
    int quantidade;
    int id;
    int totalProdutosDeEntrada;
    int totalProdutosDeSaida;
    float totalValorDeEntrada;
    float totalValorSaida;
} Produto;


Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

float TotalDeValorCompras = 0;
float TotalDeValorVendas = 0;

void limparBuffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF) { }}


// adicionar produto 
void adicionarProduto() {
    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Número máximo de produtos atingido!\n");
        printf("\n");
        return;
    }

    Produto novoProduto;
    printf("Digite o código do produto: ");
    scanf(" %[^\n]s", novoProduto.codigo);
 

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, novoProduto.codigo) == 0) { 
            printf("\n");
            printf("--------------------------------------\n");
            printf("Este código já foi cadastrado no sistema! \n ");
            printf("--------------------------------------\n");     
            printf("\n");
            return; 
        }
    }
    
    printf("Digite o nome do produto: ");
    scanf(" %[^\n]s", novoProduto.nome);
    printf("Digite o tipo do produto: ");
    scanf(" %[^\n]s", novoProduto.tipo);

    printf("Digite o preço da compra do produto: ");
    if(scanf(" %f", &novoProduto.precocompra)!=1){
        limparBuffer();
        printf("Erro ao digitar o preço da compra!\n");
        return;
    }
    if(novoProduto.precocompra>1500 || novoProduto.precocompra<0){
        printf("\n");
        printf("Não é um valor valido!\n");
        printf("\n");
        return;
    }
    printf("Digite o preço de venda do produto: ");
    if(scanf(" %f", &novoProduto.precovenda)!=1){
        limparBuffer();
        printf("Erro ao digitar o preço de venda!\n");
        return;
    }
    if(novoProduto.precovenda>3000 || novoProduto.precovenda<0){
        printf("\n");
        printf("Não é um valor valido!\n");
        printf("\n");
        return;
    }
    printf("Digite a quantidade inicial do estoque: ");
    if(scanf(" %d", &novoProduto.quantidade)!=1){
        limparBuffer();
        printf("Erro ao digitar a quantidade inicial!\n");
        return;
    }
    if(novoProduto.quantidade<0 || novoProduto.quantidade>10000){
        printf("\n");
        printf("Não é um valor valido!\n");
        printf("\n");
        return;
    }
    novoProduto.id = totalProdutos + 1;
    float total = novoProduto.precocompra * novoProduto.quantidade;
    novoProduto.totalProdutosDeEntrada = novoProduto.quantidade;
    novoProduto.totalProdutosDeSaida = 0;
    novoProduto.totalValorDeEntrada = total;
    novoProduto.totalValorSaida = 0;
    produtos[totalProdutos] = novoProduto;
    totalProdutos++;
    TotalDeValorCompras += total;
    printf("\n");
    printf("------------------------------------\n");
    printf("| Produto adicionado com sucesso! |\n");
    printf("------------------------------------\n");
    printf("\n");
}

    //listar produtos
void listarProdutos() {
    if (totalProdutos == 0) {
        printf("\n");
        printf("----------------------------- \n");
        printf("Nenhum produto cadastrado!\n");
        printf("-----------------------------\n");
        printf("\n");

                                                                                            
        return;
    }
    for (int i = 0; i < totalProdutos; i++) { 
        printf("\n");
        printf("------------------------------------- \n");
        printf("Nome: %s\n", produtos[i].nome);
        printf("Tipo: %s\n", produtos[i].tipo);
        printf("Codigo: %s\n", produtos[i].codigo);
        //printf("Preço de unitario de venda: %f\n", produtos[i].precovenda);
        //printf("Preço de custo: %f\n", produtos[i].precocompra);
        //printf("Quantidade no estoque: %d\n", produtos[i].quantidade);
        //printf("Total de Produtos Comprados: %d\n", produtos[i].totalProdutosDeEntrada);
        printf("------------------------------------- \n");
        printf("\n");
    }
}
//consultar produto
void consultarProduto() {
    char codigoBusca[MAX_CODIGO];
    printf("\n");
    printf("Digite o codigo do produto que deseja buscar: ");
    scanf(" %[^\n]s", codigoBusca);
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("\n");
            printf("------------------------------------- \n");

            printf("Nome: %s\n", produtos[i].nome);
            printf("Tipo: %s\n", produtos[i].tipo);
            printf("codigo: %s\n", produtos[i].codigo);
            printf("Preço de compra: %.2f\n", produtos[i].precocompra);
            printf("Preço de venda: %.2f\n", produtos[i].precovenda);
            printf("Quantidade no estoque: %d\n", produtos[i].quantidade);
            printf("Total de Produtos Comprados: %d\n", produtos[i].totalProdutosDeEntrada); 
            printf("Total produtos de Vendidos: %d\n", produtos[i].totalProdutosDeSaida);
            printf("------------------------------------- \n");

            return;
        }
    }
    printf("\n"); 
    printf("------------------------------\n");
    printf("| Ops! Produto não encontrado! |\n");
    printf("------------------------------\n");

}
// editar produto 
void editarProduto() {
    char codigoBusca[MAX_CODIGO];
    int quatidadeRetirada;
    printf("Digite o codigo do produto que deseja modificar: ");
    scanf(" %[^\n]s", codigoBusca);
    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0) {
            printf("\n");
            printf("Produto encontrado!\n");
            printf("------------------------------------- \n");

            printf("Codigo atual: %s\n", produtos[i].codigo);
            printf("Digite um novo codigo para o produto:");
            scanf(" %[^\n]s", produtos[i].codigo);

            printf("Nome atual: %s\n", produtos[i].nome);
            printf("Digite o novo nome do produto: ");
            scanf(" %[^\n]s", produtos[i].nome);

            printf("Tipo atual do produto: %s\n", produtos[i].tipo);
            printf("Digite a novo tipo do produto: ");
            scanf(" %[^\n]s", produtos[i].tipo);

            printf("Estoque atual do produto: %d\n", produtos[i].quantidade);
            printf("\n");
            printf("----------------------------------------------\n");
            printf("AVISO!\n");
            printf("Caso não houve um erro no resgitro do estoque. Desconsidere essa opção digitando 0\n");
            printf("----------------------------------------------\n");
            printf("\n");
            printf("Digite a correção de quantos produtos deseja retirar do estoque: ");
            if(scanf("%d", &quatidadeRetirada)!=1){
                printf("Erro ao ler valor\n");
                return;
            }
            if(quatidadeRetirada <= produtos[i].quantidade){
            produtos[i].quantidade = ( produtos[i].quantidade- quatidadeRetirada);
            produtos[i].totalProdutosDeEntrada =  produtos[i].totalProdutosDeEntrada - quatidadeRetirada;
            produtos[i].totalValorDeEntrada =  (produtos[i].totalValorDeEntrada - (quatidadeRetirada * produtos[i].precocompra));
            TotalDeValorCompras = TotalDeValorCompras - (quatidadeRetirada * produtos[i].precocompra);
            }else{
                printf("Quantidade de produtos que deseja retirar é maior que o estoque!\n");
                return;
            }

            printf("Preço atual de compra do produto: %.2f\n", produtos[i].precocompra);
            printf("Digite o novo preço de compra do produto: ");
            if(scanf(" %f", &produtos[i].precocompra)!=1){
                limparBuffer();
                printf("Erro ao digitar o preço de compra!\n");
                return;
            }

            printf("Preço de atual de venda do produto: %.2f\n", produtos[i].precovenda);
            printf("Digite o novo preço de venda: ");
            if(scanf(" %f", &produtos[i].precovenda)!=1){
                limparBuffer();
                printf("Erro ao digitar o preço de venda!\n");
                return;
            }
            printf("------------------------------------- \n");
            printf("\n");
            printf("-------------------------------------\n");
            printf("Produto foi modificado com sucesso!\n");
            printf("-------------------------------------");

            printf("\n");

            return;
        }
    }
    
    printf("\n");
    printf("-------------------------------------\n");
    printf("Produto não encontrado!\n");
    printf("-------------------------------------\n");
    printf("\n");
}
//entrada do estoque

void entradaEstoque() { 
    char codigoBusca[MAX_CODIGO];
    int quantidadeEntrada;

    printf("Digite o código do produto para entrada de estoque: ");
    scanf(" %[^\n]s", codigoBusca);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0) { 
            printf("Produto encontrado!\n");
            printf("Digite a quantidade de produtos para adicionar ao estoque: ");
            if(scanf("%d", &quantidadeEntrada)!=1){
                limparBuffer();
                printf("\n");
                printf("Erro ao ler quantidade de produtos!\n");
                printf("\n");
                return;
            } 
            
            if(quantidadeEntrada<0 || quantidadeEntrada>10000){
                printf("\n");
                printf("Quantidade invalida!\n");
                printf("\n");

                return;
            }

            produtos[i].quantidade += quantidadeEntrada; 
            produtos[i].totalProdutosDeEntrada += quantidadeEntrada;
            produtos[i].totalValorDeEntrada += (produtos[i].precocompra * quantidadeEntrada); // Acumula corretamente
            TotalDeValorCompras += (produtos[i].precocompra * quantidadeEntrada); // Atualiza global

            printf("\n");
            printf("-------------------------------------\n"); 
            printf("Quantidade atualizada com sucesso!\n");
            printf("Nova quantidade em estoque: %d\n", produtos[i].quantidade); 
            printf("-------------------------------------\n");
            printf("\n");
            return;
        }
    }
    printf("\n");
    printf("-------------------------------------\n");
    printf("Produto não encontrado!\n");
    printf("-------------------------------------\n"); 
    printf("\n"); 
}

// Saída do estoque com aviso de estoque baixo
void saidaEstoque() {
    char codigoBusca[MAX_CODIGO];
    int quantidadeSaida;

    printf("Digite o código do produto para saída de estoque: ");
    scanf(" %[^\n]s", codigoBusca);

    for (int i = 0; i < totalProdutos; i++) {
        if (strcmp(produtos[i].codigo, codigoBusca) == 0) {
            printf("Produto encontrado!\n");
            printf("Digite a quantidade de produtos para remover do estoque: ");
            if(scanf("%d", &quantidadeSaida)!=1){
                limparBuffer();
                printf("\n");
                printf("Quantidade invalida!\n");
                printf("\n");
                return;
            }
            
            if (quantidadeSaida<0 || quantidadeSaida>10000){
                printf("\n");
                printf("Quantidade invalida!\n");
                printf("\n");
                return;
            }
            

            if (quantidadeSaida <= produtos[i].quantidade) {
                produtos[i].quantidade -= quantidadeSaida;
                produtos[i].totalProdutosDeSaida += quantidadeSaida;
                produtos[i].totalValorSaida += produtos[i].precovenda * quantidadeSaida;
                TotalDeValorVendas += produtos[i].precovenda * quantidadeSaida;

                printf("\n");
                printf("-------------------------------------\n");
                printf("Quantidade atualizada com sucesso!\n");
                printf("Nova quantidade em estoque: %d\n", produtos[i].quantidade);
                printf("-------------------------------------\n");

                // Verificar se o estoque está baixo
                if (produtos[i].quantidade <= 3) {
                    printf("\n");
                    printf("-------------------------------------\n");
                    printf("AVISO: Estoque baixo para o produto!\n");
                    printf("Produto: %s\n", produtos[i].nome);
                    printf("Quantidade atual: %d\n", produtos[i].quantidade);
                    printf("-------------------------------------\n");
                    printf("\n");
                }
            } else {
                printf("\n");
                printf("-------------------------------------\n");
                printf("Quantidade invalida para a saída!\n");
                printf("Reabasteça o estoque!\n");
                printf("-------------------------------------\n");
            }
            return;
        }
    }
    printf("\n");
    printf("-------------------------------------\n");
    printf("Produto não encontrado!\n");
    printf("-------------------------------------\n");
    printf("\n");
}


// consulta do caixa
void consultarCaixa() {
    char entrada[99];
    char opcao;
    char codigoBusca[MAX_CODIGO];
    
    printf("\n-------------------------------------\n");
    printf("Resumo do Caixa:\n");
    printf("-------------------------------------\n");
    printf("Total gasto em compras: R$ %.2f\n", TotalDeValorCompras);
    printf("Total adquirido em vendas: R$ %.2f\n", TotalDeValorVendas);
    if((TotalDeValorVendas - TotalDeValorCompras)>0){
    printf("Lucro total: R$ %.2f\n", TotalDeValorVendas - TotalDeValorCompras);
    }else{
        printf("Prejuízo total: R$ %.2f\n", TotalDeValorVendas - TotalDeValorCompras);
    }
    printf("-------------------------------------\n");
    do{
        printf("Deseja consultar o desempenho de um produto específico? (S/N): ");
        scanf(" %99s", entrada);
        if (strlen(entrada) == 1) {
            opcao = entrada[0];
        }
        
        if(opcao != 'S' && opcao != 'N' && opcao != 's' && opcao != 'n'){
            printf("Entrada inválida!\n");
            return;
        }
    
        if (opcao == 'S' || opcao == 's') {
            printf("Digite o código do produto: ");
            scanf(" %[^\n]s", codigoBusca);
            int i;
            for (i = 0; i < totalProdutos; i++) {
                if (strcmp(produtos[i].codigo, codigoBusca) == 0) {
                    printf("\nProduto encontrado!\n");
                    printf("-------------------------------------\n");
                    printf("Nome: %s\n", produtos[i].nome);
                    printf("Quantidade total comprada: %d\n", produtos[i].totalProdutosDeEntrada);
                    printf("Valor total gasto em compras: R$ %.2f\n", produtos[i].totalValorDeEntrada);
                    printf("-------------------------------------\n");
                    printf("Quantidade total vendida: %d\n", produtos[i].totalProdutosDeSaida);
                    printf("Montante obtido com vendas: R$ %.2f\n", produtos[i].totalValorSaida);
                    printf("-------------------------------------\n");
                    if(( produtos[i].totalValorSaida - produtos[i].totalValorDeEntrada)>0){
                        printf("Lucro líquido com este produto: R$ %.2f\n", 
                        produtos[i].totalValorSaida - produtos[i].totalValorDeEntrada);
                    }else{
                        printf("Prejuízo líquido com este produto: R$ %.2f\n",  produtos[i].totalValorSaida - produtos[i].totalValorDeEntrada);
                        }
                    printf("-------------------------------------\n");
                    break;
                }   
            }if(i == totalProdutos){
                printf("\nProduto não encontrado!\n");
            }
        }
    }while(opcao == 'S' || opcao == 's');
}
    
//listar estoques zerados
void listarEstoquesZerados(){
     if (totalProdutos == 0) {
        printf("\n");
        printf("----------------------------- \n");
        printf("Nenhum produto cadastrado!\n");
        printf("-----------------------------\n");
        printf("\n");


        return;
    }
    for (int i = 0; i < totalProdutos; i++) { 
        if(produtos[i].quantidade == 0){
        printf("\n");
        printf("------------------------------------- \n");
        printf("Nome: %s\n", produtos[i].nome);
        printf("Tipo: %s\n", produtos[i].tipo);
        printf("Codigo: %s\n", produtos[i].codigo);
        //printf("Preço de unitario de venda: %f\n", produtos[i].precovenda);
        //printf("Preço de custo: %f\n", produtos[i].precocompra);
        //printf("Quantidade no estoque: %d\n", produtos[i].quantidade);
        //printf("Total de Produtos Comprados: %d\n", produtos[i].totalProdutosDeEntrada);
        printf("------------------------------------- \n");
        printf("\n");
        }else{
            printf("\n");
            printf("Todos os produtos com estoque cheio!\n");
        }
    } 
}

//estimativa de compra 
void estimativaDeCompra(){
    if (totalProdutos == 0) {
        printf("\n");
        printf("----------------------------- \n");
        printf("Nenhum produto cadastrado!\n");
        printf("-----------------------------\n");
        printf("\n");
        return;
    }
    char codigoBusca[MAX_CODIGO];
    int opcaoCompra;
    int opcaoVenda;
        printf("\n");
        printf("Digite o codigo do produto: ");
        scanf(" %[^\n]s", codigoBusca);
        int i;
        for (i = 0; i < totalProdutos; i++) {
            if (strcmp(produtos[i].codigo, codigoBusca) == 0) {
                printf("Produto encontrado!\n");
                printf("\n");
                printf("------------------------------------- \n");

                printf("Nome: %s\n", produtos[i].nome);
                printf("Tipo: %s\n", produtos[i].tipo);
                printf("codigo: %s\n", produtos[i].codigo);
                printf("Preço de compra: %.2f\n", produtos[i].precocompra);
                printf("Preço de venda: %.2f\n", produtos[i].precovenda);
                printf("\n");
                printf("----------------------------- \n");
            
                printf("Quantos produtos deseja estimar a compra: ");
                if(scanf("%d", &opcaoCompra)!=1){
                    printf("\n");
                    printf("Erro ao ler valor!\n");
                    printf("\n");
                    limparBuffer();
                    return;
                }
                if(opcaoCompra<0){
                    printf("\n");
                    printf("Quantidade invalida!\n");
                    printf("\n");
                }
                printf("\n");
                printf("Quantos produtos deseja estimar a venda: ");
                if(scanf("%d", &opcaoVenda)!=1){
                    printf("\n");
                    printf("Erro ao ler valor!\n");
                    printf("\n");
                    limparBuffer();
                    return;
                }
                if(opcaoVenda<0){
                    printf("\n");
                    printf("Quantidade invalida!\n");
                    printf("\n");
                }
                printf("----------------------------- \n");
                printf("Gasto na compra do produto: R$ %2.f", produtos[i].precocompra * opcaoCompra);
                printf("\n");
                printf("Gasto na venda do produto: R$ %2.f", produtos[i].precovenda * opcaoVenda);
                printf("\n");
                if(produtos[i].precovenda * opcaoVenda - produtos[i].precocompra * opcaoCompra > 0){
                    printf("Lucro do produto: R$ %2.f\n", produtos[i].precovenda * opcaoVenda - produtos[i].precocompra * opcaoCompra);
                }else{
                    printf("Prejuizo do produto: R$ %2.f\n", produtos[i].precovenda * opcaoVenda - produtos[i].precocompra * opcaoCompra);
                    printf("------------------------- \n");
                    return;
                }
               
            }
    
            printf("\nProduto não encontrado!\n");    
        }
            
}



    
int main(){
    int opcao;
do{
    printf("-------------------------------------------------------");
    printf("\n SISTEMA DE MERCADO\n");
    printf("-------------------------------------------------------\n");
    printf("1 - Cadastrar produto\n");
    printf("2 - Listar produtos\n");
    printf("3 - Consultar produto\n");
    printf("4 - Editar produto\n");
    printf("5 - Entrada do estoque\n");
    printf("6 - Saída do estoque\n");
    printf("7 - Consultar caixa\n");
    printf("8 - Estoques zerados\n");
    printf("9 - Estimativa Compra e venda\n");
    printf("10 - Sair\n");
    scanf("%d", &opcao);    
    limparBuffer();

    switch (opcao){
    case(1):
    adicionarProduto();
        break;
    case(2):
    listarProdutos(); 
    break;
    
    case(3):
    consultarProduto();
    break;

    case(4):
    editarProduto();
    break;

    case(5):
    entradaEstoque();
    break;

    case(6):
    saidaEstoque();
    break;

    case(7):
    consultarCaixa();
    break;

    case(8):
    listarEstoquesZerados();
    break;

    case(9):
    estimativaDeCompra();
    break;

    case(10):
    printf("Obrigado por usar o sistema!\n");
    break;

    default:
    printf("Opção invalida, tente novamente!\n");
        break;
    }
    
}while(opcao != 10);


return 0;
}

//DUPLA: Gabriel Santana e Eric Marques