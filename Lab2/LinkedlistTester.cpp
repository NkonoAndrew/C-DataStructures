#include "Linkedlist.h"
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
    Linkedlist<int> list;


    list.insertlast(40);
    list.insertlast(41);
    list.insertlast(42);
    list.insertlast(43);
    list.insertfirst(44);
    list.insertfirst(45);

    list.insertatposition(46,2);
    list.removeatposition(2);
    list.removeatposition(2);

    Linkedlist<int> list1 = list;
    cout <<"\n" << list;
    cout <<"\n" << list1;
    getch();


    cout << "\n There are " << list.getlength() << " Node(s) ";

}
