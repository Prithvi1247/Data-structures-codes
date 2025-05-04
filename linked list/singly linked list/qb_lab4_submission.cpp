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

int main()
{

    linkedlist mylist1, mylist2, mergedlist;

    int inp = 0, value = 0, index = 0, a = 0;

    while (1)
    {

        cout << "1.Insert ascending in list 1 \n2.Insert ascending in list 2\n3.Merge\n4.Display \n5.Exit \nEnter choice: ";

        cin >> inp;

        switch (inp)
        {

        case 1:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist1.insertAsc(value);

            break;

        case 2:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist2.insertAsc(value);

            break;

        case 3:

            mergedlist.merge(mylist1, mylist2);

            break;

        case 4:

            a = 0;

            cout << "Enter choice of list (1/2/3) : ";

            cin >> a;

            if (a == 1)
            {

                mylist1.display();
            }

            else if (a == 2)
            {

                mylist2.display();
            }

            else if (a == 3)
            {

                mergedlist.display();
            }

            else
            {

                cout << "Invalid input ";
            }

            break;

        case 5:

            cout << "Exiting..\n";

            return 0;

            break;
        }
    }
}

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