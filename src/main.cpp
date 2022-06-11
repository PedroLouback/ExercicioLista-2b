#include "pilha.hpp"

int main()
{
	string equacao_infixa;

	cout << "Informe a equação que deseja ser feita utilizando espaços entre operandos e operadores: ";
	getline(cin, equacao_infixa);

	cout << "\nA equação '" << equacao_infixa << "' em notação posfixa é: " << EquacaoPosfixa(equacao_infixa) << endl;
	cout << "\nA equação '" << equacao_infixa << "' em notação prefixa é: " << EquacaoPrefixa(equacao_infixa) << endl;
	cout << "\n";

	return 0;
}
