#include <iostream>
using namespace std;

int solve(int );
int isUnique(int [], int );
int main(){

   
   int arr[5] = {1,1,3,4,5};
   cout<<isUnique(arr,5)<<endl;
   return 0;
}

int solve(int n){
    int* arr = new int[n];
    for (int i = 0; i < n; i++){cin>>arr[i];}

    int ptr = 0 ; 
    int sizeArr = n;


    
}


int isUnique(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        int elem = arr[i];
        for (int j = i+1; j < size; j++)
        {   
            if (elem == arr[j]){return 0;}
        
        }
        return 1;
    }
    
}