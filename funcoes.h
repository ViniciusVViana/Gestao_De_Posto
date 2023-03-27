#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<string.h>

typedef struct Categorias Categorias;
typedef struct Endereco Endereco;
typedef struct Produtos Produtos;

struct Endereco{

    char rua[99];
    char bairro[99];
    char cidade[99];
    char cep[15];
    int num_telefone;
    int id_func;

};

struct Categorias{
    
    int id;
    int idPai;
    char nome[99];

};

struct Produtos{

    int id;
    Categorias cat;
    char nome[99];
    int quantidade;
    float preco;
    int entrada;
    int validade;

};

struct Funcionarios{

    int login;
    int senha;
    char nome;
    float salario;
    Endereco endereco;
    char cpf;
    int telefone;

};