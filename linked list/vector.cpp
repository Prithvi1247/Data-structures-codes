#include <iostream>
#include <vector>

using namespace std;

int main(){

    vector<int> intvector;
    intvector.push_back(1);
    intvector.push_back(2);
    intvector.push_back(3);
    intvector.push_back(20);

    for (int elem : intvector){
        cout<<elem<<endl;
    }
   
    cout<<"the size of the vector is :"<<intvector.size()<<endl;
    cout<<"index 3: "<<intvector.at(3)<<" or "<<intvector[3]<<endl;
    // cout<<"index 30: "<<intvector.at(30)<<endl;

    cout<<intvector.front()<<endl;
    cout<<intvector.back()<<endl;
    
    cout<<intvector.back()<<endl;
    intvector.pop_back();
    for (int elem : intvector){
        cout<<elem<<endl;
    }
    return 0 ;
}