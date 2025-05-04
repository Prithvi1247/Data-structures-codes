#include <iostream>
using namespace std;

class linkedlist {
    private:
        struct node
        {
            int data;
            struct node *next;
        } *head;

    public:
        linkedlist()
        {
            head = NULL;
        }
        void insertAtBeg(int);
        void insertAtEnd(int);
        void insertAtPstn(int,int); // int value , int position
        void deleteAtBeg(); 
        void deleteAtEnd(); 
        void deleteAtPstn(int); // integer index 
        int search(int); // returns index of num in list
        void display();
        void displayReverse();
        void reverseLink();
        int swap(int,int);
        void displayreverserec(int);
};

int main()
{
    linkedlist mylist;
    mylist.insertAtEnd(17);
    mylist.insertAtEnd(18);
    // mylist.insertAtEnd(17);
    mylist.insertAtEnd(18);
    mylist.insertAtEnd(19);
    mylist.insertAtPstn(1,2);
    // mylist.deleteAtBeg();
    // mylist.deleteAtEnd();
    // mylist.display();
    // mylist.deleteAtPstn(1);
    // int index = mylist.search(1);
    // cout<<"the value of index is "<<index<<endl;
    mylist.display();
    // mylist.displayReverse();
    mylist.reverseLink();
    mylist.display();
    mylist.displayreverserec(0);

    return 0;
}   

void linkedlist :: insertAtBeg(int num){ // function under linkled list class

    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    // struct node* newnode = new struct node;
    newnode->data = num;
    newnode->next = head;
    head = newnode;

}
void linkedlist :: display(){
    cout<<"hi from display"<<endl;
    struct node* curr;
    curr=head;
    if (curr==NULL){
        cout<<"The list is empty.. "<<endl;
    }
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr = curr->next;
    }
    cout<<endl;
}

void linkedlist :: insertAtEnd(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = num ; 
    newnode -> next = NULL;
    struct node* curr = head;

    if (curr == NULL){
        head=newnode;
        return;
    }
    while( (curr->next)!=NULL){
        curr=curr->next;
    }
    curr->next=newnode;
    return;

}

void linkedlist :: insertAtPstn(int num , int index) { 
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    newnode->next=NULL;

    if (index == 0){
        newnode->next = head;
        head=newnode;
    }
    else{
        struct node* curr = head;
        for (int i = 0; i < index-1; i++)
        {
            curr=curr->next;
            if (curr == NULL){
                cout<<"invalid index passed"<<endl;
                return;
            }
        }
        newnode->next = curr->next;
        curr->next = newnode;
    }
}

void linkedlist :: deleteAtBeg(){
    if (head == NULL ) {
        cout<<"the list is empty"<<endl;
    }
    else{
        head = head->next;
    }
}

void linkedlist :: deleteAtEnd(){
    if (head == NULL ) {
        cout<<"the list is empty"<<endl;
    }
    else if(head->next == NULL){
        head = NULL;
    }
    else{
        struct node* curr = head; 
        
        while((curr->next)->next != NULL )  {
            curr=curr->next;

        }
        curr->next = NULL;
    }
}

void linkedlist :: deleteAtPstn(int index){
    if (index<0){
        cout<<"Invalid index"<<endl; 
    }
    else if (index == 0 ){
        head = head->next;
    }
    else if (index > 0){
        struct node* curr = head;
        for (int i = 0; i < index-1; i++)
        {
            curr = curr->next;
            if (curr == NULL){
                cout<<"index out of range"<<endl;
                return ;
            }
        }
        curr->next=curr->next->next;
    }
}

int linkedlist :: search (int num){
    int count = 0 ; 
    struct node* curr = head; 
    while(curr!= NULL){
        if (curr->data == num){
            return count;
        }
        count++;
        curr=curr->next;
    }
    return -1;
    
    
}

void linkedlist :: displayReverse(){

    if (head == NULL){
        cout<<"The list is empty "<<endl;
    }
    else{
        int size = 0 , ind = 0 ; 
        struct node* curr = head;
        while ( curr != NULL)   {
            size++;
            curr = curr->next;
        }
        struct node* ptr;
        for (int i = 1; i <= size; i++)
        {
            ptr = head;
            ind = size-i;
            for (int j = 0; j < ind; j++)
            {
                ptr = ptr->next;
            }
            cout<<ptr->data<<" ";
            
        }
        
    }
}

void linkedlist :: reverseLink(){
    if (head == NULL){
        cout<<"The list is empty "<<endl;
    }
    else{
        struct node* curr = head;

        int size = 0  ;
        while(curr != NULL){
            curr=curr->next;
            size++;
        }
        
        
        curr = head ;
        int mid = size/2;
        int j;
        for (int i = 0; i < mid; i++)
        {
            j = size-i-1;
            //swap index i and j 
            cout<<i<<" "<<j<<endl;
            int y = this->swap(i,j);
        }
       

    }
}

int linkedlist :: swap(int a , int b ){
    // cout<<"hi from swap"<<endl;
    struct node* ptr1 = head ; 
    struct node* ptr2 = head ; 
   ; 
    for (int i = 0; i < a; i++)
    {
        ptr1=ptr1->next;
    }
    for (int i = 0; i < b; i++)
    {
        ptr2=ptr2->next;
    }
    //swapping data in the two nodes of ath index and bth index
    int temp  = ptr1 ->data;
    ptr1->data = ptr2->data;
    ptr2->data = temp;
    

    // cout<<"swap has ended"<<endl;
    return 1;
}

void linkedlist :: displayreverserec(int first){
    
    if (first == 0 ){

        struct node* curr = head ;
        int size = 0;
        while(curr != NULL){
            size++;
            curr = curr->next;
        }
        first++;
    }
    else{
        cout<<curr->data<<" ";
        
    }


}
