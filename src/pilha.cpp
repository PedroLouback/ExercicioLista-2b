#include "pilha.hpp"

void FPVazia(Pilha *p)
{
	p->base = new Block;
	p->top = p->base;
	p->base->prox = NULL;
}

void Push(Pilha *p, Item d)
{
	Block *aux = new Block;
	aux->data = d;
	aux->prox = p->top;
	p->top = aux;
}

void Pop(Pilha *p, Item *d)
{
	Block *aux;

	if (p->base == p->top || p == NULL)
	{
		cout << "LISTA VAZIA!\n";
		return;
	}

	aux = p->top;
	p->top = aux->prox;
	*d = aux->data;
	free(aux);
}

string Converte(int caracter)
{
	string num_convertido;

	num_convertido = caracter;

	return num_convertido;
}

void PImprime(Pilha *p)
{
	Block *aux;
	int i = 0;
	aux = p->top;
	while (aux != p->base)
	{
		for (i = 0; i < TAM; i++)
		{
			if (aux->data.notacao == 0)
			{
				break;
			}
			cout << Converte(aux->data.notacao);
		}
		cout << "\n";
		aux = aux->prox;
	}
}

bool vazia(Pilha *p)
{
	return (p->top->prox == NULL);
}

// void inverte(string equacao)
// {

// 	int i = 0, j = 0;
// 	int tam = strlen(equacao);
// 	char prefixa[tam];

// 	j = strlen(equacao);
// 	prefixa[j--] = '\0';
// 	while (equacao[i] != '\0')
// 	{
// 		prefixa[j] = equacao[i];
// 		j--;
// 		i++;
// 	}
// 	strcpy (equacao, prefixa);
// }

// void TrataParentesses(string equacao)
// {
// 	int i = 0;
// 	while (equacao[i] != '\0')
// 	{
// 		if (equacao[i] == '(')
// 		{
// 			equacao[i] = ')';
// 		}
// 		else if (equacao[i] == ')')
// 		{
// 			equacao[i] = '(';
// 		}
// 		i++;
// 	}
// }

int Prioridade(char caractere)
{
	if (caractere == '/' || caractere == '*')
	{
		return 2;
	}
	else if (caractere == '+' || caractere == '-')
	{
		return 1;
	}
	else
		return -1;
}

// void EquacaoPrefixa(string equacao)
// {
// 	inverte(equacao);
// 	TrataParentesses(equacao);
// 	EquacaoPosfixa(equacao);
// 	inverte(equacao);
// }

void EquacaoPosfixa(string equacao_infixa)
{
	Pilha Posfixa;
	FPVazia(&Posfixa);
	Item aux;
	string equacao_posfixa;
	char caractere_equacao;

	for (size_t i = 0; i < equacao_infixa.size(); i++)
	{
		caractere_equacao = equacao_infixa[i];
		
		if ((caractere_equacao >= 48 && caractere_equacao <= 57))
		{
			equacao_posfixa += caractere_equacao;
		}
		else if (caractere_equacao == '(')
		{
			aux.notacao = '(';
			Push(&Posfixa, aux);
		}
		else if (caractere_equacao == ')')
		{
			while (Posfixa.top->data.notacao != '(')
			{
				equacao_posfixa += Posfixa.top->data.notacao;
				Pop(&Posfixa, &aux);
			}
			Pop(&Posfixa, &aux);
		}
		else
		{
			while (!vazia(&Posfixa) && (Prioridade(equacao_infixa[i]) <= Prioridade(Posfixa.top->data.notacao)))
			{
				equacao_posfixa += Posfixa.top->data.notacao;
				Pop(&Posfixa, &aux);
			}
			aux.notacao = caractere_equacao;
			Push(&Posfixa, aux);
		}
	}

	while (!vazia(&Posfixa))
	{
		equacao_posfixa += Posfixa.top->data.notacao;
		Pop(&Posfixa, &aux);
	}

	cout << "\nA equação '" << equacao_infixa << "' em notação posfixa é: " << equacao_posfixa << "\n";	

}
