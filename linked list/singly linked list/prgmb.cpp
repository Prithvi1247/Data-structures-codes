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

    struct node *gethead();

public:
    linkedlist()
    {
        this->head = NULL;
    }
    void insertend(int);
    void display();
    int insertAscending(int);
    linkedlist merge(linkedlist,linkedlist);
};

int main()
{
    linkedlist mylist1, mylist2;
    linkedlist mylist3 ;
    int inp = 0, val = 0, lst = 0;
    while (inp != 4)
    {
        cout << "1.Insert ascending\n2.Merge\n3.Display\n4.Exit\n5.insert at end\n6.display merged list" << endl;
        cin >> inp;

        
        if (inp==2){
            mylist3 = mylist3.merge(mylist1,mylist2);
            mylist3.display();
            continue;
        }
        cout << "Enter list(1/2) : ";
        cin >> lst;
        if (lst == 1)
        {
            if (inp == 5)
            {
                cout << "Enter number : ";
                cin >> val;

                mylist1.insertend(val);
            }
            else if (inp == 3)
            {

                mylist1.display();
            }
            else if (inp == 1)
            {
                cout << "Enter number : ";
                cin >> val;
                mylist1.insertAscending(val);
            }
        }
        if (lst == 2)
        {
            if (inp == 5)
            {
                cout << "Enter number : ";
                cin >> val;

                mylist2.insertend(val);
            }
            else if (inp == 3)
            {

                mylist2.display();
            }
            else if (inp == 1)
            {
                cout << "Enter number : ";
                cin >> val;
                mylist2.insertAscending(val);
            }
        }
    }
    return 0;
}

linkedlist::node* linkedlist ::gethead()
{
    return (head);
}

void linkedlist ::insertend(int num)
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
            curr = curr->next;
        }

        curr->next = newnode;
    }
}

void linkedlist ::display()
{
    if (head == NULL)
    {
        cout << "the list is empty" << endl;
    }
    else
    {
        struct node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
        cout << endl;
    }
}

int linkedlist::insertAscending(int num)
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
            if ((curr->data < num) & (curr->next->data >= num))
            {
                newnode->next = curr->next;
                curr->next = newnode;
                return 1;
            }
            curr = curr->next;
        }
        curr->next = newnode;
        return 1;
    }
}


linkedlist linkedlist::merge(linkedlist mylist1 ,linkedlist mylist2){
    struct node* head1 = mylist1.gethead();
    struct node* head2 = mylist2.gethead();

    struct node* curr = NULL;

    linkedlist mergedlist;
    if (head1 == NULL) return mylist2;
    if (head2 == NULL) return mylist1;

    while(head1!=NULL || head2!=NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));

        if (head1!=NULL && (head2 == NULL || head1->data <= head2->data)){
            newnode->data = head1->data;
            head1 = head1->next;
        }
        else{
            newnode->data = head2->data;
            head2= head2->next;
        }

        newnode->next = NULL;
        if (mergedlist.head==NULL){
            mergedlist.head=newnode;
            curr= newnode;
        }
        else{
            curr->next = newnode;
            curr=newnode;
        }
    }
    return mergedlist;
}