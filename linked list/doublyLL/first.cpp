#include <iostream>
using namespace std;

class listADT
{
private:
    struct node
    {
        int data;
        node *next;
        node *prev;
    } *head, *tail;

public:
    listADT()
    {
        head = nullptr;
        tail = nullptr;
    }
    // list the function definitions here..
    void insertbeg(int);
    int deletebeg();
    void insertend(int);
    int deleteend();
    void insertpos(int,int);
    int deletepos(int);
    int search(int);
    void display(); // shd display both forward and backward order
};

int main()
{

    listADT mylist;

    int inp = 0, value = 0, index = 0;

    while (1)
    {
        cout<<"------------------------------------------";
        cout << "\n\n1.Insert at beginning\n2.Insert at End\n3.Insert at a position\n4.Delete beginning\n5.Delete end\n6.Delete at a position\n7.Search\n8.Display\n9.Exit\n\nEnter choice: ";
        cin >> inp;
        cout<<endl;
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
            mylist.insertpos(value , index);
            break;
        case 4 :
            mylist.deletebeg();
            break;
        case 5 :
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
            if (index == -1){
                cout<<"Element not found"<<endl;
            }
            cout<<"element found at index "<<index<<endl;
            break;
        case 8:
            mylist.display();
            break;
        case 9 :
            return 0;
        }
    }

    
}

void listADT::insertbeg(int val)
{
    node *newnode = new node();
    newnode->data = val;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (head == nullptr)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    else
    {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void listADT::display()
{
    if (head == nullptr)
    {
        cout << "The list is empty.. " << endl;
        return;
    }
    node *curr = head;
    cout << "Forward order: " << endl;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    curr = tail;
    cout << "\nBackward order: " << endl;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->prev;
    }
    cout << endl;
}

void listADT::insertend(int val)
{
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->data = val;

    if (head == nullptr)
    {
        head =newnode;
        tail =newnode;
        return;
    }

    else{
        tail->next = newnode;
        newnode->prev= tail;
        tail=newnode;
        return;
    }
}

void listADT :: insertpos(int val , int ind){
    node *newnode = new node();
    newnode->next = nullptr;
    newnode->prev = nullptr;
    newnode->data = val;

    if (head == nullptr)
    {
        head =newnode;
        tail =newnode;
        return;
    }

    
    else{
        node* curr = head; 
        for (int i = 0; i < ind-1; i++)
        {
            curr = curr->next;
        }
        if(curr->prev == NULL){
            newnode->next=curr;
            curr->prev= newnode;
            head = newnode;
            return;
        }
        newnode->next = curr->next;
        curr->next=newnode;
        newnode->prev = curr;
        if(newnode->next == NULL){
            tail = newnode;
        }
        return;   
    }
}

int listADT::deletebeg(){
    int contained_data = -1  ;
    if (head  == nullptr){
        cout << "The list is empty.. " << endl;
        return contained_data;
    }
    else{
        contained_data=head->data;
        node* deletethis = head;
        head = head->next;
        head->prev = NULL;
        delete deletethis;
        return contained_data;
    }
}
int listADT :: deleteend(){
    int contained_data = -1  ;
    if (head  == nullptr){
        cout << "The list is empty.. " << endl;
        return contained_data;
    }
    node* curr = tail; 
    if(tail->prev == nullptr){
        contained_data=tail->data;
        tail = nullptr;
        head = nullptr;
    }
    else{
        curr = tail->prev;
        contained_data=tail->data;
        curr->next=nullptr;
        tail=curr;
    }
    return contained_data;
}

int listADT::deletepos(int ind){
    int contained_data = -1  ;
    if (head  == nullptr){
        cout << "The list is empty.. " << endl;
        return contained_data;
    }

    if(ind == 0 ){
        node* removeme =head;
        contained_data = head->data;
        head  = head->next;
        head->prev=nullptr;
        delete removeme;
    }
    else{
        node* curr = head;
        for (int i = 0; i < ind-1; i++)
        {
            curr = curr->next;
        }
        
        contained_data  = curr->next->data;
        node* removeme =curr->next;
        curr->next = curr->next->next;
        if(curr->next == nullptr){
            tail = tail->prev;
            delete removeme;
            return contained_data;

        }
        curr = curr->next;
        curr->prev = curr->prev->prev;
        delete removeme;
        return contained_data;
    }
}

int listADT::search(int val){
    int ind = 0;
    if (head  == nullptr){
        cout << "The list is empty.. " << endl;
        return -1;
    }
    node* curr = head; 
    while(curr!=nullptr){
        if (curr->data==val){
            return ind;
        }
        ind++;
        curr = curr->next;
    }
    return -1;
}