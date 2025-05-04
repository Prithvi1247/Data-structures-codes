#include <iostream>

using namespace std;

class queueADT
{

private:
    int size = 5;

    int arr[5];

    int rear;

    int front;

public:
    queueADT()
    {

        rear = -1;

        front = -1;
    }

    void Enqueue(int);

    void display(int);

    void Dequeue();

    int peak();
};

int main()
{

    queueADT myqueue;

    int temp = -1;

    while (true)
    {

        cout << "Queue ADT\n1.Enqueue\n2.Dequeue\n3.peak\n4.Exit\nEnter choice: ";

        int ch;

        cin >> ch;

        switch (ch)
        {

        case 1:

            cout << "Enter value :";

            int val;

            cin >> val;

            myqueue.Enqueue(val);

            // myqueue.display();

            break;

        case 2:

            myqueue.Dequeue();

            // myqueue.display();

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

    if (rear == -1 && front == -1)
    {
        rear++;
        front++;
        arr[rear] = value;
        display(1);
    }

    else
    {
        int cap = front - rear + 1;
        if ((front + 1) % size == rear)
        {
            cout << "Maximum capacity! \n";
            return;
        }

        for (int i = front; i >= rear; i--)
        {
            int ind = (i + 1) % size;
            arr[ind] = arr[i];
        }

        arr[rear] = value;
        front = (front + 1) % size;
        cap++;
        display(cap);
    }
}

// Displays all the elements of the queue

void queueADT::display(int cap)
{

    cout << "Queue: ";

    for (int i = rear; i < rear+cap; i++)
    {

        cout << arr[i%size] << " ";
    }

    cout << endl;
}

// Deletes element at the beginning

void queueADT::Dequeue()
{

    int cap = front - rear + 1;

    if (front == 0)
    {

        front = rear + cap - 2;
    }

    front = (front - 1) % size;
}

// Returns the element at the front index of the queue

int queueADT::peak()
{

    return arr[front];
}