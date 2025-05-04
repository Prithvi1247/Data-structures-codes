#include <iostream>
using namespace std;

int solve(int );


class ListAdt{
    private: 
    struct node {
        int data;
        node* next;
    }*head;

    public:
    ListAdt(){head = nullptr;}

    //functions

    void append(int );
    int isUnique(int );
    int deletebeg();
};

int main(){

    cout<<"Enter no of testcases: ";
    int tc;cin>>tc;

    while(tc--){
        cout<<"Enter no of elements: ";
        int n;cin>>n;
        int ans = solve(n);
        cout<<"Answer : "<<ans<<endl;
    }
    return 0;
}

int solve(int n){
    ListAdt ll ;
    // cout<<"inside solve function "<<endl;
    for (int i = 0; i < n; i++){
        int d;
        cin>>d;
        
        ll.append(d);
        // cout<<"appended "<<d <<" at index "<<i <<endl;
    }
    int ptr = 0 ; 
    int sizeArr = n;
    int remove = 0;
    while(!(ll.isUnique(n))){
        ll.deletebeg();
        remove++;
    }
    return remove;
}


int ListAdt::isUnique(int n){

    if (head == nullptr || head->next == nullptr){
        return 1;
    }
    node* ptr = head;
    while(ptr->next != nullptr){
        node* temp = ptr->next;
        while(temp != nullptr){
            if (ptr->data == temp->data){
                return 0;
            }
            else{
                temp = temp->next;
            }
        }
        ptr = ptr->next;
    }
    return 1;
}

void ListAdt::append(int d){
    node* newnode = new node();
    newnode->data = d;
    newnode->next=nullptr;

    // cout<<"inside append"<<endl;
    if(head == nullptr){
        // cout<<"inside head is null"<<endl;
        head = newnode;
        // cout<<"made it"<<endl;
        return;
    }
    node* ptr = head;
    while(ptr->next!=nullptr){
        ptr=ptr->next;
    }
    ptr->next=newnode;
    

}

int ListAdt::deletebeg(){
    int data = head->data;
    node* temp  = head;
    head = head->next;
    // delete temp;
    return data;
}