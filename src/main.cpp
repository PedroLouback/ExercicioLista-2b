#include "pilha.hpp"

int main()
{
	string equacao_infixa;

	cout << "Informe a equação que deseja ser feita utilizando espaços entre operandos e operadores: ";
	getline(cin, equacao_infixa);

	EquacaoPosfixa(equacao_infixa);

	return 0;
}
