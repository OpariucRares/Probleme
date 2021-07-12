#include <iostream>
#include <fstream>
#include <string>

using namespace std;

ifstream fin("ed.in");
ofstream fout("ed.out");

int main()
{
	int poz, lg, n;
	string sir, aux;
	fin >> sir;
	lg = sir.size();
	fin >> n;
	poz = lg;
	for (int i = 0; i < n; i++)
	{
		fin >> aux;
		lg = sir.size();
		switch(aux[0]){
		case 'L':
		{
			if (poz > 0)
				poz--;
			break;
		}
		case 'R':
		{
			if (poz < lg)
				poz++;
			break;
		}
		case 'B':
		{
			if (poz > 0)
			{
				string st, dr;
				st = string(sir, 0, poz - 1);
				sir = string(sir, poz);
				st += sir;
				sir = st;
				break;
			}
		}
		case 'I':
		{
			string sir_nou, st, dr;
			sir_nou = string(aux, 1, aux.size() - 1);
			if (poz == lg)
				sir += sir_nou;
			else
			{
				st = string(sir, 0, poz + 1);
				dr = string(sir, poz);
				st += sir_nou + dr;
				sir = st;
			}
			break;
		}
		case 'D':
		{
			string sir_nou;
			sir_nou = string(aux, 1, aux.size() - 1);
			int nr = 0, p_lungime = sir_nou.size(), p = 1;
			for (int i = p_lungime - 1; i >= 0; i--)
			{
				nr += p * (sir_nou[i] - '0');
				p *= 10;
			}
			if (nr >= lg - poz)
				sir = string(sir, 0, poz);
			else
			{
				string st, dr;
				st = string(sir, 0, poz);
				dr = string(sir, poz + nr + 1);
				st += dr;
				sir = st;
				lg = st.size();
			}
			break;
		}
		}
	}
	fout << sir << '\n';
}