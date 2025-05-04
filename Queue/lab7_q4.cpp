#include <iostream>
#include <vector>
#include <string>
#include "stack.h"

using namespace std;
string function(string);
string stackToStringEfficient(listADT );

int main(){
    string input_str;
    cout<<"Enter string: ";
    cin>>input_str;

    string output_str = function(input_str);
    cout<<"Ouput: "<<output_str;

    return 0;
}

string function(string str){
    char elem = str[0];
    listADT mystk;
    mystk.push(elem);
    int size = str.length();
    for (int i = 1; i < size; i++)
    {
        if (str[i]=='+'  && mystk.peek()!='`'){
            mystk.pop();
        }
        else{

            mystk.push(str[i]);
        }
    }
    str = stackToStringEfficient(mystk);
    return str;
}

string stackToStringEfficient(listADT st) {
    vector<char> temp;

    while (st.peek()!='`') {
        temp.push_back(st.peek());
        st.pop();
    }

    return string(temp.rbegin(), temp.rend()); 
}