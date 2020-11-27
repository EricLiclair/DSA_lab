/*
2. 2.	Write a C program to create a circular linked list so that the input order of data items is maintained.
Add the following functions to carry out the following operations on circular single linked lists. 
a) Count the number of nodes. b) insert a node c) delete a node
*/
#include <iostream>
#define null NULL
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = null;
    }
};

Node *head = null;
Node *tail = head;

void insertNode()
{
    int nodeData;
    cout << "enter the data to be inserted : ";
    cin >> nodeData;
    Node *newNode = new Node(nodeData);

    if (head == null)
    {
        head = newNode;
        tail = head;
        return;
    }

    tail->next = newNode;
    newNode->next = head;
    tail = newNode;
    return;
}

void deleteNode()
{
    if (head == null)
    {
        cout << "Empty List!!\n";
        return;
    }

    int nodeData;
    cout << "Enter data to be deleted : ";
    cin >> nodeData;

    Node *ptr = head;
    if (ptr->data == nodeData)
    {
        head = head->next;
        delete ptr;
        return;
    }

    Node *temp = null;
    do
    {
        if (ptr->next->data == nodeData)
            temp = ptr;
        ptr = ptr->next;
    } while (ptr->next != head);
    temp->next = ptr->next;
    delete (ptr);
}

int countNode()
{
    int count = 0;
    Node *ptr = head;
    do
    {
        count += 1;
        ptr = ptr->next;
    } while (ptr != head);
    return count;
}

void showMenu()
{
    cout << "\n\nWhat would you like to do ?\n1. insert node\n2. Delete node\n3. count nodes\n4. Exit\n\n";
}

void mapTask(int choice)
{
    switch (choice)
    {
    case 1:
        insertNode();
        break;

    case 2:
        deleteNode();
        break;

    case 3:
        cout << "The Number of nodes are: " << countNode();
        break;

    default:
        break;
    }
}

int main()
{
    int choice;
    do
    {
        showMenu();
        cout << "Enter choice : ";
        cin >> choice;
        mapTask(choice);
    } while (choice != 4);
}