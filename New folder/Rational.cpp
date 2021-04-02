#include "Rational.h"
#include <iostream>
#include<numeric>
using namespace std;

	// precondition: m is not zero
	int Rational::gcd(int m , int n)
    {
		if (n < 0) n *= -1;
		if (m < 0) m *= -1;
		// now both m and n are positive
		if (n == 0)
			return m;
		return gcd(n,  m % n);
	}


	Rational::Rational(int n, int d)
	 {
		if (d == 0)
			d = 1;
		if (d  < 0) {
			d*=-1;
			n*=-1;
		}
		int g = gcd(n,d);
		n /=g;
		d /=g;
		numerator = n;
		denominator = d;
	}

	Rational Rational::operator*(const Rational &num) const
	 {
		int tempNumerator = this->numerator * num.numerator;
		int tempDenominator = this->denominator * num.denominator;
		return Rational(tempNumerator, tempDenominator);
	}

	Rational Rational::operator+(const Rational &num) const
	{
	    int temp1 = (this->numerator * num.denominator) + (this->denominator * num.numerator);
	    int temp2 = (this->denominator * num.denominator);
	    return Rational(temp1, temp2);
	}

	Rational& Rational::operator+=(const Rational &num)
	{
		return *this = *this + num;
	}

    Rational& Rational::operator++()
	{
	    Rational temp = *this;
	    Rational tempnum;
	    tempnum = Rational (1,1);
	    *this = *this + tempnum;
	    return temp;
	}

	Rational Rational:: operator++(int num1)
	{
	    Rational tempnum = *this;
	    ++(*this);
	    return tempnum;
	}



	Rational& Rational::operator*=(const  Rational &num)
	{
		return *this = *this * num;
	}

	bool Rational::operator==(const  Rational &num) const {
		return this->numerator == num.numerator
			&& this->denominator == num.denominator;
	}

	bool Rational::operator!=(const  Rational &num) const {
		return !(*this == num);
	}
	const Rational Rational::ZERO(0,1);


	ostream & operator<<(ostream & out, const Rational & number) {
		out << number.numerator << "/" << number.denominator;
		return out;
	}
	istream & operator>>(istream & in, Rational & number) {
		char slash;
		int n, d;
		in >> n >> slash >> d;
		Rational temp(n,d);
		number = temp;
		return in;

	}
