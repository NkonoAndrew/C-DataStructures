#include<iostream>
#include<iostream>
using namespace std;

double roothelp(double x, double min, double max)
{
    double average = (min + max)/2;
    double average2 = average * average;

    if ((average2 - x) >  0.00000001)
    {
        return roothelp(x, min, average);
    }

    else if ((x - average2) > 0.00000001)
    {
        return roothelp(x , average , max);
    }
    return average;
}

double root( double x)
{
    if (x <= 0)
        {
          return 0;
        }
     return roothelp(x, 0, x);
}


double rooot(double x, double min, double max, double n)
{
    double avg = (min + max)/2;
    double pow = avg;

    for (int i= 1; i <= n; i++)
    {
        pow *= avg;
    }

    if (pow > ( x+0.00000001))
    {
        return rooot(x ,min,avg, n);
    }

    else if (pow < ( x-0.00000001))
    {
        return rooot(x ,avg,max, n);
    }
    return avg;
}

double rooter(double x, int temp)
{
    if (x <= 0)
    {
        return 0;
    }
    else if (x < 1)
    {
        return rooot(x, 0, 1, temp);
    }
    return rooot(x, 1,x, temp);
}

int main()
{
    double number;
    int number2;

    cout<< "\n square:";
    cin >>  number;
    cout << root(number);

    cout <<"\n Value: ";
    cin >> number;
    cout << "\n nth root: ";
    cin >> number2;
    cout << "\n" << rooter(number, number2);



}
