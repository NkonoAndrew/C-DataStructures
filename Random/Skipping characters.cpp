#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

// pretend file stream
istringstream data(R"(
From:  Seoul, South Korea
To  :  Toronto, Canada
       Luxembourg, Luxembourg
       Seattle, United States
       Dhaka, Bangladesh
       Guatemala City, Guatemala
)");

int main()
{

    double theta;
    double phi;
    std::string skip; // used to read past unwanted text

    // set printing format to 4 decimal places

    while( getline(data, skip, ':')
        && data >> theta
        && getline(data, skip, ':')
        && data >> phi
    )
    {
        cout << "\n " << theta << " " << phi;
    }
}
