#include <iostream>

using namespace std;

class Node {
    public:
        int key;
        int data;
        Node* next;
        Node* previous;

        Node();
        Node(int, int);

};

class LinkedList {
    public:
        Node* head;
        LinkedList();
        LinkedList(Node*);
        // Check Node exists
        Node* nodeCheck(int);
        // Attach Node to the List
        void appendNode(Node*);
};

Node::Node()
{
    key = 0;
    data = 0;
    next = NULL;
    previous = NULL;
}
Node::Node(int k, int d)
{
    key = k;
    data = k;
}

LinkedList::LinkedList()
{
    head = NULL;
}

LinkedList::LinkedList(Node* n)
{
    head = n;
}

Node* LinkedList::nodeCheck(int k)
{
    Node* temp = NULL;
    Node* ptr = head;

    while(ptr != NULL)
    {
        if(ptr->key==k)
        {
            temp = ptr;
        }
        ptr = ptr->next;
    }

    return temp;
}

// Attach Node to the List
void LinkedList::appendNode(Node* n)
{
    if(nodeCheck(n->key)!=NULL)
    {
        cout << "Node already exists with key value : " << n->key <<". Append another node with different key value" << endl;
    }
    else
    {
        if(head==NULL)
        {
            head = n;
            cout << "Node appended as head node";
        }
        else 
        {
            Node* ptr = head;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = n;
            n->previous = ptr;
            cout << "Node appended" << endl;
        }
    }
};

int main()
{

    return 0;
}