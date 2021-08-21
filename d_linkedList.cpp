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
        // Update a Node by Key
        void updateNode(int, int);
        // print list to std::out
        void printList();

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
        cout << endl << endl <<  "Node already exists with key value : " << n->key <<". Append another node with different key value" << endl << endl;
    }
    else
    {
        if(head==NULL)
        {
            head = n;
            cout << endl << endl <<  "Node appended as head node" << endl << endl;
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
            cout << endl << endl <<  "Node appended" << endl << endl;
        }
    }
};

// Prepend Node to the List
void LinkedList::prependNode(Node* n)
{
    if(nodeCheck(n->key)!=NULL)
    {
        cout << endl << endl <<  "Node Already exists with key value: " << n->key << ". Append another node with different value" << endl << endl;
    }
    else
    {
        if(head==NULL)
        {
            head = n;
            cout << endl << endl <<  "Node Prepended as head Node" << endl << endl;
        }
        else
        {
            head->previous = n;
            n->next = head;
            head = n;
            cout << endl << endl <<  "Node prepended" << endl << endl;
        }
    }
}

// Insert Node after a specific node in the list
void LinkedList::insertNodeAfter(int k, Node* n)
{
    Node* ptr = nodeCheck(k);
    if(ptr==NULL)
    {
        cout << endl << endl <<  "No node exists with key value: " << k << endl << endl;
    }
    else
    {
        if(nodeCheck(n->key) != NULL)
        {
            cout << endl << endl <<  "Node already exists with key value: " << n->key << ". Append another node with different key value" << endl << endl;
        }
        else
        {
            cout << endl << endl <<  "Inserting..." << endl << endl;

            Node* nextNode = ptr->next;

            // append to the end of list
            if(nextNode == NULL)
            {
                ptr->next = n;
                n->previous = ptr;
                cout << endl << endl <<  "Node Inserted at the end of list" << endl << endl;
            }
            else // insert between nodes
            {
                n->next = nextNode;
                nextNode->previous = n;
                n->previous = ptr;
                ptr->next = n;

                cout << endl << endl <<  "Node inserted in between" << endl << endl;
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
        cout << endl << endl <<  "No node found with this key: " << k << endl << endl;
    }
    else
    {
        if(head->key==k)
        {
            head = head->next;
            cout << endl << endl <<  "Node is being deleted with key: " << k << endl << endl;
        }
        else
        {
            Node* nextNode = ptr->next;
            Node* prevNode = ptr->previous;
            // delete at the end
            if(nextNode == NULL)
            {
                prevNode->next = NULL;
                cout << endl << endl <<  "Node deleted at the end of list" << endl << endl;
            }
            // delete in between
            else
            {
                prevNode->next = nextNode;
                nextNode->previous = prevNode;
                cout << endl << endl <<  "Node deleted in between" << endl << endl;
            }
        }
    }
}

// Update a Node
void LinkedList::updateNode(int k, int d)
{
    Node* ptr = nodeCheck(k);

    if(ptr != NULL)
    {
        ptr->data = d;
        cout << endl << endl <<  "Node data updated successfully" << endl << endl;
    }
    else
    {
        cout << endl << endl <<  "Node doesn't exist with key value " << k << endl << endl;
    }
}

// Print the list of nodes
void LinkedList::printList()
{
    if(head == NULL)
    {
        cout << endl << endl << "No nodes in Linked List" << endl << endl;
    }
    else
    {
        cout << endl << "Linked List Values: ";
        Node* temp = head;

        while(temp != NULL)
        {
            if(temp->next == NULL)
            {
                cout << "(" << temp->key << ", " << temp->data << ")" << endl << endl;
                temp = temp->next;
            }
            else
            {
                cout << "(" << temp->key << ", " << temp->data << ") <--> " << endl << endl;
                temp = temp->next;
            }
        }
    }
}

// Main function
int main()
{
    // Create object
    LinkedList L;
    int iOption, iK1, iK2, iData1;

    // Create a menu to display options
    do
    {
        cout << endl << "Select an opertation or 0 to exit: " << endl;
        cout << "1. Append node in list" << endl;
        cout << "2. Prepend node in list" << endl;
        cout << "3. Add a node" << endl;
        cout << "4. Delete a node" << endl;
        cout << "5. Update a node" << endl;
        cout << "6. Print List" << endl;
        cout << "7. Clear Screen " << endl;

        cout << "Enter an option: ";
        cin >> iOption;

        // Create a new Node
        Node* n1 = new Node();

        // switch case for menu choice
        switch(iOption)
        {
            case 0:
                break;
            case 1:
                cout << "Append Node\nEnter key & data of the Node to be Appended to: " << endl;
                cout << "Key: ";
                cin >> iK1;
                cout << endl << "Data: ";
                cin >> iData1;
                n1->key = iK1;
                n1->data = iData1;
                L.appendNode(n1);
                break;
                
            case 2:
                cout << "Prepend Node\nEnter key & data of the Node to be Prepended: " << endl;
                cout << "Key: ";
                cin >> iK1;
                cout << endl << "Data: ";
                cin >> iData1;
                n1->key = iK1;
                n1->data = iData1;
                L.prependNode(n1);
                break;

            case 3:
                cout << "Add Node\nEnter key of existing node after which this one will be inserted " << endl;
                cout << "Key: ";
                cin >> iK1;
                cout << endl << "Enter Key & data of new node: " << endl;
                cout << "Key: ";
                cin >> iK2;
                cout << endl << "Data: ";
                cin >> iData1;
                n1->key = iK2;
                n1->data = iData1;
                L.insertNodeAfter(iK1, n1);
                break;

            case 4:
                cout << "Delete Node\nEnter key of node to be deleted: ";
                cin >> iK1;
                L.deleteNode(iK1);
                break;

            case 5:
                cout << "Update Node\nEnter key & new data " << endl;
                cout << "Key: ";
                cin >> iK1;
                cout << endl << "Data: ";
                cin >> iData1;
                L.updateNode(iK1, iData1);
                break;

            case 6:
                L.printList();
                break;

            case 7:
                system("clear");
                break;

            default:
                cout << "Enter a valid option" << endl;

        }
        
    } while (iOption != 0);
    

    return 0;
}