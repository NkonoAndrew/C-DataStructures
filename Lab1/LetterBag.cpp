#include "Letterbag.h"
#include <iostream>
using namespace std;

ostream & operator<< (ostream & out, const LetterBag & let)
{
    out << let.toString();
    return out;
}

istream & operator>> (istream & in, LetterBag & let)
{
    string s;
    getline(in, s);
    for (int i = 0; i < s.size(); i++)
    {
        let+=s.at(i);
    }
    return in;
}

LetterBag::LetterBag()
{
    current = 0;
}

LetterBag::LetterBag(const string &s)
{
    current = 0;
    for (int i = 0;i < s.size();i++)
    {
        char c = s.at(i);
        if  (isalpha(c))
        {
            c = tolower(c);
            letters[(int)(c-'a')]+=1;
            current++;
        }
    }
}

int LetterBag::getCurrentSize() const
{
    return current;
}

LetterBag LetterBag::operator+(char ch) const
{
    string s = toString();
    s.push_back(ch);
    LetterBag l(s);
    return l;
}

LetterBag& LetterBag::operator+=(char c) {
        if(isalpha(c)) {
                c = tolower(c);
                letters[(int)(c - 'a')] += 1;
                current++;
        }
        return *this;
}

// remove all occurence occurrence of ch from the current object.
// if ch is out of range or has count equal to zero do nothing.
void LetterBag::removeAll(char c) {
        if(isalpha(c)) {
                c = tolower(c);
                current -= letters[(int)(c - 'a')];
                letters[(int)(c - 'a')] = 0;
        }
}

// remove all occurrences of all letters.
void LetterBag::clear() {
        for(int i=0; i<26; i++) {
                letters[i] = 0;
        }
        current = 0;
}

// return the number of occurence of ch in the current object.
int LetterBag::getFrequency(char c) const {
        if(isalpha(c)) {
                c = tolower(c);
                return letters[(int)(c - 'a')];
        }
        return 0;
}


// return a string with the letters in this object, in sorted order and lowercase. e.g. "ddfz"
string LetterBag::toString() const {
        string s = "";
        for(int i=0; i<26; i++) {
                char c = ('a' + i);
                for(int j=0; j<letters[i]; j++) {
                        s.push_back(c);
                }
        }
        return s;
}

// return true iff the current object and other are equal.
bool LetterBag::operator==(const LetterBag & other) const {
        return (toString().compare(other.toString()) == 0);
}

// return false iff the current object and other are equal.
bool LetterBag::operator!=(const LetterBag & other) const {
        return (toString().compare(other.toString()) != 0);
}



