#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

unsigned int hash1( string n, int size)
{
    int m = 0;
    for (int  i = 0; i < n.length()-3; i++)
    {
        m *= 26;
        m += (n[i]-'a');

    }

    for (int  i = n.length()-3; i < n.length(); i++)
    {
        m *= 10;
        m += (n[i]-'0');

    }
    return m%size;

}

int main()
{

    auto start = high_resolution_clock::now();

    cout << hash1("zzzz999",456976000);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "\n Programme takes " << duration.count() << " microseconds";


}
