#include <iostream>
using namespace std;

class Node
{
    public:
    int data;
    Node* next;
};

void printBackward(Node* head)
{
    if (head == NULL)
    return;

    printBackward(head->next);
    cout << head->data << "->";
}

void push(Node** head_ref, char new_data)
{

    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main()
{
    Node* head = NULL;
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    printBackward(head);

}
