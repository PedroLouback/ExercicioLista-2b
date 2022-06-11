#ifndef PILHA_HPP
#define PILHA_HPP

#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#define TAM 10

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item{
	char notacao;
};

struct Block{
	Item data;
	Block *prox;
};

struct Pilha{
	Block *base;
	Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
string Converte(int caracter);
bool vazia(Pilha *p);
void PImprime(Pilha *p);
// void inverte(string equacao);
// void TrataParentesses(string equacao);
int Prioridade(char operador);
// void EquacaoPrefixa(string equacao);
void EquacaoPosfixa(string equacao_infixa);


#endif