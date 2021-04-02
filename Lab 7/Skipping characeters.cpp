#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
struct Info
{
    string city;
    string country;
};

int main()
{
    ifstream infile;
    struct Info data[100];
    string cityName,Countryname,key;

    infile.open("connections.txt");
    int i=0,length=0;

    //infile>>cityName>>Countryname;


    while (!infile.eof())
    {
    infile>>cityName>>Countryname;
    std::replace(cityName.begin(), cityName.end(), ',', ' ');//To Remove Commas from the CityName
    data[i].city=cityName;
    data[i].country=Countryname;
    i++;
    length++;
}
    cout<<"\nThe List country and City"<<endl;

    for(int i=0;i<length;i++)
    {
        cout<<data[i].city<<"\t"<<data[i].country<<endl;
    }

    bool status=false;
    label:

    cout<<"\nPlease Enter a CityName: "<<endl;
    cin>>key;

    for(int i=0;i<length;i++)
    {
        string name=data[i].city;
        if(name.find(key, 0)!= std::string::npos);
    {

    cout<<data[i].city<< endl;
    status=true;

    }
}

    if(status==false)
    {
        cout<<"\nTry Again with Different CityName"<<endl;
        goto label;
    }

    cout<<"\nThanks"<<endl;
    return 0;

}
