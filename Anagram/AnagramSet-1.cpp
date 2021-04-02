
#include "AnagramSet.h"



bool AnagramSet::contains(const string & s)
{
	int start = 0, scanright = Words.size() - 1;

	while (start <= scanright)
	{
		int mid = (start + scanright) / 2;


		if (!Words.at(mid).compare(s))
        {
            return true;
        }

		if (Words.at(mid).compare(s) < 0)
        {
            start = mid + 1;
        }
		else
			scanright = mid - 1;
	}
	return false;
}

void AnagramSet::insert(const string &s)
{
	if (!contains(s))
	{
		Words.push_back(s);
		for (unsigned int i = 0; i < Words.size(); i++)
		{
			if (Words.at(i).compare(s) > 0)
			{
				Words.insert(Words.begin() + i, s);
				return;
			}
		}
	}
	return;
}



void AnagramSet::remove(const string &s)
{
	if (contains(s))
	{
		for (unsigned int i = 0; i < Words.size(); i++)
		{
			if (Words.at(i).compare(s) == 0)
            {
                Words.erase(Words.begin() + i);
            }

		}
	}
	return;
}




ostream & operator<< (ostream & out, const AnagramSet & s)
{
	vector<string> words = s.getWords();

	out << "\n{ " << s.key.toString() << ": ";

	for (unsigned int i = 0; i < words.size(); i++)
	{
		out << words.at(i);

		if (i != (words.size() - 1))
        {
            out << ", ";
        }

	}
	out << " }";
	return out;
	// output the AnagramSet in a format like {aet: ate, eat, eta, tea}

	// aet is the key as a sorted string and ate, eat ... are the words.

}
int AnagramSet::getSize() const
{
	return Words.size();

}

void AnagramSet::clear()
{
	Words.clear();
}


vector <string> AnagramSet::getWords() const
{
	return Words;
}

