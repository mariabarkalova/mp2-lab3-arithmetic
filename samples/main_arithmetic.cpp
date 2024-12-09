// реализация пользовательского приложения
#include <iostream>
#include "stack.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Parser a;
	//string s;
	//cout << "Выражение обязательно должно быть в скобках "<<endl;
	//string s = "(3+5*2)";
	string s = "(a+b/a)";
	//cin >> s;
	cout << s<<endl;
	a.MassivLexem(s);
	a.Parser_Postfix();
	cout << "Postfix zapis: ";
	a.printPostfix();
	cout << "Znachenie vurazenia: " << a.Arifmetic();
	return 0 ;
}
