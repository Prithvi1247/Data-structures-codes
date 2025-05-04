#include <iostream>
using namespace std;

class listADT{
    private:
    char arr[5];
    int top;

    public:
    listADT(){top = -1;};
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

//Push an element at the top of the stack
void listADT ::push(char value){
    if(top==4){
        cout<<"List Full!"<<endl;
        return;
    }
    else{
        top++;
        arr[top]=value;
        return;
    }
}

// Peek at the element at the top of the stack
char listADT::peek(){
    if ( top==-1){
        cout<<"Empty List!"<<endl;
        return -1;
    }
    else{
        cout<<"Top element: "<<arr[top]<<endl;
        return arr[top];
    }
}

// Delete the element at the top of the stack
char listADT::pop(){
    if ( top==-1){
        cout<<"Empty List!"<<endl;
        return -1;
    }
    else{
        char relem = arr[top];
        top--;
        return relem;
    }
}