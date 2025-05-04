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
    linkedlist()
    {

        head = NULL;
    }

    void insertBeg(int);

    void insertEnd(int);

    void insertPos(int, int); // index , value

    int deleteBeg();

    int deleteEnd();

    int deletePos(int);

    int search(int);

    void Display();

    void displayRev();

    void swap(int, int); // indexes of the two elements which has to be swapped

    void reverseLink();
};

int main()
{

    linkedlist mylist;

    int inp = 0, value = 0, index = 0;

    while (1)
    {

        cout << "1.Insert at beginning 2.Insert at End 3.Insert at a position\n\n4.Delete beginning 5.Delete end 6.Delete at a position 7.Search\n\n8.Display reverse 9.Reverse link 10.Display 11.Exit\n\nEnter choice: ";

        cin >> inp;

        switch (inp)
        {

        case 1:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist.insertBeg(value);

            break;

        case 2:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist.insertEnd(value);

            break;

        case 3:

            cout << "Enter value to be inserted : ";

            cin >> value;

            cout << "Enter index : ";

            cin >> index;

            mylist.insertPos(index, value);

            break;

        case 4:

            mylist.deleteBeg();

            break;

        case 5:

            mylist.deleteEnd();

            break;

        case 6:

            cout << "Enter index : ";

            cin >> index;

            mylist.deletePos(index);

            break;

        case 7:

            cout << "Enter element to search : ";

            cin >> value;

            index = mylist.search(value);

            cout << "\nThe element was found at index " << index << endl;

            break;

        case 8:

            mylist.displayRev();

            break;

        case 9:

            mylist.reverseLink();

            break;

        case 10:

            mylist.Display();

            break;

        case 11:

            cout << "Exiting .. ";

            return 0;

            break;
        }
    }
}

// Inserts given value at the starting of the list

void linkedlist ::insertBeg(int num)
{ // inserts given value at the starting of the list

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = num;

    newnode->next = NULL;

    if (head == NULL)
    {

        head = newnode;
    }

    else
    {

        newnode->next = head;

        head = newnode;
    }
}

// Inserts given value at the end of the list

void linkedlist ::insertEnd(int num)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = num;

    newnode->next = NULL;

    if (head == NULL)
    {

        head = newnode;
    }

    else
    {

        struct node *curr = head;

        while (curr->next != NULL)
        {

            cout << curr->data << " ";

            curr = curr->next;
        }

        curr->next = newnode;
    }
}

// Inserts given num element at the given index value of the list

void linkedlist::insertPos(int index, int num)
{

    if (index < 0)
    {

        cout << "Invalid index" << endl;
    }

    else if (index == 0)
    {

        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = num;

        newnode->next = NULL;

        newnode->next = head;

        head = newnode;
    }

    else
    {

        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        newnode->data = num;

        newnode->next = NULL;

        struct node *curr = head;

        for (int i = 0; i < index - 1; i++)
        {

            curr = curr->next;

            if (curr == NULL)
            {

                cout << "Invalid index\n";

                return;
            }
        }

        newnode->next = curr->next;

        curr->next = newnode;
    }
}

// Displays the elements of the list

void linkedlist::Display()
{

    if (head == NULL)
    {

        cout << "The list is empty. \n";
    }

    else
    {

        cout << "list: ";

        struct node *curr = head;

        while (curr != NULL)
        {

            cout << curr->data << " ";

            curr = curr->next;
        }

        cout << endl;
    }
}

// Deletes the first element of the list

int linkedlist::deleteBeg()
{

    if (head == NULL)
    {

        cout << "The list is empty . \n";

        return -1;
    }

    else
    {

        int tempdata = head->data;

        head = head->next;

        return tempdata;
    }
}

// Deletes the last element of the list

int linkedlist::deleteEnd()
{

    if (head == NULL)
    {

        cout << "The list is empty . \n";

        return -1;
    }

    else
    {

        int tempdata = 0;

        struct node *curr = head;

        if (head->next == NULL)
        {

            tempdata = head->data;

            head = NULL;

            return tempdata;
        }

        else
        {

            while (curr->next->next != NULL)
            {

                curr = curr->next;
            }

            int tempdata = curr->next->data;

            curr->next = curr->next->next;

            return tempdata;
        }
    }
}

// Deletes the element at the given index of the list

int linkedlist::deletePos(int index)
{

    if (head == NULL)
    {

        cout << "The list is empty . \n";

        return -1;
    }

    else if (index == 0)
    {

        int tempdata = head->data;

        head = head->next;

        return tempdata;
    }

    else
    {

        int tempdata = 0;

        struct node *curr = head;

        if (curr->next == NULL)
        {

            cout << "Invalid index\n";

            return -1;
        }

        for (int i = 0; i < index - 1; i++)
        {

            if (curr->next == NULL)
            {

                cout << "Invalid index\n";
            }

            curr = curr->next;
        }

        tempdata = curr->next->data;

        curr->next = curr->next->next;

        return tempdata;
    }
}

// Returns index of the num element in the list

int linkedlist::search(int num)
{

    if (head == NULL)
    {

        cout << "The list is empty . \n";

        return -1;
    }

    else
    {

        int count = 0;

        struct node *curr = head;

        while (curr != NULL)
        {

            if (curr->data == num)
            {

                return count;
            }

            count++;

            curr = curr->next;
        }

        return -1;
    }
}

// Displays the elements of the list in reverse order

void linkedlist::displayRev()
{

    if (head == NULL)
    {

        cout << "The list is empty \n";
    }

    else
    {

        cout << "list: ";

        struct node *curr = head;

        int size = 0;

        while (curr != NULL)
        {

            size++;

            curr = curr->next;
        }

        for (int i = 0; i < size; i++)
        {

            int ind = size - 1 - i;

            curr = head;

            for (int j = 0; j < ind; j++)
            {

                curr = curr->next;
            }

            cout << curr->data << " ";
        }

        cout << endl;
    }
}

// Reverses the elements in a list

void linkedlist ::reverseLink()
{

    if (head == NULL)
    {

        cout << "The list is empty \n";
    }

    else
    {

        struct node *curr = head;

        int size = 0;

        while (curr != NULL)
        {

            size++;

            curr = curr->next;
        }

        int mid = size / 2;

        for (int i = 0; i < mid; i++)
        {

            int j = size - 1 - i;

            this->swap(i, j);
        }
    }
}

// Swap elements are index i and j

void linkedlist::swap(int a, int b)
{

    struct node *ptr1 = head;

    struct node *ptr2 = head;

    for (int i = 0; i < a; i++)
    {

        ptr1 = ptr1->next;
    }

    for (int i = 0; i < b; i++)
    {

        ptr2 = ptr2->next;
    }

    int temp = ptr1->data;

    ptr1->data = ptr2->data;

    ptr2->data = temp;
}