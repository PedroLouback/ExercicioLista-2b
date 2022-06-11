#include "pilha.hpp"

int main()
{
	string equacao_infixa;

	cout << "\nInforme a equação que deseja visualizar sua notação posfixa e prefixa: ";
	getline(cin, equacao_infixa);

	cout << "\nA equação '" << equacao_infixa << "' em notação posfixa é: " << EquacaoPosfixa(equacao_infixa) << endl;
	cout << "\nA equação '" << equacao_infixa << "' em notação prefixa é: " << EquacaoPrefixa(equacao_infixa) << endl;
	cout << "\n";

	return 0;
}
