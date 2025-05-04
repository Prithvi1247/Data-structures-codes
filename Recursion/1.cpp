#include <iostream>
using namespace std;

void mycount(int n){
    // base case
    if (n==1){
        cout<<" 1";
        return;}
    cout<<" "<<n;
    // recursive relation
    mycount(n-1);
}

int main(){

    // counting using recursion
    mycount(100);

    return 0;
}