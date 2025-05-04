#include <iostream>
using namespace std;

class heap{
    private:
    int arr[100];
    int size = 0;
    public:
    heap(){
        size = 0 ; 
    }

    // Functions

    void insert(int );
    void print();
};

int main(){

    heap myh;
    while (1)
    {
        int ch;
        cout<<"1.Insert\n2.Delete\n3.Display\n4.Search\n5.Sort\n6.Exit\nEnter choice: ";
        cin>>ch;

        switch (ch)
        {
        case 1:
            int val;
            cout<<"Enter value: "<<endl;
            cin>>val;
            myh.insert(val);

            break;
        case 3:
            myh.print();
            break;
        default:
            break;
        }
    }
    

    return 0;
}

void heap::insert(int data){
    size++;
    arr[size]=data;
    int index = size;
    while (index != 1){
        if (arr[index/2] < arr[index]){
            int temp = arr[index/2];
            arr[index/2]=arr[index];
            arr[index]=temp;

            index = index/2;
        }
        else{return;}
    }
}

void heap::print(){
    for (int  i = 1; i < size+1  ; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}