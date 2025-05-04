#include <iostream>
using namespace std;
int* solve(int[],int);
int maxexcept(int [] ,int, int );

int main(){

    cout<<"Enter no of test cases: ";
    int tc;cin>>tc;
    while(tc--){
        cout<<"Enter no of elements: ";
        int n;cin>>n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        
        int* op = solve(arr,n);
        for (int i = 0; i < n; i++)
        {
            cout<<op[i]<<" ";
        }
        cout<<endl;
        
    }

    return 0;
}

// returns array according to the q
int* solve(int arr[],int size){
    int* op = new int[size];

    for (int i = 0; i < size; i++)
    {
        op[i]=-maxexcept(arr,size,i)+arr[i];
    }
    return op;
}
// returns the difference between each element and the maximum element except it in the array
int maxexcept(int arr[] , int size , int index1 ){
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (i != index1){
            if (max < arr [i]){
                max = arr[i];
            }
        }
    }
    return max;

}