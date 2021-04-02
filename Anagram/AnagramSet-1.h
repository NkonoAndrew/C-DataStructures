#ifndef ANAGRAMSET_H
#define ANAGRAMSET_H

#include "LetterBag.h"
//#include <iostream>
//#include <vector>
class AnagramSet
{

public:
	friend ostream & operator<< (ostream & out, const AnagramSet & s);

	// Member functions

	void insert(const string & s);

	void remove(const string & s);

	int getSize() const;

	bool contains(const string & s);

	void clear();

	AnagramSet(const LetterBag & theKey) : key(theKey)
	{
		key = theKey;
	}

	vector <string> getWords() const;
	// we won't need a getKey since the key is a public constant.

  LetterBag key;

private:
	vector <string> Words;

};

#endif



