#include "BigInt.h"
#include <cstring>
#include <iostream>

void zero(int* &v, int lg_vechi, int lg_nou)
{
	int* copie;
	copie = new int[2 * lg_nou];
	for (int i = 0; i < 2 * lg_nou; i++)
		copie[i] = 0;
	for (int i = 0; i < lg_vechi; i++)
		copie[i] = v[i];
	delete v;
	v = new int[2 * lg_nou];
	for (int i = 0; i < 2 * lg_nou; i++)
		v[i] = copie[i];
	delete copie;
}

BigInt::BigInt(int x)
{

	if (x == 0)
	{
		LGMAX = 1;
		v = new int[LGMAX];
		v[0] = 0;
	}
	else
	{
		int copie = x;
		while (copie)
		{
			LGMAX++;
			copie /= 10;
		}
		v = new int[LGMAX];
		for (int i = 0; i < LGMAX; i++)
		{
			v[i] = x % 10;
			x /= 10;
		}
	}
}
BigInt::BigInt(const char* sir)
{
	LGMAX = strlen(sir);
	v = new int[LGMAX];
	for (int st = 0, dr = LGMAX - 1; dr >= 0; st++, dr--)
		v[st] = sir[dr] - '0';
}
BigInt::BigInt(const BigInt& obj)
{
	LGMAX = obj.LGMAX;
	v = new int[LGMAX];
	for (int i = 0; i < LGMAX; i++)
		v[i] = obj.v[i];
}
void BigInt::Print()
{
	for (int i = LGMAX - 1; i >= 0; i--)
		std::cout << v[i];
	std::cout << '\n';
}
BigInt& BigInt::operator=(const BigInt& obj)
{
	//ob = ob1;
	if (this == &obj)
		return *this;
	LGMAX = obj.LGMAX;
	if (v)
		delete v;
	v = new int[LGMAX];
	for (int i = 0; i < LGMAX; i++)
		v[i] = obj.v[i];
	return *this;
}
int BigInt::operator[](int poz) const
{
	return v[poz];
}
BigInt& BigInt::operator++()//postfixaa
{
	int t = 0, i = 0;
	v[i]++;
	if (v[i] == 10)
	{
		v[i++] = 0;
		t = 1;
		while (t && i < LGMAX)
		{
			v[i]++;
			t = 0;
			if (v[i] == 10)
			{
				v[i] = 0;
				t = 1;
			}
			i++;
		}
		if (i == LGMAX && t == 1)
			v[LGMAX++] = 1;
	}
	return *this;
}
BigInt BigInt::operator++(int fictiv)
{
	BigInt temp;
	temp = *this;
	++(*this);
	return temp;
}
BigInt& BigInt::operator--()
{
	int t = 0, i = 0;
	if (v[i] == 0)
	{
		v[i++] = 9;
		t = 1;
		while (t && i < LGMAX)
		{
			if (v[i] == 0)
			{
				v[i++] = 9;
				t = 1;
			}
			else
			{
				v[i]--;
				t = 0;
			}
		}
		if (v[LGMAX - 1] == 0)
		{
			for (i = LGMAX - 1; i > 0; i--)
				v[i] = v[i - 1];
			LGMAX--;
		}
	}
	else
		v[i]--;
	return *this;
}
BigInt BigInt::operator--(int fictiv)
{
	BigInt temp;
	temp = *this;
	--(*this);
	return temp;

}
bool operator==(const BigInt& obj1, const BigInt& obj2)
{
	if (obj1.LGMAX != obj2.LGMAX)
		return false;
	for (int i = 0; i < obj1.LGMAX; i++)
	{
		if (obj1.v[i] != obj2.v[i])
			return false;
	}
	return true;
}
bool operator!=(const BigInt& obj1, const BigInt& obj2)
{
	return !(obj1 == obj2);
}
bool operator>(const BigInt& obj1, const BigInt& obj2)
{
	if (obj1.LGMAX > obj2.LGMAX)
		return true;
	else
		return false;
	for (int i = obj1.LGMAX - 1; i >= 0; i--)
	{
		if (obj1.v[i] <= obj2.v[i])
			return false;
	}
	return true;
}
bool operator<(const BigInt& obj1, const BigInt& obj2)
{
	if (obj1.LGMAX < obj2.LGMAX)
		return true;
	else
		return false;
	for (int i = obj1.LGMAX - 1; i >= 0; i--)
	{
		if (obj1.v[i] >= obj2.v[i])
			return false;
	}
	return true;
}
bool operator>=(const BigInt& obj1, const BigInt& obj2)
{
	return !(obj1 < obj2);
}
bool operator<=(const BigInt& obj1, const BigInt& obj2)
{
	return !(obj1 > obj2);
}
BigInt operator+(BigInt& obj1, BigInt& obj2)
{
	BigInt temp;
	temp = obj1;
	temp += obj2;
	return temp;
}
BigInt& operator+=(BigInt& obj1, BigInt& obj2)
{
	int lg;
	if (obj1.LGMAX != obj2.LGMAX)
	{
		if (obj1.LGMAX > obj2.LGMAX)
			zero(obj2.v, obj2.LGMAX, obj1.LGMAX);
		else
			zero(obj1.v, obj1.LGMAX, obj2.LGMAX);
	}
	int t = 0;
	obj1.LGMAX = std::max(obj1.LGMAX, obj2.LGMAX);
	for (int i = 0; i < obj1.LGMAX; i++)
	{
		obj1.v[i] = obj1.v[i] + obj2.v[i] + t;
		if (obj1.v[i] > 9)
		{
			obj1.v[i] %= 10;
			t = 1;
		}
	}
	if (t == 1)
		obj1.v[obj1.LGMAX++] = 1;
	return obj1;
}
std::istream& operator>>(std::istream& in, BigInt& obj)
{
	char m[1001];
	in >> m;
	obj.LGMAX = strlen(m);
	for (int i = 0; i < obj.LGMAX; i++)
		obj.v[obj.LGMAX - 1 - i] = m[i] - '0';
	return in;
}
std::ostream& operator<<(std::ostream& out, const BigInt& obj)
{
	for (int i = obj.LGMAX - 1; i >= 0; i--)
		out << obj.v[i];
	return out;
}