#include <iostream>
using namespace std;

class linkedlist{
    private:
    struct node{
        int data;
        node* next;

    }*head;
    public:
    linkedlist(){head =nullptr;}

    //functions

    node* gethead();
    void insertbeg(int);
    void display();
};

class hashadt{
    private:
    int size = 7;
    linkedlist* arr = (linkedlist*)malloc( size * sizeof(linkedlist));

    public:
    // hashadt(){init() ; }
    // void init();
    void insert(int);
    void display();
    void hdelete(int);
    bool hsearch(int);

};

int main(){
    int ch=0;
    hashadt h;
    while(ch!=5){
        cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"Enter value: ";
                int d;
                cin>>d;
                h.insert(d);
                break;
            }
            case 4:{
                h.display();
                break;
            }
            case 2:{
                cout<<"Enter value: ";
                // int d;
                // cin>>d;
                // h.hdelete(d);
                // break;
            }

            case 3:{
                cout<<"Enter value: ";
                // int d;
                // cin>>d;
                // if (h.hsearch(d)){
                //     cout<<"Value found"<<endl;
                // }
                // else{
                //     cout<<"Value not found"<<endl;
                // }
                // break;
            }


            default:
                cout<<"Invalid Input! "<<endl;
        }

        cout<<"--------------------------------------"<<endl;
    }

    return 0;
}

linkedlist::node* linkedlist::gethead(){
    return head;
}

void linkedlist::insertbeg(int d){
    node* newnode = new node();
    newnode->data=d;
    newnode->next=nullptr;

    newnode->next = head;
    head = newnode;
}

void linkedlist::display(){
    node* ptr = head;
    while(ptr!=nullptr){
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
    cout<<""<<endl;
}

void hashadt::display(){
    for (int i = 0; i < size; i++)
    {
        arr[i].display();
        cout<<endl;
    }
    cout<<""<<endl;
    
}

void hashadt::insert(int d){
    int ind = d%size;
    arr[ind].insertbeg(d);

}

// void hashadt::init(){

//     for (int  i = 0; i < size; i++)
//     {   
//         linkedlist l;
//         arr[i] = l.gethead();
//     }
    
// }