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

	aux = p->top;
	while(aux != p->base){
		cout << aux->data.notacao;
		aux = aux->prox;
	}

}

bool vazia(Pilha *p)
{
	return (p->top->prox == NULL);
}

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
		return 0;
}

//Construção Posfixa

string EquacaoPosfixa(string equacao_infixa)
{
	equacao_infixa = '(' + equacao_infixa + ')'; 
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
			while (!vazia(&Posfixa) && (Prioridade(caractere_equacao) < Prioridade(Posfixa.top->data.notacao)))
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

	return equacao_posfixa;

}

//Construção Prefixa

void EquacaoPrefixa(string equacao_infixa)
{
	char caractere_equacao;
	string equacao_prefixa;

	reverse(equacao_infixa.begin(), equacao_infixa.end());
	
	for (size_t i = 0; i < equacao_infixa.size(); i++){
		caractere_equacao = equacao_infixa[i];

		if(caractere_equacao == '('){
			caractere_equacao = ')';
			i++;
		}else if (caractere_equacao == ')'){
			caractere_equacao = '(';
			i++;
		}
	}

	equacao_prefixa = EquacaoPosfixa(equacao_infixa);

	reverse(equacao_prefixa.begin(), equacao_prefixa.end());

	cout << "\nA equação '" << equacao_infixa << "' em notação prefixa é: " << equacao_prefixa << endl;
	cout << "\n";

}
