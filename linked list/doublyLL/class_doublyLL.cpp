#include <iostream>
using namespace std;

class doublyll{
    private : 
    struct node {
        int data ;
        struct node* next;
        struct node* prev;
    }*head,*tail;

    public:
    doublyll(){
        head = NULL;
        tail = NULL;
    }
    void insertbeg(int);
    void insertend(int);
    int deletebeg();
    int deleteend();
    void display();

};

int main(){

    doublyll mylist ; 
    mylist.insertbeg(7);
    mylist.insertbeg(3);
    mylist.insertbeg(1);
    mylist.insertend(10);
    mylist.deletebeg();
    mylist.deleteend();
    mylist.deleteend();
    mylist.deleteend();
    mylist.deleteend();
    mylist.display();

    return 0 ; 
}

void doublyll::insertbeg(int num){
    struct node* newnode = (node*)malloc(sizeof(struct node));
    newnode -> data = num ;
    newnode->next = NULL;
    newnode->prev = NULL;

    if((head == NULL)&&(tail == NULL) ){
        head= newnode;
        tail=newnode;
        return;

    }
    else{
        newnode->next = head; 
        head->prev = newnode;
        newnode->prev = NULL;
        // tail->next = NULL;

         
        head = newnode ;
    }
} 

void doublyll::display(){
    if((head == NULL)&&(tail == NULL) ){
        cout<<"The list is empty"<<endl;
        return;
    }
    else{
        struct node* curr = head ;
        cout<<"Forward progress: "<<endl;
        while(curr !=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;

        curr = tail ;
        cout<<"Backward progress: "<<endl;
        while(curr !=NULL){
            cout<<curr->data<<" ";
            curr = curr->prev;
        }
        cout<<endl;
    }
}

void doublyll::insertend(int num){
    struct node* newnode = new node();
    newnode->next = NULL;
    
    newnode->prev = NULL;
    newnode->data = num;

    tail->next = newnode;
    newnode->prev = tail;
    tail=newnode;
}
int doublyll::deletebeg(){ // check
    if (head==NULL|| tail==NULL){
        cout<<"The list is empty\n";
        return -1;
    }
    int nodedata = head->data;
    head = head->next;
    head->prev= NULL;
    return nodedata;
}

int doublyll::deleteend(){
    if (head==NULL|| tail == NULL){ // check 
        cout<<"The list is empty\n";
        return -1;
    }
    int nodedata = tail->data;
    tail = tail->prev  ;
    tail->next=NULL;
    return nodedata;

}