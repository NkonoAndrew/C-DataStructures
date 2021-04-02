#include "Dictionary.h"
#include <fstream>
Dictionary::Dictionary()  // default constructor: creates an empty dictionary.
{
	numWords = 0;
}
Dictionary::Dictionary(string fileName)  // insert all words from the file into an empty dictionary.
{
	ifstream inFile;
	string something;
	inFile.open(fileName);
	numWords = 0;

	while (!inFile.eof())
	{

		inFile >> something;
		LetterBag v(something);
		if(inFile)
        {
            if(insertWord(something))
            {
                cout << something << "\n";
            }

        }

	}

}

Dictionary::Dictionary(const Dictionary & d)
{
	int n = 0;
	while (n < tableSize)
	{
		hashTable[n] = d.hashTable[n];
		numWords = d.numWords;
	}


}


Dictionary::Dictionary(string words[], int arraySize)  // insert all words from the array into an empty dictionary.
{

	int i = 0;
	while(i < arraySize)
	{
		if(!insertWord(words[i]))
        {
            cout << words[i] << " found";
        }
        i++;
	}

}

Dictionary::~Dictionary()
{
	clear();
}

int Dictionary::getNumWords() const
{
	return numWords;
}

bool Dictionary::contains(string word) const
{
	LetterBag v(word);
	int hValue = hashAnagram(v);
	AnagramSet *temp = hashTable[hValue];

	while (temp != nullptr)
	{
		if (temp->key != v)
		{
			temp = temp->next;
		}
		else
        {
            return true;
        }
	}
	return false;


}

bool Dictionary::insertWord(const string &w)  // insert a word, return true if wasn’t already there, false if already there.
{
    LetterBag some(w);
    int index = hashAnagram(some);
    AnagramSet *temp = hashTable[index];

	 temp = find( hashTable[index], some);
		if (temp == nullptr)
		{
			temp = new AnagramSet(w);
            insertNew(index, temp);
		}

	temp->insert(w);
        numWords++;

    return temp;


}
int Dictionary::insertWords(const vector<string> v)  // insert multiple words and return how many weren’t already there.
{


   int fish = 0;
   int newnumWords = numWords;
    while (fish < v.size())
	{
		if (!insertWord(v[fish]))
		{
			cout << "Same Word " << v[fish] << endl;
		}
		fish++;
    return newnumWords - numWords;
    }

}
bool Dictionary::removeWord(string w)  // remove the word. Return true if it was there to be removed and false otherwise.
{
	LetterBag v(w);
    int index;
    AnagramSet *temp = findWord(w), *prev;

    if(temp == nullptr)
    {
        return false;
    }

    if(temp->getSize() == 1)
    {
        index = hashAnagram(v);

        if(temp == hashTable[index])
        {
            hashTable[index] = temp->next;
        }
        else
        {
            prev = findPrevious(hashTable[index], w);
            prev->next = temp->next;
        }
        temp->clear();
        delete temp;
    }
    else
    {
        temp->remove(w);
    }
    numWords--;
    return true;
}

void Dictionary::clear()
{
    AnagramSet *temp;
    for(int n = 0; n < tableSize; n++ )
    {

        while( hashTable[n] != nullptr )
        {

            temp = hashTable[n];

            while( temp->next != nullptr )
            {
                temp = temp->next;
            }

            temp->clear();
            delete temp;
        }
    }

}

void Dictionary::printDictionary(int limit, ostream & out) const
{

    AnagramSet *temp;

    for( int i = 0; i < limit; i++ )
    {

        temp = hashTable[i];
        if( temp != nullptr )
        {
            out << i << "...";

        }
        while( temp != nullptr )
        {
            out << *temp << '\t' << endl;
            temp = temp->next;
        }

    }
    out << "Number of words: " << getNumWords() << "\nThe Tablesize is: " << tableSize << endl;


}


vector<string> Dictionary::getWords(const string & word) const // return words that are anagrams for the given word.
{
    vector<string> ana;
    ana.clear();
	LetterBag v(word);
    int n = hashAnagram(v);
    AnagramSet *temp = find(hashTable[n], v);

    if(temp != nullptr)
    {
        return temp->getWords();
    }
    else{
            return ana;
    }

}

int Dictionary::getNumAnagrams(const string & word) const  // return number of anagrammatic forms found for the given word.
{

	LetterBag v(word);
    int index = hashAnagram(v);
    AnagramSet *temp = find( hashTable[index], v);
    if(temp == nullptr)
    {
        return 0;// return nothing
    }
    return temp->getSize();
}


int Dictionary::hashAnagram(LetterBag v) const
{
	int h = 0;
	for (char ch = 'a'; ch <= 'z'; ch++)
	{
		h *= 10;
		h += v.getFrequency(ch);
		h %= tableSize;
	}
	return h;
}

AnagramSet *Dictionary::findWord(const string &w) const
{
    LetterBag v(w);
    int i = hashAnagram(v);
    AnagramSet *loca = find(hashTable[i], v);

    if( loca != nullptr )
    {
        if(loca->contains(w))
        {
            return loca;
        }
        else{
            return nullptr;
        }

    }


}

AnagramSet * Dictionary::findPrevious(AnagramSet * head, const LetterBag & key) const
{
    if( head == nullptr || head->key == key )
    {
        return nullptr;
    }
    AnagramSet *loca= head;
    while( loca->next != nullptr)
    {
        if((loca->next)->key != key )
        {
            loca = loca->next;
        }
         if( loca->next == nullptr )
    {
        return nullptr;
    }

    return loca;
    }


}


void Dictionary::insertNew(int index, AnagramSet * toInsert)
{
    toInsert->next = hashTable[index];
    hashTable[index] = toInsert;

}

AnagramSet * Dictionary::find(AnagramSet * head, const LetterBag & key) const
{
    AnagramSet *loca = head;
    while( loca != nullptr && loca->key != key)
    {
        loca = loca->next;
    }
    return loca;


}


