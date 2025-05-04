#include <iostream>
using namespace std;

class linkedlist{
    private:
    struct node{
        int data;
        struct node* next;
    }*head;

    public:
    linkedlist(){
        this->head = NULL;
    }

    void insertbeg(int);
    int deletepos(int);
    void display();
};

int main(){
    linkedlist mylist;
    mylist.insertbeg(1);
    mylist.insertbeg(2);
    mylist.insertbeg(3);
    mylist.insertbeg(4);
    mylist.display();

    mylist.deletepos(4);
    mylist.display();

    return 0;
}

void linkedlist :: insertbeg(int num){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=num;
    newnode->next=NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next= head;
        head = newnode;
    }

}
void linkedlist :: display(){
    struct node* curr = head ;
    cout<<"this list : ";
    while (curr!=NULL)
    {
        cout<<curr->data<<" ";
        curr = curr->next;

    }
    cout<<endl;

    
}
int linkedlist :: deletepos(int index){
    if (index<0){
        cout<<"invalid index"<<endl;
    }
    else if (index == 0){
        head = head->next;
    }
    else{
        struct node * curr = head;
        for (int i = 0; i < index-1; i++)
        {
            if (curr->next == NULL){
                cout<<"invalid index"<<endl;
                return -1; 
            }
            curr = curr->next;
        }
        curr->next = curr->next->next;
    }
}