#include <iostream>

using namespace std;

class Node
{
    public:
    int data;
    Node *next;
};

void printBackwards(Node *head)
{
    if (head = NULL)
        return;

        printBackwards(head->next);

        cout << head->data << " ";
}

void add(Node** head_ref, char data)
{
    Node* newNode = new Node;
     newNode->data = data;
     newNode->next = (*head_ref);
     (*head_ref) = newNode;
}

int main()
{
    //Linked list 1->2->3->4
    Node* head = NULL;

    add(&head, 4);
    add(&head, 3);
    add(&head, 2);
    add(&head, 1);

    printBackwards(head);

    return 0;
}
