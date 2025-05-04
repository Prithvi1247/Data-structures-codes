#include <iostream>
#include <unordered_map>
using namespace std;

int main(){

    // to traverse a map 

    //1 

    unordered_map<string,int> umap ;
    // Insertion
    pair<string ,int> p = make_pair("prithvi",1);
    umap.insert(p);

    pair<string,int> q("Akshay",2);
    umap.insert(q);

    umap["Krithik"]=9; // new entry - creation
    
    unordered_map<string,int> ::iterator it = umap.begin();

    while(it!=umap.end()){
        cout<<it->first<<" "<<it->second<<endl;
        it++;
    }




    return 0;
}