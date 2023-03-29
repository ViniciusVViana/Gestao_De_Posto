#include"header_structs.h"

    /*struct Produtos* produto_posto = (struct Produtos*)malloc(4 * sizeof(struct Produtos));*/

struct Produtos produto_posto[4];

void criacao_estoque(){

    strcpy(produto_posto[0].nome,"Gasolina comum");
    produto_posto[0].identificacao_produto = 1111;
    produto_posto[0].quantidade = 1000;
    produto_posto[0].preco = 5.51;
    produto_posto[0].cat.identificacao_categoria_pai = 1;
    produto_posto[0].cat.identificacao_categoria = 1;

    strcpy(produto_posto[1].nome,"Gasolina aditivada");
    produto_posto[1].identificacao_produto = 1112;
    produto_posto[1].quantidade = 1000;
    produto_posto[1].preco = 5.51;
    produto_posto[1].cat.identificacao_categoria_pai = 1;
    produto_posto[1].cat.identificacao_categoria = 1;

    strcpy(produto_posto[2].nome,"Etanol");
    produto_posto[2].identificacao_produto = 1120;
    produto_posto[2].quantidade = 1000;
    produto_posto[2].preco = 4,87;
    produto_posto[2].cat.identificacao_categoria_pai = 1;
    produto_posto[2].cat.identificacao_categoria = 2;

    strcpy(produto_posto[3].nome,"Diesel");
    produto_posto[3].identificacao_produto = 1130;
    produto_posto[3].quantidade = 1000;
    produto_posto[3].preco = 5.94;
    produto_posto[3].cat.identificacao_categoria_pai = 1;
    produto_posto[3].cat.identificacao_categoria = 3;    

    printf("%s", produto_posto[0].nome);
    printf("%s", produto_posto[1].nome);
    printf("%s", produto_posto[2].nome);
    printf("%s", produto_posto[3].nome);

};