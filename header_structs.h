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
    
    int identificacao_categoria;
    int identificacao_categoria_pai;
    char nome[99];

};

struct Produtos{

    int identificacao_produto;
    Categorias cat;
    char nome[99];
    int quantidade;
    float preco;
    int entrada;
    int validade;

};

struct Funcionarios{

    char login;
    int senha;
    char nome;
    float salario;
    Endereco endereco;
    char cpf;
    int telefone;

};