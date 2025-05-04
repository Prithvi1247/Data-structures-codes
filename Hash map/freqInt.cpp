#include <iostream>
#include<map>
#include<vector>

using namespace std;

int maxFreq(vector<int>,int);

int main(){
    cout<<"Enter no of testcases: ";int tc;cin>>tc;
    while(tc--){

        cout<<"Enter no of elements : ";int n;cin>>n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int elem;cin>>elem;
            v.push_back(elem);
        }

        int ans = maxFreq(v,n);
        cout<<"Answer: "<<ans<<endl;

    }
    return 0;
}

int maxFreq(vector<int> vect , int n){
    map<int,int> m;
    for (int i = 0; i < n; i++)
    {   
        // Initialise map
        int key = vect.at(i);
        // if (m.count(key)){
        m[key]++; // if key not present , it creates and appends one
        // }
        // else{
        //     m[key] = 1;
        // }
    }
   
    int maxf = 0;
    int maxelem = -1;
    for (int i = 0; i < n; i++){
        int key = vect.at(i);
        if (m[key] > maxf){
            maxf = m[key];
            maxelem = key;
        }
    }
    for (auto i:m) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    return maxelem;

}