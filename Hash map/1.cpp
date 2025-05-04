#include <iostream>

using namespace std;

class hashADT
{

private:
    int size = 7;

    int arr[7] = {-1, -1, -1, -1, -1, -1, -1};

public:
    // functions

    void insert(int);

    void display();

    void del(int);

    bool search(int);
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

// Inserts the given element using linear probing

void hashADT::insert(int d)
{

    int key = d % size;

    int turns = 0;

    while (arr[key] != -1 && turns < 8)
    {

        key = (key + 1) % size;

        turns++;
    }

    if (arr[key] != -1)
    {

        cout << "Array is filled\n";

        return;
    }

    arr[key] = d;
}

// Displays the hash

void hashADT::display()
{

    for (int i = 0; i < size; i++)
    {

        cout << arr[i] << " ";
    }

    cout << endl;
}

// Deletes the given element in the hash

void hashADT::del(int d)
{

    int key = d % size;

    int turns = 0;

    while (arr[key] != d && turns < 8)
    {

        key = (key + 1) % size;

        turns++;
    }

    if (arr[key] != d)
    {

        cout << "Element not present\n";

        return;
    }

    arr[key] = -1;
}

// Returns true if the element is present in the hashtable else false

bool hashADT::search(int d)
{

    int key = d % size;

    int turns = 0;

    while (arr[key] != d && turns < 8)
    {

        key = (key + 1) % size;

        turns++;
    }

    if (arr[key] == d)
    {

        return true;
    }

    return false;
}