#include <iostream>
using namespace std;
//
class circularll
{
private:
    struct node
    {
        int data;
        node *next;
    } *head;

public:
    circularll()
    {
        head = NULL;
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
    circularll mylist;
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
// Inserting the given value at the beginning index of the list
void circularll::insertbeg(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->data = num;
    if (head == nullptr)
    {
        head = newnode;
        head->next = newnode;
        return;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = newnode;
        newnode->next = head;
        head = newnode;
        return;
    }
}
// Displaying the elements of the list
void circularll::display()
{
    if (head == nullptr)
    {
        cout << "Empty list. \n\n";
        return;
    }
    node *curr = head;
    cout << "List: ";

    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << endl;
    return;
}
// Deleting the first element of the list
int circularll::deletebeg()
{
    if (head == nullptr)
    {
        cout << "Empty list. \n\n";
        return -1;
    }
    else
    {
        if (head->next == head)
        {
            int temp = head->data;
            head = nullptr;
            return temp;
        }
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        int temp = head->data;
        head = head->next;
        curr->next = head;
        return temp;
    }
}
// Inserting the given element at the end of the list
void circularll::insertend(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->data = num;
    if (head == nullptr)
    {
        head = newnode;
        head->next = newnode;
        return;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}
// Deleting the last element of the lsit

int circularll::deleteend()
{
    if (head == nullptr)
    {
        cout << "Empty list. \n\n";
        return -1;
    }
    else
    {
        if (head->next == head)
        {
            int temp = head->data;
            head = nullptr;
            return temp;
        }
        node *curr = head;
        while (curr->next->next != head)
        {
            curr = curr->next;
        }
        int temp = curr->next->data;
        curr->next = head;
        return temp;
    }
}
// Inserting a value at the given index in a list
void circularll::insertpos(int num, int ind)
{
    if (ind < 0)
    {
        cout << "Invalid index! \n\n";
        return;
    }
    else
    {
        if (head == nullptr)
        {
            if (ind > 0)
            {
                cout << "Invalid index! \n\n";
                return;
            }
            else
            {
                node *newnode = new node();
                newnode->next = newnode;
                newnode->data = num;
                head = newnode;
            }
        }
        else
        {
            node *curr = head;
            node *newnode = new node();
            newnode->next = nullptr;
            newnode->data = num;
            if (ind == 0)
            {
                while (curr->next != head)
                {
                    curr = curr->next;
                }
                curr->next = newnode;
                newnode->next = head;
                head = newnode;
                return;
            }
            for (int i = 0; i < ind - 1; i++)
            {
                curr = curr->next;
            }
            newnode->next = curr->next;
            curr->next = newnode;
            return;
        }
    }
}
// Deleting the value at the given index of the list
int circularll::deletepos(int ind)
{
    if (ind < 0)
    {
        cout << "Invalid index! \n\n";
        return -1;
    }
    else
    {
        if (head == nullptr)
        {
            cout << "Empty list.\n";
            return -1;
        }
        if (ind == 0)
        {
            node *curr = head;
            while (curr->next != head)
            {
                curr = curr->next;
            }
            int temp = head->data;
            head = head->next;
            curr->next = head;
            return temp;
        }
        else
        {
            node *curr = head;
            for (int i = 0; i < ind - 1; i++)
            {
                curr = curr->next;
                if (curr == head)
                {
                    cout << "INVALID INDEX\n";
                    return -1;
                }
            }
            int temp = curr->next->data;
            curr->next = curr->next->next;
            return temp;
        }
    }
}
// Searching an element and returning its index
int circularll::search(int num)
{
    if (head == nullptr)
    {
        cout << "Empty list. \n\n";
        return -1;
    }
    else
    {
        node *curr = head;

        int ind = 0;
        do
        {
            if (curr->data == num)
            {
                return ind;
            }
            curr = curr->next;
            ind++;
        } while (curr != head);
        return -1;
    }
}