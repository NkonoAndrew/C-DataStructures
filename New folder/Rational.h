#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
using namespace std;

class Rational
{
	friend ostream & operator<<(ostream & out, const Rational & number);
	friend istream & operator>>(istream & in, Rational & number);


private:
	int numerator, denominator;
	static int gcd(int m, int n);


public:
	static const Rational ZERO;

	int getnumerataor()
	{
	    return numerator;
	}

	int getdenominator()
	{
	    return denominator;
	}


	Rational(int n = 1, int d=1); // constructor

	Rational operator*(const  Rational &n) const;

	//Overloaded operator+
	Rational operator+(const Rational &m) const;

	//Overloaded operator+=
    Rational& operator+=(const  Rational &n);

	Rational& operator*=(const  Rational &n);

	Rational& operator++();

	Rational operator++(int num1);

	bool operator==(const  Rational &n) const;

	bool operator!=(const  Rational &n) const;
};


#endif
