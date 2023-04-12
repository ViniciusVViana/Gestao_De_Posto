#ifndef header_estoque_h
#define header_estoque_h
#include"header_database.h"

int buscaProduto(int id_produto, Produtos *produto){
    produto->quantidade = 0; //inicializa a quantidade do produto com 0
    produto->preco = 0;     //inicializa o preco do produto com 0
    int cont;

    for(cont = 0; cont < size_stock; cont++){

        if(id_produto == produto_posto[cont].identificacao_produto){

            if(produto_posto[cont].quantidade > 0){

                strcpy(produto->nome, produto_posto[cont].nome);
                produto->identificacao_produto = produto_posto[cont].identificacao_produto;
                produto->quantidade = produto_posto[cont].quantidade;
                produto->preco = produto_posto[cont].preco;
                produto->cat.identificacao_categoria_pai = produto_posto[cont].cat.identificacao_categoria_pai;
                produto->cat.identificacao_categoria = produto_posto[cont].cat.identificacao_categoria;
                strcpy(produto->cat.nome_categoria, produto_posto[cont].cat.nome_categoria);

                return 1;

            };

        };

    };

    return 0;

};

//ESTA FUNÇÃO ADICIONA UNIDADES DE UM CERTO PRODUTO AO ESTOQUE
int adicionar_estoque(){

    int busc, cont;
    float quant;

    printf("=--= Busque o item ao qual voce quer adicionar estoque pela identificacao (4 digitos)\nR: ");
    scanf("%i", &busc);
    fflush(stdin);

    for(cont = 0; cont < size_stock; cont++){

        if(busc == produto_posto[cont].identificacao_produto){

            printf("\n\n=-= O quanto desse item voce quer adicionar?\nR: ");
            scanf("%f", &quant);
            fflush(stdin);

            produto_posto[0].quantidade += quant;

            return 1;
        };
    };
    return 0;
};

//ESTA FUNÇÃO ADICIONA UM NOVO PRODUTO AO ESTOQUE
int novo_estoque(){

    size_stock += 1;
    produto_posto = (Produtos *)realloc(produto_posto, size_stock * sizeof(Produtos));

    printf("===---==---=== Cadastro de Novo Produto ===---==---===/n");

    printf("\n=--= Insira o nome do produto (string):\nR: ");
    gets(produto_posto[size_stock - 1].nome);
    fflush(stdin);
    printf("\n=--= Insira o codigo de identificacao do produto (integer):\nR: ");
    scanf("%i", &produto_posto[size_stock - 1].identificacao_produto);
    fflush(stdin);
    printf("\n=--= Insira o tamanho do estoque do produto (integer): \nR: ");
    scanf("%i", &produto_posto[size_stock - 1].quantidade);
    fflush(stdin);
    printf("\n=--= Insira o valor do produto (float): \nR: ");
    scanf("%f", &produto_posto[size_stock - 1].preco);
    fflush(stdin);
    printf("\n=--= Insira o nome da catgoria que o produto se encaixa (string): \nR: ");
    gets(produto_posto[size_stock - 1].cat.nome_categoria);
    fflush(stdin);
    printf("\n=--= Insira a categoria pai do produto (integer): \nR: ");
    scanf("%i", &produto_posto[size_stock - 1].cat.identificacao_categoria_pai);
    fflush(stdin);
    printf("\n=--= Insira a cattegoria do produto (integer): \nR: ");
    scanf("%i", &produto_posto[size_stock - 1].cat.identificacao_categoria);
    fflush(stdin);

    return 1;

};
void descontar_estoque(int id_produto, int quantidade){

    int cont;

    for(cont = 0; cont < size_stock; cont++){

        if(id_produto == produto_posto[cont].identificacao_produto){

            produto_posto[cont].quantidade -= quantidade;

        };

    };

};

#endif
