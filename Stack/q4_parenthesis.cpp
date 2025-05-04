#include <iostream>
#include <string>
#include "stack.h" 

using namespace std;

int chkBalance(string);

int main(){
    int choice;
    while(true){
        cout<<"1. Check Balance\n2. Exit\n\nEnter choice:";
        cin>>choice;
        string str;
        switch (choice){
            case 1:
                cout<<"Enter string: ";
                cin>>str;
                chkBalance(str);
                break;
            case 2:
                return 0 ;
        }
    }
}

int chkBalance(string str){
    listADT parStk;
    parStk.push('E');
    for(char elem : str){
        if (elem == '('){
            parStk.push(elem);
        }
        else if(elem == ')'){
            if (parStk.peek()=='E'){
                cout<<"Not Balanced\n"<<endl;
                return 0;
            }
            parStk.pop();
        }
    }
    if (parStk.peek()=='E'){
        cout<<"Balanced\n"<<endl;
        return 1;
    }
    cout<<"Not Balanced\n "<<endl;

    return 0;
}