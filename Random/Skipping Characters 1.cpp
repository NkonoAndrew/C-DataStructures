#include <iostream>
#include <algorithm>
#include <fstream>
#include <cstdlib>
#include <string>
#include <map>
int main ()
{
int b = 0;
map cities;
string arr[2500]; // setting the max no. of city in file = 100

string line; // opening the file in reading mode

ifstream myfile ("connections.txt");

int pos = 0; // for indexing in our string array

if (myfile.is_open()) // if file gets open
{

while ( getline (myfile,line) ) // getting line by line data
{
string temp=""; // to store string temporarily

for(int i=0; i<=line.length(); i++) // traversing till end of string

{

if(i==line.length()) // As last character can be '\n'

{

if(temp.size()>=1) // if there is any string in temp
{
arr[pos++] = temp;
temp="";
continue;
}

}

if(line[i]==' ')
continue; // if space then continue

if(isalpha(line[i]))
temp+=line[i]; // if it is alphabet then add to temp


if(line[i]==':')
temp=""; // if it is ':', then initialize the temp string again

if(line[i]==',') // if it is ',' , then store it to the array

{
temp += line[i];
temp += line[i+1];

}

}
//if (!isDuplicate(arr, temp, b))
//{
cities.insert(pair (b, temp) );
arr[pos++] = temp;
temp ="";
b++;
//}
//else
//{
//temp ="";
// }
//temp ="";


}

myfile.close(); // closing the file
map :: iterator i;
int p = 0;
for (i = cities.begin(); i != cities.end();++i)
{
if (p%5 == 0)
{
getch();
}
p++;
cout << '\t' << i->first;
cout << '\t' << i->second << '\n';
}
//for(int i=0; i //{

//cout< //}

}

else // if file doesn't get open

cout << "Unable to open file";

return 0;
