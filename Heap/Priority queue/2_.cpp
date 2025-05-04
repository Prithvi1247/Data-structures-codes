#include <iostream>
using namespace std;

int* solve(string*,string*,string* , int );
int check(string  , string* ,string*  , int );

int main(){
    cout<<"Enter no of testcases: ";
    int tc;cin>>tc;

    while(tc--){
        cout<<"Enter no of words: ";
        int n ;
        cin>>n;

        string p1[n];
        string p2[n];
        string p3[n];

        string* ptr1 = p1;
        string* ptr2 = p2;
        string* ptr3 = p3;

        for (int j = 0; j < n ; j++)
        {
            cin>>ptr1[j];
        }
        for (int j = 0; j < n ; j++)
        {
            cin>>ptr2[j];
        }
        for (int j = 0; j < n ; j++)
        {
            cin>>ptr3[j];
        }          
        int* arr = solve(ptr1,ptr2,ptr3,n);


    }
    return 0;
}

int* solve(string* ptr1 ,string* ptr2,string* ptr3, int n){

    int s1=0,s2=0,s3=0;
    int arr[3];
    for (int i = 0; i < n; i++)
    {
        string p1_word = ptr1[i];

        int wrdsc = check(p1_word,ptr2,ptr3,n);
        switch (wrdsc){
            case 0:
            s1 = s1+3;
            break;
            case 1:
            s1 = s1 + 1;
            break;
        }
        
    }
    for (int i = 0; i < n; i++)
    {
        string p1_word = ptr2[i];

        int wrdsc = check(p1_word,ptr1,ptr3,n);
        switch (wrdsc){
            case 0:
            s2 = s2+3;
            break;
            case 1:
            s2 = s2 + 1;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        string p1_word = ptr3[i];

        int wrdsc = check(p1_word,ptr2,ptr1,n);
        switch (wrdsc){
            case 0:
            s3 = s3+3;
            break;
            case 1:
            s3 = s3 + 1;
            break;
        }
    }
    
    cout<<s1<<" "<<s2<<" " <<s3<<endl;
    return 0;
    
}

int check(string word , string* arr1,string* arr2 , int n){
    int a= 0;
    for (int i = 0; i < n; i++)
    {
        if (word == arr1[i]){
            a++;
            break;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (word == arr2[i]){
            a++;
            break;
        }
    }
    return a;
}