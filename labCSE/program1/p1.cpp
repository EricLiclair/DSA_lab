/*
1.	Write an interactive C program to create a linear linked list of customer names 
and their telephone numbers. The program should be menu-driven and include features 
for adding a new customer, deleting an existing customer and for displaying the list 
of all customers.
*/
#include <iostream>
#define null NULL
using namespace std;

struct Customer
{
    string name;
    int phone;
    Customer *next;
    Customer(string cName, int cPhone)
    {
        this->name = cName;
        this->phone = cPhone;
    }
};

Customer *head = null;

void addCustomer()
{
    string cName;
    int cPhone;
    cout << "Enter customer Name : ";
    cin >> cName;
    cout << "Enter customer phone number : ";
    cin >> cPhone;
    Customer *newCustomer = new Customer(cName, cPhone);
    if (head == null)
    {
        head = newCustomer;
        return;
    }

    newCustomer->next = head;
    head = newCustomer;
    return;
}

void deleteCustomer()
{
    if (head == null)
    {
        cout << "Empty List!!\n";
        return;
    }

    string customerName;
    cout << "Enter customer name to delete";
    cin >> customerName;

    Customer *ptr = head;
    if (ptr->name == customerName)
    {
        head = head->next;
        delete ptr;
        return;
    }

    Customer *temp = null;
    while (ptr->next != null)
    {
        if (ptr->next->name == customerName)
            temp = ptr;
        ptr = ptr->next;
    }
    temp->next = ptr->next;
    delete (ptr);
}

void showList()
{
    Customer *ptr = head;
    while (ptr != null)
    {
        cout << "Customer Name: " << ptr->name << "\t\tCustomer Phone no. : " << ptr->phone << endl;
        ptr = ptr->next;
    }
}

void showMenu()
{
    cout << "\n\nWhat would you like to do ?\n1. Add new customer\n2. Delete existing customer\n3. Display All Customers\n4. Exit\n\n";
}

void mapTask(int choice)
{
    switch (choice)
    {
    case 1:
        addCustomer();
        break;

    case 2:
        deleteCustomer();
        break;

    case 3:
        showList();
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