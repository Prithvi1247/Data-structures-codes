#include <iostream>

using namespace std;

class linkedlist
{

private:
    struct node
    {

        int data;

        node *next;

    } *head;

public:
    linkedlist() { head = nullptr; }

    // Functions

    node *insertbeg(int);

    void display();

    bool del(int);

    bool search(int);
};

class hashADT
{

private:
    linkedlist arr[7];

public:
    // Functions

    void insert(int);

    void display();

    bool search(int);

    void del(int);
};

int main()
{

    hashADT h;

    int ch = 0;

    while (1)
    {

        cout << "1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice: ";

        cin >> ch;

        switch (ch)
        {

        case 1:
        {

            cout << "Enter value: ";

            int d;
            cin >> d;

            h.insert(d);

            break;
        }

        case 2:
        {

            cout << "Enter value: ";

            int d;
            cin >> d;

            h.del(d);

            break;
        }

        case 3:
        {

            cout << "Enter value: ";

            int d;
            cin >> d;

            bool ans = h.search(d);

            if (ans)
                cout << "Element present!\n";

            else
                cout << "Element not found!\n";

            break;
        }

        case 4:
        {

            h.display();

            break;
        }

        case 5:
        {

            cout << "-----------------------------\n";

            return 0;
        }
        }

        cout << "-----------------------------\n";
    }

    return 0;
}

// Displays the hash table

void hashADT::display()
{

    for (int i = 0; i < 7; i++)
    {

        arr[i].display();

        cout << endl;
    }
}

// Displays the linked list

void linkedlist::display()
{

    node *ptr = head;

    while (ptr != nullptr)
    {

        cout << ptr->data << " ";

        ptr = ptr->next;
    }

    cout << endl;
}

// Inserts the given element in the hash table

void hashADT::insert(int d)
{

    int key = d % 7;

    arr[key].insertbeg(d);

    cout << "Added successfully!\n";
}

// Inserts element in the beginning of the linkedlist

linkedlist::node *linkedlist::insertbeg(int d)
{

    node *nn = new node();

    nn->data = d;

    nn->next = head;

    head = nn;

    return head;
}

// Deletes the given element in the hash table

void hashADT::del(int d)
{

    int key = d % 7;

    if (!arr[key].del(d))
        cout << "Error ! no such value present. \n";
}

// Deletes the given element in the linkedlist

bool linkedlist::del(int d)
{

    node *ptr = head;

    if (head == nullptr)
        return false;

    if (ptr->data == d)
    {

        head = head->next;

        return true;
    }

    while (ptr->next != nullptr)
    {

        if (ptr->next->data == d)
        {

            ptr->next = ptr->next->next;

            return true;
        }
    }

    return false;
}

// Returns true if the element is present in the hash table

bool hashADT::search(int d)
{

    int key = d % 7;

    if (arr[key].search(d))
        return true;

    return false;
}

// Returns true if the element is present in the linked list

bool linkedlist::search(int d)
{

    if (head == nullptr)
        return false;

    node *ptr = head;

    while (ptr != nullptr)
    {

        if (ptr->data == d)
            return true;

        ptr = ptr->next;
    }

    return false;
}