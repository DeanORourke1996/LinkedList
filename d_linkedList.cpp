#include <iostream>

using namespace std;

// Classes
class Node {
    public:
        // Properties
        int key;
        int data;
        Node* next;
        Node* previous;

        // Members
        Node();
        Node(int, int);

};

class LinkedList {
    public:
        Node* head;

        // Members
        LinkedList(); // Constructor
        LinkedList(Node*); // Overload
        // Check Node exists
        Node* nodeCheck(int);
        // Attach Node to the List
        void appendNode(Node*);
        // Attach Node at the Start
        void prependNode(Node*);
        // Insert Node after a specific node
        void insertNodeAfter(int, Node*);
        // Delete Node by unique key
        void deleteNode(int);

};

/*
 * Member Definitions
 */
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

// Linked List Constructor
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

// Prepend Node to the List
void LinkedList::prependNode(Node* n)
{
    if(nodeCheck(n->key)!=NULL)
    {
        cout << "Node Already exists with key value: " << n->key << ". Append another node with different value" << endl;
    }
    else
    {
        if(head==NULL)
        {
            head = n;
            cout << "Node Prepended as head Node" << endl;
        }
        else
        {
            head->previous = n;
            n->next = head;
            head = n;
            cout << "Node prepended" << endl;
        }
    }
}

// Insert Node after a specific node in the list
void LinkedList::insertNodeAfter(int k, Node* n)
{
    Node* ptr = nodeCheck(k);
    if(ptr==NULL)
    {
        cout << "No node exists with key value: " << k << endl;
    }
    else
    {
        if(nodeCheck(n->key) != NULL)
        {
            cout << "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl;
        }
        else
        {
            cout << "Inserting..." << endl;

            Node* nextNode = ptr->next;

            // append to the end of list
            if(nextNode == NULL)
            {
                ptr->next = n;
                n->previous = ptr;
                cout << "Node Inserted at the end of list" << endl;
            }
            else // insert between nodes
            {
                n->next = nextNode;
                nextNode->previous = n;
                n->previous = ptr;
                ptr->next = n;

                cout << "Node inserted in between" << endl;
            }
        }
    }
}

// Delete a node 
void LinkedList::deleteNode(int k)
{
    Node* ptr = nodeCheck(k);
    if(ptr==NULL)
    {
        cout << "No node found with this key: " << k << endl;
    }
    else
    {
        if(head->key==k)
        {
            head = head->next;
            cout << "Node is being deleted with key: " << k << endl;
        }
        else
        {
            Node* nextNode = ptr->next;
            Node* prevNode = ptr->previous;
            // delete at the end
            if(nextNode == NULL)
            {
                prevNode->next = NULL;
                cout << "Node deleted at the end of list" << endl;
            }
            // delete in between
            else
            {
                prevNode->next = nextNode;
                nextNode->previous = prevNode;
                cout << "Node deleted in between" << endl;
            }
        }
    }
}

int main()
{

    return 0;
}