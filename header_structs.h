#ifndef header_structs_h
#define header_structs_h

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<string.h>

//DEFINIÇÃO DOS TIPOS DAS ESTRUTURAS.

//  struct Categorias categorias;
//  struct Endereco endereco;
typedef struct Produtos Produtos;
typedef struct Funcionarios Funcionarios;

//CRIAÇÃO DAS STRUCTS DO PROGRAMA.

struct Endereco{

    char rua[99];
    char bairro[99];
    char cidade[99];
    char cep[15];
    int num_telefone;
    int identificacao_func;

};

struct Categorias{
    
    char nome_categoria[99];
    int identificacao_categoria;
    int identificacao_categoria_pai;    

};

struct Produtos{

    int identificacao_produto;
    struct Categorias cat;
    char nome[99];
    float quantidade;
    float preco;

};

struct Funcionarios{

    int identificacao_func;
    char login[99];
    int senha;
    char nome;
    float salario;
    struct Endereco endereco;
    char cpf;
    int telefone;

};

#endif