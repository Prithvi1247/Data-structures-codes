#include <iostream>
using namespace std;

class cll
{
private:
    struct node
    {
        int time;
        node *next = nullptr;
    } *head;

public:
    cll() { head = nullptr; }
    void insertAtEnd(int);
    void display();
    int deleteAtBeg();
};

void cll::insertAtEnd(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->time = num;

    if (head == nullptr)
    {
        head = newnode;
        newnode->next = head;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        newnode->next = head;
        curr->next = newnode;
    }
}
void cll::display()
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
    }
    else
    {
        node *curr = head;
        do
        {
            cout << curr->time << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
}

int cll::deleteAtBeg()
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return -1;
    }
    else if (head->next == head)
    {
        int returndata = head->time;
        delete head;
        head = nullptr;
        return returndata;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        node *temp = head;
        int returndata = head->time;
        curr->next = head->next;
        head = head->next;
        delete temp;
        return returndata;
    }
}