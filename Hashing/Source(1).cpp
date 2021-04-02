#include "AnagramSet.h"
#include <iostream>
#include <fstream>
using namespace std;

const int wordListSize = 200000;
AnagramSet *dictionary2[wordListSize];

int main() {
    ifstream  infile;
    infile.open("words.txt");
    if (!infile) {
        cout << "File not found. Exiting." << endl;
        return 1;
    }
    int anagramCount = 0;
    while (infile) {
        string s;
        infile >> s;

        if (infile) {
            LetterBag b(s);
            int i = 0;
            for (; i < anagramCount; i++) {
                if (dictionary2[i]->key == b) {
                    dictionary2[i]->insert(s);
                    break;
                }
            }
            if (i == anagramCount) {
                dictionary2[anagramCount] = new AnagramSet(b);
                dictionary2[anagramCount++]->insert(s);
                if (anagramCount % 10000 == 0) cout << anagramCount << endl;
            }
        }
    }
    bool playAgain = true;
    while (playAgain) {
        cout << "Enter anagram & minimum result size: ";
        string s;
        int minSize;
        cin >> s >> minSize;
        LetterBag letters(s);
        bool foundOne = false;
        for (int i = 0; i < anagramCount; i++)
            if (dictionary2[i]->key.getCurrentSize() >= minSize && letters.isSubbag(dictionary2[i]->key)) {
                foundOne = true;
                cout << (*dictionary2[i]) << endl;
            }
        if (!foundOne) cout << "No matches found." << endl;
        cout << endl << "Play again (y/n) ? ";
        char response;
        cin >> response;
        playAgain = response == 'y';
    }

  
    cout << "Bye" << endl;

    return 0;
}