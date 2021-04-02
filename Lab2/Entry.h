#ifndef ENTRY_H_INCLUDED
#define ENTRY_H_INCLUDED

#include<iostream>
using namespace std;

ostream &operator << (ostream &, const Entry &);
istream &operator >> (istream &, Entry &);

class Entry
{
    private:
        int enter;
    public:
        void setentry(int entry)
        {
            this->entry = entry;
        }
        int getentry() const
		{
		     return entry;
        }

    friend ostream &operator << (ostream &, const Entry &);
	friend istream &operator >> (istream &, Entry &);

};



#endif // ENTRY_H_INCLUDED
