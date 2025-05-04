#include <iostream>
using namespace std;

class linkedlist
{

private:
    struct node
    {

        int data;

        struct node *next;

    } *head;

    node *gethead();

public:
    linkedlist()
    {

        head = NULL;
    }

    void display();

    void insertAsc(int);

    void merge(linkedlist, linkedlist);
};

void linkedlist::insertAsc(int num)
{

    struct node *newnode = (struct node *)malloc(sizeof(struct node));

    newnode->data = num;

    newnode->next = NULL;

    if (head == NULL)
    {

        head = newnode;
    }

    else if (num <= head->data)
    {

        newnode->next = head;

        head = newnode;
    }

    else
    {

        struct node *curr = head;

        while (curr->next != NULL)
        {

            if ((curr->data < num) && (curr->next->data >= num))
            {

                newnode->next = curr->next;

                curr->next = newnode;

                return;
            }

            curr = curr->next;
        }

        curr->next = newnode;
    }
}

void linkedlist::display()
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

linkedlist::node *linkedlist::gethead()
{

    return head;
}

void linkedlist ::merge(linkedlist mylist1, linkedlist mylist2)
{

    struct node *head1 = mylist1.gethead();

    struct node *head2 = mylist2.gethead();

    struct node *curr = head;

    while ((head1 != NULL) || (head2 != NULL))
    {

        struct node *newnode = (struct node *)malloc(sizeof(struct node));

        newnode->next = NULL;

        if ((head1 != NULL) && (head2 == NULL || head2->data >= head1->data))
        {

            newnode->data = head1->data;

            head1 = head1->next;
        }

        else
        {

            newnode->data = head2->data;

            head2 = head2->next;
        }

        if (head == NULL)
        {

            head = newnode;

            curr = newnode;
        }

        else
        {

            curr->next = newnode;

            curr = newnode;
        }
    }
}