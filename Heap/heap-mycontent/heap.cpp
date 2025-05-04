#include <iostream>
#include <vector>
using namespace std;

class heap{
    private:
    int arr[100];
    int size=0;
    public:
    heap(){}
    void display();
    void insert(int); // O (log n)
    int deleteroot();
    void takenodetocrctpstn(int,int);
    void hsort();

};

int main(){

    heap h;
    h.insert(1);
    h.display();
    h.insert(2);
    h.display();
    h.insert(3);
    h.display();
    h.insert(31);
    h.display();
    h.insert(32);
    h.display();
    h.insert(39);
    h.display();
    h.insert(30);
    h.display();
    // h.deleteroot();
    // h.display();
    // h.deleteroot();
    // h.display();
    // h.deleteroot();
    // h.display();
    h.hsort();
    h.display();

    int n ;cout<<"enter n: ";cin>>n;
    vector<int> vect;
    for (int i = 0; i < n; i++)
    {
        int d;
        cin>>d;
        vect.push_back(d);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<vect[i]<<" ";
    }
    cout<<""<<endl;


    
    return 0; 
}

void heap::insert(int elem){
    size++;
    arr[size] = elem;
    int ptr=size;
    int pind = ptr/2;
    while(pind > 0){
        pind = ptr/2;
        if (arr[pind] < arr[ptr]){
            int temp = arr[pind];
            arr[pind]=arr[ptr];
            arr[ptr]=temp;
            ptr = pind;
        }
        else{
            break;
        }
    }
}   

void heap::display(){
    cout<<"Heap"<<endl;
    for (int i = 1; i < size+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}

int heap::deleteroot(){
    int rootval = arr[1];

    arr[1] = arr[size];
    size--;
    takenodetocrctpstn(1,size);

    return rootval;
}

void heap::takenodetocrctpstn(int ptr , int size_){
    // int ptr = 1;
    while(2*ptr <= size_){
        int lc = arr[2*ptr];
        int rc = arr[(2*ptr)+1];
        if ((arr[ptr] < lc ) && (lc >= rc)){
            int temp = arr[2*ptr];
            arr[2*ptr]=arr[ptr];
            arr[ptr]=temp;
            ptr = 2*ptr;
        }
        else if ((arr[ptr] < rc ) && (2*(ptr)+1 <= size_) && (lc <= rc)){
            int temp = arr[(2*ptr)+1];
            arr[(2*ptr)+1]=arr[ptr];
            arr[ptr]=temp;
            ptr =(2*ptr)+1;
        }
        else{
            break;
        }

    }
}

void heap::hsort(){
    for (int i = 0; i < size; i++)
    {   
        int lastnodeind=size-i;
        int temp = arr[lastnodeind];
        arr[lastnodeind] = arr[1];
        arr[1] = temp;

        takenodetocrctpstn(1,size-1-i);
    }
    
}