#include <iostream>
using namespace std;
//
class doublyll
{
private:
    struct node
    {
        int data;
        node *next;
        node *prev;
    } *head, *tail;

public:
    doublyll()
    {
        head = NULL;
        tail = NULL;
    }
    void insertbeg(int);
    int deletebeg();
    int deleteend();
    void insertend(int);
    void insertpos(int, int);
    int deletepos(int);
    void display();
    int search(int);
};
int main()
{
    doublyll mylist;
    int inp = 0, ind = 0, value = 0, index = 0;
    while (1)
    {
        cout << "--------------------------------" << endl;
        cout << "1.Insert at beginning\n2.Insert at End\n3.Insert at a position\n4.Delete beginning\n5.Delete end\n6.Delete at a position\n7.Search\n8.Display\n9.Exit\n\nEnter choice : ";
        cin >>inp;
            
        switch (inp)
        {
        case 1:
            cout << "Enter value to be inserted : ";
            cin >> value;
            mylist.insertbeg(value);
            break;
        case 2:
            cout << "Enter value to be inserted : ";
            cin >> value;
            mylist.insertend(value);
            break;
        case 3:

            cout << "Enter value to be inserted : ";
            cin >> value;
            cout << "Enter index : ";
            cin >> index;
            mylist.insertpos(value, index);
            break;
        case 4:
            mylist.deletebeg();
            break;
        case 5:
            mylist.deleteend();
            break;
        case 6:
            cout << "Enter index : ";
            cin >> index;
            mylist.deletepos(index);
            break;
        case 7:
            cout << "Enter value to be searched : ";
            cin >> value;
            ind = mylist.search(value);
            if (ind == -1)
            {
                cout << "Element not found! \n";
            }
            else
            {
                cout << "Element found at index: " << ind << endl;
            }
            break;
        case 8:
            mylist.display();
            break;
        case 9:
            cout << "THANKS FOR COMING BY!... :)\n";
            return 0;
            break;
        }
    }
    return 0;
}
// Insert element in the beginning
void doublyll ::insertbeg(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->data = num;
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}
// Displaying the list in both the orders
void doublyll ::display()
{
    cout << endl;
    if (head == nullptr)
    {
        cout << "List is empty.\n\n";
        return;
    }
    node *curr = head;
    cout << "Forward : ";
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    curr = tail;
    cout << "Backward : ";
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}
// Inserting element at the end
void doublyll::insertend(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->data = num;
    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}
// Inserting element at a given index
void doublyll::insertpos(int num, int ind)
{
    if (ind < 0)
    {
        cout << "INVALID INDEX";
        return;
    }
    if (head == nullptr)
    {
        if (ind > 0)
        {
            cout << "INVALID INDEX";

            return;
        }
        else if (ind == 0)
        {
            node *newnode = new node();
            newnode->next = nullptr;
            newnode->prev = nullptr;
            newnode->data = num;
            head = newnode;
            tail = newnode;
        }
    }
    else
    {
        node *curr = head;
        node *newnode = new node();
        newnode->next = nullptr;
        newnode->prev = nullptr;
        newnode->data = num;
        for (int i = 0; i < ind - 1; i++)
        {
            if (curr == nullptr)
            {
                cout << "INVALID INDEX\n";
                return;
            }
            curr = curr->next;
        }
        if (curr->next == nullptr)
        {
            newnode->prev = curr;
            curr->next = newnode;
            tail = newnode;
            return;
        }
        newnode->next = curr->next;
        curr->next->prev = newnode;
        newnode->prev = curr;
        curr->next = newnode;
    }
}
// Deleting the first element of the list
int doublyll::deletebeg()
{
    if (head == nullptr)
    {
        cout << "Empty list.\n";
        return -1;
    }
    if (head->next == NULL)
    {
        int temp = head->data;
        delete head;
        head = nullptr;
        tail = nullptr;
        return temp;
    }
    node *removeme = head;
    int temp = head->data;
    head = head->next;

    head->prev = nullptr;
    delete removeme;
    return temp;
}
// Deleting the last element of the list
int doublyll::deleteend()
{
    if (head == nullptr)
    {
        cout << "Empty list.\n";
        return -1;
    }
    if (head->next == nullptr)
    {
        int temp = head->data;
        head = nullptr;
        tail = nullptr;
        return temp;
    }
    int temp = tail->data;
    tail = tail->prev;
    tail->next = nullptr;
    return temp;
}
// Deleting an element at a particular index
int doublyll::deletepos(int ind)
{
    if (ind < 0)
    {
        cout << "INVALID INDEX\n\n";
        return -1;
    }
    if (head == nullptr)
    {
        cout << "Empty list.\n\n ";
        return -1;
    }
    if (ind == 0)
    {
        int temp = head->data;
        if (head->next == nullptr)
        {
            head = nullptr;
            tail = nullptr;
            return temp;
        }
        head = head->next;
        head->prev = nullptr;
        return temp;
    }
    else
    {
        node *curr = head;
        for (int i = 0; i < ind - 1; i++)
        {
            curr = curr->next;
            if (curr == nullptr)
            {
                cout << "INVALID INDEX\n\n";
                return -1;
            }
        }
        if (curr->next->next == nullptr)
        {
            int temp = tail->data;
            tail = tail->prev;

            tail->next = nullptr;
            return temp;
        }
        int temp = curr->next->data;
        curr->next = curr->next->next;
        curr->next->prev = curr;
        return temp;
    }
}
// Searching an element and returning its index if present
int doublyll::search(int value)
{
    if (head == nullptr)
    {
        cout << "Empty list.\n";
        return -1;
    }
    int ind = 0;
    node *curr = head;
    while (curr != nullptr)
    {
        if (curr->data == value)
        {
            return ind;
        }
        else
        {
            ind++;
            curr = curr->next;
        }
    }
    return -1;
}