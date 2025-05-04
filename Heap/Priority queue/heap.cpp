#include <iostream>
using namespace std;

void heapme(int[],int);
void heapify(int[],int,int);

class heap{
    private:
    int arr[100];
    int size = 0 ;

    public:
    heap(){}
    //functions 
    void insert(int);
    void display();
    void deleteroot();
    void hsort();
    int search(int);


};
int main(){
    int ch = 0 ; 
    heap hp;
    while(ch!=7){
        cout<<"1.Insert\n2.Display\n3.Delete root node\n4.Heap any array\n5.Sort Heap\n6.Search element\n7.Exit\nEnter choice: ";
        cin>>ch;
        switch (ch){
            case 1 : 
                cout<<"Enter value : ";
                int d;cin>>d;
                hp.insert(d);
                break;

            case 2:
                hp.display();
                break;

            case 3:
                hp.deleteroot();
                break;

            case 4:{
                cout<<"Enter no of elements: ";
                int n ; cin>>n;
                int* iarr = new int[n+1];
                for (int i = 1; i < n+1; i++)
                {
                    cin>>iarr[i];
                }
                
                heapme(iarr,n);
                break;
            }
            case 5:
                hp.hsort();
                break;

            case 6:{
                cout<<"Enter element :";
                int e;cin>>e;
                int ans = hp.search(e);
                break;
            }

            case 7:
                cout<<"Exiting!.."<<endl;
            default:
                cout<<"INVALID INPUT! "<<endl;
            

        }
    }
    return 0;
}
// returns 1 if element found else 0
int heap::search(int val){
    int ind = 0 ;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val){
            ind = i;
        }
    }
    if(ind==0){
        cout<<"Element not found !"<<endl;
        return -1;
    }

    int p = ind/2;
    if (p==0){
        cout<<"Element is root node "<<endl;
    }
    else if ( ind == (2*p) +1){
        cout<<"Element is right child of "<<arr[p]<<" node"<<endl;
    }
    else{
        cout<<"Element is left child of "<<arr[p]<<" node"<<endl;
    }
    return 1;

}
// sorts the elements of the heap
void heap::hsort(){
    int tsize = size;
    while(tsize >0){
        // swapping first and last element
        int temp = arr[tsize];
        arr[tsize]=arr[1];
        arr[1] = temp;

        // decrementing size
        tsize--;

        // heapifying the rest of the elements
        // cout<<"--------------------"<<endl;
        // this->display();
        // cout<<"--------------------"<<endl;
        heapify(arr,tsize , 1);

    }
}
// heaps an array of integers
void heapme(int arr[],int size){
    for (int i = size/2 ; i > 0 ; i--)
    {
        heapify(arr,size,i);
    }
    for (int i = 1; i < size+1; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
    
}
// Applies heap algorithm on the specified element
void heapify(int arr[],int _size , int i){
    int ind = i;
    int li = 2*i;
    int ri = 2*i +1 ;

    if (li <= _size && arr[li] > arr[ind]){
        ind = li; 
    }
    if (ri <= _size && arr[ri] > arr[ind]){
        ind = ri;
    }
    if (ind != i ){
        int temp =arr[i];
        arr[i] = arr[ind];
        arr[ind]=temp;

        heapify(arr,_size,ind);
    }
    else{
        return;
    }
}
// Inserts element in the heap
void heap::insert(int num){
    size++;
    arr[size]=num;
    int ind = size;
    while(ind>1){
        int par = ind / 2;
        if (arr[par] < arr[ind]){
            int temp = arr[par];
            arr[par] = arr[ind];
            arr[ind]=temp;

            ind = par;
        }
        else{return;}
    }
}
// Displays the heap
void heap::display(){
    for (int i = 0; i < size; i++)
    {
        cout<<arr[i+1]<<" ";
    }
    cout<<endl;
}
// Deletes the root element of the heap
void heap::deleteroot(){
    arr[1] = arr[size];
    size--;
    int i = 1;
    while( 2*i <= size){
        int lc = arr[2*i];
        int rc = arr[2*i+1];

        if ((arr[i] < lc) && (lc >=  rc)){
            int temp = arr[i];
            arr[i]=arr[2*i];
            arr[2*i]=temp;

            i = 2* i ;
        }
        else if((arr[i] < rc) && (lc <=  rc)){
            int temp = arr[i];
            arr[i]=arr[(2*i)+1];
            arr[(2*i)+1]=temp;

            i = (2* i) +1;
        }
        else{
            return ;
        }
    }
}
