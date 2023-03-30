#include"header_structs.h"

void incializacao_estoque(){

    

    Produtos *produto_posto;
    Produtos *produto_loja;

    produto_loja = (Produtos *)malloc(3 * sizeof(Produtos));
    produto_posto = (Produtos *)malloc(4 * sizeof(Produtos));

    strcpy(produto_posto[0].nome,"Gasolina comum");
    produto_posto[0].identificacao_produto = 1111;
    produto_posto[0].quantidade = 1000;
    produto_posto[0].preco = 5.51;
    produto_posto[0].cat.identificacao_categoria_pai = 1;
    produto_posto[0].cat.identificacao_categoria = 1;
    strcpy(produto_posto[0].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[1].nome,"Gasolina aditivada");
    produto_posto[1].identificacao_produto = 1112;
    produto_posto[1].quantidade = 1000;
    produto_posto[1].preco = 5.51;
    produto_posto[1].cat.identificacao_categoria_pai = 1;
    produto_posto[1].cat.identificacao_categoria = 1;
    strcpy(produto_posto[1].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[2].nome,"Etanol");
    produto_posto[2].identificacao_produto = 1120;
    produto_posto[2].quantidade = 1000;
    produto_posto[2].preco = 4,87;
    produto_posto[2].cat.identificacao_categoria_pai = 1;
    produto_posto[2].cat.identificacao_categoria = 2;
    strcpy(produto_posto[2].cat.nome_categoria,"Combustivel");

    strcpy(produto_posto[3].nome,"Diesel");
    produto_posto[3].identificacao_produto = 1130;
    produto_posto[3].quantidade = 1000;
    produto_posto[3].preco = 5.94;
    produto_posto[3].cat.identificacao_categoria_pai = 1;
    produto_posto[3].cat.identificacao_categoria = 3;
    strcpy(produto_posto[3].cat.nome_categoria,"Combustivel");

    strcpy(produto_loja[0].nome, "Doritos");
    produto_loja[0].identificacao_produto = 2111;
    produto_loja[0].quantidade = 50;
    produto_loja[0].preco = 9.99;
    produto_loja[0].cat.identificacao_categoria_pai = 1;
    produto_loja[0].cat.identificacao_categoria = 1;
    strcpy(produto_loja[0].cat.nome_categoria,"Alimentos");

    strcpy(produto_loja[1].nome, "Baconzitos");
    produto_loja[1].identificacao_produto = 2112;
    produto_loja[1].quantidade = 50;
    produto_loja[1].preco = 9.99;
    produto_loja[1].cat.identificacao_categoria_pai = 1;
    produto_loja[1].cat.identificacao_categoria = 1;
    strcpy(produto_loja[1].cat.nome_categoria,"Alimentos");

    strcpy(produto_loja[2].nome, "Cebolitos");
    produto_loja[2].identificacao_produto = 2113;
    produto_loja[2].quantidade = 50;
    produto_loja[2].preco = 9.99;
    produto_loja[2].cat.identificacao_categoria_pai = 1;
    produto_loja[2].cat.identificacao_categoria = 1;
    strcpy(produto_loja[2].cat.nome_categoria,"Alimentos");

    /* printf("%s\n", produto_posto[0].nome);
    printf("%s\n", produto_posto[1].nome);
    printf("%s\n", produto_posto[2].nome);
    printf("%s\n", produto_posto[3].nome);
    printf("%s\n", produto_loja[0].nome);
    printf("%s\n", produto_loja[1].nome); *\

};