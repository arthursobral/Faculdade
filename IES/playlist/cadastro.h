#ifndef CADASTRO_H
#define CADASTRO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>

#include "data.h"

typedef struct {
    char* HashTag;
    char* nome;
    char* sobrenome;
    char* email;
    char* senha;
    char* senha2;
    Data nascimento;
    char* numero;
} Cadastro;

Cadastro* inicializa();
void cadastro_save(Cadastro *login);

#endif
