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
            tail = NULL;
        }
        void insertAtBeg(int);
        void insertAtEnd(int);
        void display();
};

int main()
{
    linkedlist mylist;
    mylist.insertAtBeg(17);
    mylist.insertAtEnd(18);
    mylist.insertAtEnd(19);
    mylist.display();
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

