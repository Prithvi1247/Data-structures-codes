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

char listADT::pop(){

    if(head == nullptr){
        // cout<<"List is Empty!"<<endl;
        return '`';
    }
    else{
        char relem = head->data;
        node* delme = head; 
        head = head->next;
        delete delme;
        return relem;
    }
}

char listADT::peek(){

    if(head == nullptr){
        // cout<<"List is Empty!"<<endl;
        return '`';
    }
    else{
        // cout<<"Top element: "<<head->data<<endl;
        return head->data;
    }
}