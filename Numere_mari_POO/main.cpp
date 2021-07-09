#include <iostream>
#include "BigInt.h"
using namespace std;

int main()
{
	BigInt n_int(12345), n_char("192647914617246"), n_gol;
	cout << "Lungimea numarului: ";
	cout << n_char.GetLg() << '\n';
	cout << "Constructorii: \n";
	n_gol.Print();
	n_int.Print();
	n_char.Print();
	cout << "Operatorul de atribuire: \n";
	n_gol = n_int;
	n_gol.Print();
	n_int = n_int;
	n_int.Print();
	cout << "Operatorii ++ pre si post-fixata: \n";
	BigInt n_9999("9999");
	(++n_9999).Print();
	(++n_int).Print();
	n_gol = n_int++;
	n_gol.Print();
	n_int.Print();
	n_gol = ++n_9999;
	n_gol.Print();
	cout << "Operatorul -- pre si post-fixata: \n";
	BigInt n_1000("1000");
	(--n_1000).Print();
	n_gol = n_1000--;
	n_gol.Print();
	n_1000.Print();
	n_gol = --n_1000;
	n_gol.Print();
	cout << "Operatorii de egalitate: \n";
	if (n_gol == n_gol)
		cout << "TRUE\n";
	else
		cout << "FALSE\n";
	if (n_gol == n_char)
		cout << "TRUE\n";
	else
		cout << "FALSE\n";
	if (n_gol != n_char)
		cout << "TRUE\n";
	else
		cout << "FALSE\n";
	cout << "Operatorii relationali: \n";
	cout << boolalpha << (n_char < n_gol) << '\n';
	cout << boolalpha << (n_gol <= n_gol) << '\n';
	cout << boolalpha << (n_char > n_gol) << '\n';
	cout << boolalpha << (n_gol >= n_gol) << '\n';
	n_gol = "45";
	n_int = 54;
	BigInt n_temp("123");
	n_temp += n_int;
	cout << "Operatori relationali aditivi:\n";
	cout << "Suma este: "; 
	(n_gol + n_int).Print();
	cout << "Suma este: ";
	n_temp.Print();
	BigInt n;
	cin >> n;
	cout << n;
	return 0;
}