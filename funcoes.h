#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<locale.h>
#include<string.h>

struct Endereco{

    char[99] rua;
    char[99] bairro;
    char[99] cidade;
    char[15] cep;
    int num_telefone;
    int id_func;

};

struct Categoria{
    
    int id;
    int idPai;
    char[99] nome;

};
