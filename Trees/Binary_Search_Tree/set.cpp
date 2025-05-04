#include <iostream>
#include <set>
using namespace std;

int main(){

    set<int> myset = {10,20,30,40,50};
    for (int i : myset){
        cout<<i<<" "<<endl;
    }
    cout<<endl;

    myset.erase(10);
    for (int i : myset){
        cout<<i<<" "<<endl;
    }
    cout<<endl;
    auto itsdf =myset.find(20);
    // cout<< itsdf <<endl;
    return 0;
}