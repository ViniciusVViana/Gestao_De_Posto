#ifndef header_structs_h
#define header_structs_h

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#endif

#include<assert.h>
#include<windows.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<string.h>

//DEFINIÇÃO DOS TIPOS DAS ESTRUTURAS.

typedef struct Categorias Categorias;
typedef struct Endereco Endereco;
typedef struct Produtos Produtos;
typedef struct Funcionarios Funcionarios;
typedef struct Vendas Vendas;
//CRIAÇÃO DAS STRUCTS DO PROGRAMA.
Produtos *produto_posto;
Funcionarios *funcionarios_cadastrado;

struct Endereco{

    char rua[99];
    char bairro[99];
    char cidade[99];
    char cep[15];
    int num;
    /* int identificacao_func; */

};

int size_stock = 15;

struct Categorias{

    char nome_categoria[99];
    int identificacao_categoria;
    int identificacao_categoria_pai;

};

struct Produtos{

    int identificacao_produto;
    Categorias cat;
    char nome[99];
    int quantidade;
    float preco;

};

int size_funcionario = 5;

struct Funcionarios{

    int identificacao_func;
    char login[99];
    int senha;
    char nome[99];
    float salario;
    Endereco endereco;
    char cpf[15];
    long int telefone;

};

struct Vendas{
    Produtos *produto;
    float valor_total;
    float valor_pago;
    int forma_pagamento;
    int id_func;
    float troco;

};
#endif
