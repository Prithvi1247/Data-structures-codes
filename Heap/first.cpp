#include <iostream>
using namespace std;

class heap{  // MAX HEAP
    private:
    int arr[100] ;
    int size = 0 ;

    public : 
    heap(){}
    void insert(int);
    void print();
};

int main(){
    heap myheap;
    myheap.insert(1);
    myheap.insert(2);
    myheap.insert(3);
    myheap.print();

    return 0;
}

void heap::insert(int data){
    size++;

    int index = size;
    arr[index] = data;

    while(index>1){
        if ( arr[index/2] < arr[index]){
            int temp = arr[index/2];
            arr[index/2] = arr[index];
            arr[index] = temp;
            index = index/2;
        }
        else {
            return;
        }
    }
}

void heap::print(){
    for (int i = 1; i < size+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    
}