#pragma once
#include <iostream>

class BigInt
{
private:
	int LGMAX = 0;
	int* v; //incepem cu initatile
public:
	BigInt(int x = 0);
	BigInt(const char*);
	BigInt(const BigInt&);
	int GetLg()
	{
		return LGMAX;
	}
	void Print();
	BigInt& operator=(const BigInt&);
	int operator[](int) const;
	BigInt& operator++();
	BigInt operator++(int fictiv);
	BigInt& operator--();
	BigInt operator--(int fictiv);
	friend bool operator==(const BigInt&, const BigInt&);
	friend bool operator!=(const BigInt&, const BigInt&);

	friend bool operator>(const BigInt&, const BigInt&);
	friend bool operator<(const BigInt&, const BigInt&);

	friend bool operator>=(const BigInt&, const BigInt&);
	friend bool operator<=(const BigInt&, const BigInt&);

	//friend BigInt operator+(const BigInt& obj1, const BigInt& obj2);
	//friend BigInt& operator+=(BigInt& obj1, const BigInt& obj2);
	//asa ii normal, dar din cauza ca modific numarul ca sa pun 0, nu mai pot pune const
	friend BigInt operator+(BigInt& obj1, BigInt& obj2);
	friend BigInt& operator+=(BigInt& obj1, BigInt& obj2);
	friend std::istream& operator>>(std::istream&, BigInt&);
	friend std::ostream& operator<<(std::ostream&, const BigInt&);
};

