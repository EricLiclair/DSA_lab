#include <iostream>
#define null NULL

using namespace std;

struct node
{
    int data;
    struct node *next;
};

struct node *front = null;
struct node *rear = null;
struct node *temp;

void insertToQueue()
{
    int val;
    cout << "Enter the element to be entered in queue : " << endl;
    cin >> val;
    if (rear == null)
    {
        rear = (struct node *)malloc(sizeof(struct node));
        rear->next = null;
        rear->data = val;
        front = rear;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        rear->next = temp;
        temp->data = val;
        temp->next = null;
        rear = temp;
    }
}

void deleteFromQueueNode()
{
    temp = front;
    if (front == null)
    {
        cout << "Underflow" << endl;
        return;
    }
    else if (temp->next != null)
    {
        temp = temp->next;
        cout << "Element deleted from queue is : " << front->data << endl;
        delete (front);
        front = temp;
    }
    else
    {
        cout << "Element deleted from queue is : " << front->data << endl;
        delete (front);
        front = null;
        rear = null;
    }
}

void displayQueue()
{
    temp = front;
    if ((front == null) && (rear == null))
    {
        cout << "Queue is empty" << endl;
        return;
    }
    cout << "Queue elements are: ";
    cout << "OUT <- ";
    while (temp != null)
    {
        cout << temp->data << " <- ";
        temp = temp->next;
    }
    cout << "IN\n";
}

void mapTask(int choice)
{
    switch (choice)
    {
    case 1:
        insertToQueue();
        break;

    case 2:
        deleteFromQueueNode();
        break;

    case 3:
        displayQueue();
        break;

    default:
        break;
    }
}

void showMenu()
{
    cout << "\n\nWhat would you like to do ?\n1. insert element to the queue\n2. Delete element from the queue\n3. display queue\n4. Exit\n\n";
}

int main()
{
    // int ch;
    // cout << "1) Insert element to queue" << endl;
    // cout << "2) Delete element from queue" << endl;
    // cout << "3) Display all the elements of queue" << endl;
    // cout << "4) Exit" << endl;
    // do
    // {
    //     cout << "Enter your choice : " << endl;
    //     cin >> ch;
    //     switch (ch)
    //     {
    //     case 1:
    //         Insert();
    //         break;
    //     case 2:
    //         Delete();
    //         break;
    //     case 3:
    //         Display();
    //         break;
    //     case 4:
    //         cout << "Exit" << endl;
    //         break;
    //     default:
    //         cout << "Invalid choice" << endl;
    //     }
    // } while (ch != 4);
    int choice;
    do
    {
        showMenu();
        cout << "Enter choice : ";
        cin >> choice;
        mapTask(choice);
    } while (choice != 4);
    return 0;
}