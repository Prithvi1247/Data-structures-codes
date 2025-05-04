#include <iostream>

using namespace std;

class queueADT
{

private:
    struct node
    {

        int data;

        node *next;

    } *head, *tail;

public:
    queueADT()
    {

        head = nullptr;

        tail = nullptr;
    }

    void Enqueue(int);

    void display();

    int Dequeue();

    int peak();
};

int main()
{

    queueADT myqueue;

    int temp = -1;

    while (true)
    {
        cout<<"------------------------------------------"<<endl;
        cout << "Queue ADT\n1.Enqueue\n2.Dequeue\n3.peak\n4.Exit\nEnter choice: ";

        int ch;

        cin >> ch;
        cout<<endl;
        switch (ch)
        {

        case 1:

            cout << "Enter value :";

            int val;

            cin >> val;

            myqueue.Enqueue(val);

            myqueue.display();

            break;

        case 2:

            temp = myqueue.Dequeue();

            if (temp != -1)
            {

                myqueue.display();
            }

            break;

        case 3:

            temp = myqueue.peak();

            cout << temp << endl;

            break;

        case 4:

            cout << "Exiting.\n";

            return 0;

        default:

            cout << "Invalid input!\n ";
        }
    }
}

// Inserts element at the end of the queue

void queueADT::Enqueue(int value)
{

    node *newnode = new node();

    newnode->data = value;

    newnode->next = nullptr;

    if (head == nullptr && tail == nullptr)
    {

        head = newnode;

        tail = newnode;
    }

    else
    {

        tail->next = newnode;

        tail = newnode;
    }
}

// Displays all the elements of the queue

void queueADT::display()
{

    cout << "Queue: ";

    node *ptr = head;

    while (ptr != nullptr)
    {

        cout << ptr->data << " ";

        ptr = ptr->next;
    }

    cout << endl;
}

// Returns the element at the front index of the queue

int queueADT::peak()
{

    if (head == nullptr && tail == nullptr)
    {

        cout << "Empty Queue! " << endl;

        return -1;
    }

    return head->data;
}

// Deletes element at the beginning

int queueADT::Dequeue()
{

    if (head == nullptr && tail == nullptr)
    {

        cout << "Empty Queue! " << endl;

        return -1;
    }

    int temp = head->data;

    if (head == tail)
    {

        head = nullptr;

        tail = nullptr;
    }

    else
    {

        head = head->next;
    }

    return temp;
}