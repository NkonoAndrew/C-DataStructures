#include <conio.h>
#include <iomanip>
#include <iostream>
#include<stdlib.h>
#include<fstream>
#include <string.h>
#include <cstring>
#include<limits>
using namespace std;


class StudentInfo
{

private:

    string country;
    string city;

public:

    StudentInfo()
    {
        city = " ";
        country = " ";
    }

        string getcity()
        {
            return city;
        }

        string getcountry()
        {
            return country;
        }

        //setters
        void setcity(string city)
        {
            this->city = city;
        }

        void setcountry(string country)
        {
            this->country = country;
        }



        void setAll(string country, string city)
        {
            setcity(city);
            setcountry(country);
        }

        void displayStudent()
        {
            cout << "\n\n City:" << city;
                 << "\n First Country: " << country;
        }

};

void readFile(StudentInfo students[]);


int main()
{
    const int max_students = 1000;
    StudentInfo students[max_students];
}

void readFile(StudentInfo students[])

{
        string country;
        string city;



        // Record counter

    ifstream inFile("Students.dat", ios::in|ios::binary);
      system("cls");

    if (!inFile)
        {
            cout << "\nSorry, the data file \"personnel.dat\" was not found on this drive";
            cout << "\n\nHit Any Key to continue";
            getch();
            system("cls");
        }
        inFile >> city >> country;

        while(!inFile.eof())
        {
            students[count].setAll(city,country)

        count++;
        inFile >> id2 >> firstname2 >> lastname2 >> gpa2 >> classes2;

        }
        inFile.close();
}
