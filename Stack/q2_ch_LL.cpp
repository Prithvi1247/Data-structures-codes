#include <iostream>
using namespace std;

class listADT{
    private:
    struct node{
        char data;
        node* next;
    }*head;

    public:
    listADT(){head = nullptr;};
    void push(char);
    char peek();
    char pop();
};

int main(){
    listADT mylist;

    int inp = 0, index = 0;
    char value;
    while (1)
    {

        cout<<"------------------------------------------";
        cout << "\n\n1. Push\n2. Pop\n3. Peek\n4. Exit\n\nEnter choice: ";
        cin >> inp;
        cout<<endl;

        switch (inp)
        {
        case 1 : 
            cout<<"Enter character element : ";
            cin>>value;
            mylist.push(value);
            break;
        case 2 : 
            mylist.pop();
            break;
        case 3 : 
            mylist.peek();
            break;
        case 4 : 
            cout<<"Exiting..";
            return 0;
            break;
        default:
            cout<<"Invalid Input! "<<endl;
        }
    }
}

// Push an element at the top of the stack
void listADT::push(char value){
    node* newnode= new node();
    newnode->data=value;
    newnode->next=nullptr;

    if(head == nullptr){
        head = newnode;
    }
    else{
        newnode->next=head;
        head = newnode;
    }
}
// Delete the element at the top of the stack
char listADT::pop(){

    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return -1;
    }
    else{
        char relem = head->data;
        node* delme = head; 
        head = head->next;
        delete delme;
        return relem;
    }
}
// Peek at the element at the top of the stack
char listADT::peek(){

    if(head == nullptr){
        cout<<"List is Empty!"<<endl;
        return -1;
    }
    else{
        cout<<"Top element: "<<head->data<<endl;
        return head->data;
    }
}

