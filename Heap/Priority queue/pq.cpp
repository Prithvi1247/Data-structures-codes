#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    priority_queue<int> pq;
    pq.push(1);
    pq.push(11);
    pq.push(11234);
    pq.push(112);

    cout<<"Priority queue following max heap"<<endl;
    cout<<"Priority queue size : "<<pq.size()<<endl;
    cout<<"Priority queue top element: "<< pq.top()<<endl;
    pq.pop();
    cout<<"Priority queue top element after popping: "<< pq.top()<<endl;

    priority_queue<int , vector<int>,greater<int>> mpq;
    mpq.push(1);
    mpq.push(11);
    mpq.push(11234);
    mpq.push(112);

    cout<<"Priority queue following min heap"<<endl;
    cout<<"Priority queue size : "<<mpq.size()<<endl;
    cout<<"Priority queue top element: "<< mpq.top()<<endl;
    mpq.pop();
    cout<<"Priority queue top element after popping: "<< mpq.top()<<endl;
    pq.
    return 0;
}