#include"header_database.h"
#ifndef header_estoque_h
#define header_estoque_h 

int buscaProduto(int id_produto, Produtos produto){

    int cont;

    for(cont = 0; cont < size_stock; cont++){

        if(id_produto == produto_posto[cont].identificacao_produto){

            if(produto_posto[cont].quantidade > 0){

                strcpy(produto.nome, produto_posto[cont].nome);
                produto.identificacao_produto = produto_posto[cont].identificacao_produto;
                produto.quantidade = produto_posto[cont].quantidade;
                produto.preco = produto_posto[cont].preco;
                produto.cat.identificacao_categoria_pai = produto_posto[cont].cat.identificacao_categoria_pai;
                produto.cat.identificacao_categoria = produto_posto[cont].cat.identificacao_categoria;
                strcpy(produto.cat.nome_categoria, produto_posto[cont].cat.nome_categoria);

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

    printf("Busque o item ao qual voce quer adicionar estoque pela identificacao (4 digitos).");
    scanf("%i", &busc);
    fflush(stdin);

    for(cont = 0; cont < size_stock; cont++){

        if(busc == produto_posto[cont].identificacao_produto){

            printf("O quanto desse item voce quer adicionar: ");
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

    printf("Agora insira as informacoes do novo produto: /n");

    printf("Insira o nome do produto: ");
    gets(produto_posto[size_stock - 1].nome);
    fflush(stdin);
    printf("Insira o codigo de identificacao do produto:");
    scanf("%i", &produto_posto[size_stock - 1].identificacao_produto);
    fflush(stdin);
    printf("Insira o tamanho do estoque do produto: ");
    scanf("%f", &produto_posto[size_stock - 1].quantidade);
    fflush(stdin);
    printf("Insira o valor do produto: ");
    scanf("%f", &produto_posto[size_stock - 1].preco);
    fflush(stdin);
    printf("Insira o nome da catgoria que o produto se encaixa: ");
    gets(produto_posto[size_stock - 1].cat.nome_categoria);
    fflush(stdin);
    printf("Insira a categoria pai do produto: ");
    scanf("%i", &produto_posto[size_stock - 1].cat.identificacao_categoria_pai);
    fflush(stdin);
    printf("insira a cattegoria do produto: ");
    scanf("%i", &produto_posto[size_stock - 1].cat.identificacao_categoria);
    fflush(stdin);

    return 1;

};

// void pos_venda(Produtos *produto){

//     for (int cont = 0; cont < size_stock; cont++){

//         if (produto->identificacao_produto == produto_posto[cont]->identificacao_produto){



//         };

//     };

// };

#endif