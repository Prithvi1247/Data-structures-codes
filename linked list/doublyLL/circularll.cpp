#include <iostream>
using namespace std;

class listADT
{
private:
    struct node
    {
        int data;
        node *next;
    } *head;

public:
    listADT()
    {
        head = nullptr;
    }
    // list the functions here
    void insertbeg(int);
    int deletebeg();
    int deleteend();
    void insertend(int);
    void insertpos(int, int);
    int deletepos(int);
    int search(int);

    void display();
};

int main()
{
    listADT mylist;

    int inp = 0, value = 0, index = 0;

    while (1)
    {
        cout << "------------------------------------------";
        cout << "\n\n1.Insert at beginning\n2.Insert at End\n3.Insert at a position\n4.Delete beginning\n5.Delete end\n6.Delete at a position\n7.Search\n8.Display\n9.Exit\n\nEnter choice: ";
        cin >> inp;
        cout << endl;
        switch (inp)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            mylist.insertbeg(value);
            break;
        case 2:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            mylist.insertend(value);
            break;
        case 3:
            cout << "Enter the value to be inserted: ";
            cin >> value;
            cout << "Enter the position to be inserted: ";
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
            cout << "Enter the position to be deleted: ";
            cin >> index;
            mylist.deletepos(index);
            break;
        case 7:
            cout << "Enter the value to be searched: ";
            cin >> value;
            index = mylist.search(value);
            if (index == -1)
            {
                cout << "Element not found" << endl;
            }
            cout << "element found at index " << index << endl;
            break;
        case 8:
            mylist.display();
            break;
        case 9:
            return 0;
        }
    }
}

void listADT::insertbeg(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->data = num;

    if (head == nullptr)
    {
        head = newnode;
        head->next = head;
    }
    else
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        newnode->next = head;
        head = newnode;
        curr->next = newnode;
    }
}

void listADT ::display()
{
    if (head == nullptr)
    {
        cout << "The list is empty." << endl;
        return;
    }
    else
    {
        cout << "List: ";
        node *curr = head;
        do
        {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
}

void listADT::insertend(int num)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->data = num;
    if (head == nullptr)
    {
        head = newnode;
        newnode->next = head;
    }
    node *curr = head;
    while (curr->next != head)
    {
        curr = curr->next;
    }
    newnode->next = head;
    curr->next = newnode;
}

void listADT::insertpos(int num, int ind)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->data = num;
    if ((head == nullptr && ind > 0) || (ind < 0))
    {
        cout << "INVALID !" << endl;
    }
    if (ind == 0)
    {
        node *curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        newnode->next = head;
        curr->next = newnode;
        head = newnode;
    }
    else
    {
        node *curr = head;
        for (int i = 0; i < ind - 1; i++)
        {
            curr = curr->next;
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

int listADT::deletebeg()
{
    if(head == nullptr){
        cout<<"Empty list!"<<endl;
        return -1;
    }
    else{
        int tempdata = 0;
        tempdata = head->data;
        if(head->next == head){
            delete head;
            head = nullptr;
            return tempdata;
        }
        node* curr = head; 
        while(curr->next!=head){
            curr = curr->next;
        }
        curr->next=head->next;
        head = head->next;
        return tempdata;
    }
}

int listADT::deleteend(){
    if(head == nullptr){
        cout<<"Empty list!"<<endl;
        return -1;
    }
    else{
        int tempdata=0;
        if(head->next == head){
            tempdata=head->data;
            delete head;
            head = nullptr;
            return tempdata;
        }
        else{
            node* curr =head;
            while(curr->next->next!=head){
                curr  = curr->next;
            }
            node* removeme = curr ->next;
            tempdata = removeme->data;
            curr->next= curr->next->next;
            delete removeme;
            return tempdata;
        }
    }
}

int listADT::deletepos(int ind){
    if(head == nullptr){
        cout<<"Empty list!"<<endl;
        return -1;
    }
    if (ind==0  ){
        
        int tempdata = head->data;
        if(head->next == head){
            delete head ; 
            head = nullptr;
            return tempdata;

        }
        node* curr = head;
        while(curr->next!=head){
            curr=curr->next;
        }
        
        head=head->next;
        curr->next=head;
        return tempdata;
    }
    else{
        node* curr = head ;
        for (int i = 0; i < ind-1; i++)
        {
            curr = curr->next;
        }
        int tempdata = curr->next->data;
        curr->next = curr->next->next;
        return tempdata;
        
    }
}

int listADT::search(int num){
    node* curr=head;
    int ind = 0 ; 
    do{
        if (curr->data==num){
            return ind;
        }
        ind++;
        curr = curr->next;
    }while(curr!=head);
    return -1;
}