#include"header_structs.h"

void incializacao_estoque(){

    int variedade_pl = 10;
    int variedade_pp = 4; 

    Produtos *produto_posto;
    Produtos *produto_loja;

    produto_loja = (Produtos *)malloc(variedade_pl * sizeof(Produtos));
    produto_posto = (Produtos *)malloc(variedade_pp * sizeof(Produtos));

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

    strcpy(produto_loja[3].nome, "Coca-cola");
    produto_loja[3].identificacao_produto = 2121;
    produto_loja[3].quantidade = 50;
    produto_loja[3].preco = 3.50;
    produto_loja[3].cat.identificacao_categoria_pai = 1;
    produto_loja[3].cat.identificacao_categoria = 2;
    strcpy(produto_loja[3].cat.nome_categoria,"Bebidas");

    strcpy(produto_loja[4].nome, "Skol");
    produto_loja[4].identificacao_produto = 2122;
    produto_loja[4].quantidade = 50;
    produto_loja[4].preco = 3.50;
    produto_loja[4].cat.identificacao_categoria_pai = 1;
    produto_loja[4].cat.identificacao_categoria = 2;
    strcpy(produto_loja[4].cat.nome_categoria,"Bebidas");

    strcpy(produto_loja[5].nome, "");
    produto_loja[5].identificacao_produto = ;
    produto_loja[5].quantidade = ;
    produto_loja[5].preco = ;
    produto_loja[5].cat.identificacao_categoria_pai = ;
    produto_loja[5].cat.identificacao_categoria = ;
    strcpy(produto_loja[5].cat.nome_categoria,"");

    strcpy(produto_loja[6].nome, "");
    produto_loja[6].identificacao_produto = ;
    produto_loja[6].quantidade = ;
    produto_loja[6].preco = ;
    produto_loja[6].cat.identificacao_categoria_pai = ;
    produto_loja[6].cat.identificacao_categoria = ;
    strcpy(produto_loja[6].cat.nome_categoria,"");

    strcpy(produto_loja[7].nome, "");
    produto_loja[7].identificacao_produto = ;
    produto_loja[7].quantidade = ;
    produto_loja[7].preco = ;
    produto_loja[7].cat.identificacao_categoria_pai = ;
    produto_loja[7].cat.identificacao_categoria = ;
    strcpy(produto_loja[7].cat.nome_categoria,"");

    strcpy(produto_loja[8].nome, "");
    produto_loja[8].identificacao_produto = ;
    produto_loja[8].quantidade = ;
    produto_loja[8].preco = ;
    produto_loja[8].cat.identificacao_categoria_pai = ;
    produto_loja[8].cat.identificacao_categoria = ;
    strcpy(produto_loja[8].cat.nome_categoria,"");

    strcpy(produto_loja[9].nome, "");
    produto_loja[9].identificacao_produto = ;
    produto_loja[9].quantidade = ;
    produto_loja[9].preco = ;
    produto_loja[9].cat.identificacao_categoria_pai = ;
    produto_loja[9].cat.identificacao_categoria = ;
    strcpy(produto_loja[9].cat.nome_categoria,"");

    /*printf("%s\n", produto_posto[0].nome);
    printf("%s\n", produto_posto[1].nome);
    printf("%s\n", produto_posto[2].nome);
    printf("%s\n", produto_posto[3].nome);
    printf("%s\n", produto_loja[0].nome);
    printf("%s\n", produto_loja[1].nome);*/

};