#ifndef PILHA_HPP
#define PILHA_HPP

#include <stdbool.h>
#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

typedef struct Item Item;
typedef struct Block Block;
typedef struct Pilha Pilha;

struct Item
{
	char notacao;
};

struct Block
{
	Item data;
	Block *prox;
};

struct Pilha
{
	Block *base;
	Block *top;
};

void FPVazia(Pilha *p);
void Push(Pilha *p, Item d);
void Pop(Pilha *p, Item *d);
string Converte(int caracter);
bool vazia(Pilha *p);
void PImprime(Pilha *p);
int Prioridade(char operador);
string EquacaoPosfixa(string equacao_infixa);
string inverte(string equacao_infixa);
string EquacaoPrefixa(string equacao_infixa);

#endif