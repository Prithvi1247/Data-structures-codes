#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    unordered_map<string, int> m = {{"apple", 3}, {"banana", 5}};

    unordered_map<string,int> umap;

    // Insertion
    pair<string ,int> p = make_pair("prithvi",1);
    umap.insert(p);

    pair<string,int> q("Akshay",2);
    umap.insert(q);

    umap["Krithik"]=9; // new entry - creation
    umap["Krithik"]=8; // updation

    // Search

    cout<<umap["prithvi"]<<endl;
    cout<<umap.at("Akshay")<<endl;

    // cout<<umap.at("yadunandan")<<endl; // outputs error as entry not found
    cout<<umap["yadunandan"]<<endl; // outputs 0 as new entry created


    cout<<umap.size()<<endl;

    // to check whether a key is a part of the map
    cout<<"Count function--"<<endl;
    cout<<umap.count("yadunandan")<<endl;
    cout<<umap.count("BRO")<<endl;

    //remove entries
    umap.erase("yadunandan");
    cout<<umap.size()<<endl;


    cout<<"Traversing a map"<<endl;

    for (auto it = umap.begin() ; it != umap.end() ; it ++) {
        cout<<it->first<<" "<<it->second<<endl;
    }
    cout<<"\n"<<endl;
    cout<<"Traversing a map 2 "<<endl;
    for (auto i:umap) {
        cout<<i.first<<" "<<i.second<<endl;
    }
    
    
    return 0;
}