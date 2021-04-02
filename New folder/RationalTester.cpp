#include "Rational.h"
#include "Rational.cpp"
#include <iostream>
using namespace std;

int main()
{
	for (int i = 0; i < 10; i++)
    {
		cout << "Enter two integers: ";
		int a, b;
		cin >> a >> b;
		Rational num(a,b);
		cout << "\n First Rational number is:" << num ;

		cout << "\n Enter another rational number (two integers separated by /) : ";
		Rational r;

		cin >> r;
		cout << "\n Second Rational Number: " << r;

		cout << "\n Multiplication:" << (r*num);
		cout << "\n Adding:" << (r+num);

		cout << "\n Post increment:" << r++;

		//cout << " The new value of r is " << r << endl;

		cout << "\n\n r == r  evaluates to " << (r == r) << endl;
		cout << "r != r  evaluates to " << (r != r) << endl;
		cout << "r == num  evaluates to " << (r == num) << endl;
		cout << "r != num  evaluates to " << (r != num) << endl;
		cout << Rational::ZERO << endl;
	}
	return 0;
}
