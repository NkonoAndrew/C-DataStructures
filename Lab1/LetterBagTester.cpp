#include "LetterBag.h"
#include "LetterBag.cpp"
#include <stdlib.h>

int main()
{
    char again = 'y';
    char add, other;

    while (again == 'y')
    {

        cout << "\n Enter a string:";
        string a;
        cin >> a;
        LetterBag bag(a);


        cout << "\n The string is:" << bag.toString()
             << "\n The string's size is:" << bag.getCurrentSize();
        cout << "\n Character to find:";
        cin >> other;

        cout << "\n The frequency of the recurrence of character\'" << other << "\':" << bag.getFrequency(other);

        cout << "\n Enter a char to add:";
        cin >> add;

        LetterBag one  = bag += add;

        cout << "\n\n String with a character\'" << add << "\'added: " << one.toString();

    cout << "\n Run again: Yes(y) No(n):";
    cin >> again;
    again = tolower(again);
    system("cls");

    }


}
