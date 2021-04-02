#ifndef LINKEDLIST_H_INCLUDED
#define LINKEDLIST_H_INCLUDED
#include<iostream>
#include<stdlib.h>
#include<stdexcept>

using namespace std;
template <class T>
struct Node
{
    T data;
    Node<T> *Next, *Previous;

};

template <class T>
class Linkedlist
{
    private:
        Node<T> *First = NULL;
        Node<T> *Last = NULL;
        Node<T> *Middle = NULL;
        Node<T> *TempPrevious;
        Node<T> *TempNext;
        int length;

    public:

    	friend ostream& operator<< (ostream& out , const Linkedlist<T> & list)
        {
            Node<T>* temp = list.First;
            out << " { ";

            while (temp)
            {
                if (temp -> Next != NULL)
                {
                    out << temp -> data << ", ";
                }
                else
                {
                    out << temp -> data;
                }
                temp = temp->Next;
            }
            out << " }";
        return out;
        }

        Linkedlist()
        {
            First = NULL;
            Last = NULL;
            length = 0;
        }

        ~Linkedlist()
        {
            clear();
        }

        void insertfirst(const T & data)
        {
            P = new Node<T>;
            length++;

            P->Previous = NULL;
            P->data = data;
            P->Next = First;
            First = P;

            if (length == 1)
            {
               P = Last;
            }

            if (length > 1)
            {
                P = P->Next;
                P -> Previous = First;
            }
        }

        void insertlast(const T & d)
        {
            P = new Node<T>;
            length++;

            if (length == 1)
            {
                First = NULL;
            }

            P->Previous = Last;
            P->data = d;
            P->Next = NULL;
            Last = P;

            if (First == NULL)
            {
                First = P;
                P -> Previous = NULL;
            }
            else
            {
                P = P->Previous;
                P->Next = Last;
            }

        }

        //Copy constructor
       Linkedlist(const Linkedlist<T> &others)
        {
            First = Last = NULL;
            length = 0;
            Node<T> *temp;
            temp = others.First;

            for (int x = 0; x < others.length; x++)
            {
                insertlast(temp->data);
                temp = temp -> Next;
            }
            temp = NULL;
        }

       /* LinkedList(const LinkedList<T> &other)
        {
        if(other.headptr == nullptr)
        {
            headptr = nullptr;
            length = 0;
        }

        headptr = new Node<T>();
        headptr -> Data = other.headptr -> Data;
        Node <T> *pre = headptr, *othercurrent = other.headptr -> next;

        while(othercurrent != nullptr)
        {
            pre -> next = new Node<T>;
            pre -> next -> Data = othercurrent -> Data;
            pre = pre -> next;
            othercurrent = othercurrent -> next;
        }

        pre -> next = nullptr;
        length = other.length;
        }*/


        T getfirst()const
        {
            if (isEmpty()) throw logic_error ("None");
                return First->data;
        }

        T getlast()const
        {
            if (isEmpty()) throw logic_error ("None");
                return Last->data;
        }

        void setfirst(const T &d)
        {
            this->First = d;
        }

        void setlast(const T &d)
        {
            this->Last = d;
        }

        void removefirst() //no parameters
        {
            Node<T> *temp = First;
            First = First->Next;
            delete temp;
            if (First)
            {
                First->Previous = NULL;
            }
            else
            {
                Last = NULL;
            }
            length--;
        }

        void removelast()
        {
            Node<T>* node = Last;
            Last = Last->Previous;
            delete node;
            if (Last)
            {
                Last->Next = NULL;
            }

            else
            {
                First = NULL;
            }
            length--;
        }

        int getlength()const
        {
            int count  = 0;
            for (int i = 0; i < length; i ++)
            {
                count++;
            }
            return count;
        }

        bool isEmpty()const
        {
            return First == NULL && Last == NULL;
        }

        void clear()
        {
            while(!isEmpty())
            {
                removefirst();
            }
        }

        void removeatposition(int pos)
        {
            if (pos > length)
            {
                cout << "\n There are " << length << " nodes" << endl;
                throw logic_error ("Enter a position less than or equal to the number of nodes");
            }

            if (pos == 1)
            {
               removefirst();
            }

            else if(pos == length)
            {
                removelast();
            }
            else
            {
                Node<T> *NewNode = new Node<T>;
                TempNext = First;

                for(int n = 1; n < pos; n++)
                {
                    TempNext = TempNext->Next;
                }
                TempPrevious = TempNext->Previous;
                NewNode = TempNext -> Next;

                TempPrevious->Next = NewNode;
                NewNode->Previous = TempPrevious;

                length--;

            }


        }

        void insertatposition( const T &d, int pos)
        {
            if (pos > length)
            {
                cout << "\n There are " << length << " nodes" << endl;
                throw logic_error ("Enter a position less than or equal to the number of nodes");
            }

            if (pos == 1)
            {
               insertfirst(d);
            }

            else if(pos == length)
            {
                insertlast(d);
            }
            else
            {
                Node<T> *newNode = new Node<T>;
                 TempNext = First;
                for(int n = 1; n < pos; n++)
                {
                    TempNext = TempNext->Next;
                }
                TempPrevious = TempNext->Previous;

                TempNext->Previous = newNode;
                TempPrevious->Next = newNode;

                newNode->Previous = TempPrevious;
                newNode->Next = TempNext;

                newNode->data = d;
                length++;
            }

        }

};

#endif // LINKEDLIST_H_INCLUDED


