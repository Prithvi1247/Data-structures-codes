#include <iostream>
using namespace std;

class hashadt{
    private:
    int arr[7] = {-1,-1,-1,-1,-1,-1,-1};

    public:

    void insert(int);
    void display();
    void hdelete(int);
    bool hsearch(int);

};

int main(){
    int ch=0;
    hashadt h;
    while(ch!=5){
        cout<<"1.Insert\n2.Delete\n3.Search\n4.Display\n5.Exit\nEnter choice: ";
        cin>>ch;
        switch(ch){
            case 1:{
                cout<<"Enter value: ";
                int d;
                cin>>d;
                h.insert(d);
                break;
            }
            case 4:{
                h.display();
                break;
            }
            case 2:{
                cout<<"Enter value: ";
                int d;
                cin>>d;
                h.hdelete(d);
                break;
            }

            case 3:{
                cout<<"Enter value: ";
                int d;
                cin>>d;
                if (h.hsearch(d)){
                    cout<<"Value found"<<endl;
                }
                else{
                    cout<<"Value not found"<<endl;
                }
                break;
            }


            default:
                cout<<"Invalid Input! "<<endl;
        }

        cout<<"--------------------------------------"<<endl;
    }

    return 0;
}

bool hashadt::hsearch(int d){
    int rem = d%7;
    int turns = 0;
    while(turns < 8){
        if (arr[rem ] == d){
            return true;
        }
        turns++;
        rem = rem +1;
        rem = rem%7;
    }
    return false;
}

void hashadt::insert(int d){
    int rem = d%7;
    while(1){
        if (arr[rem] == -1){
            arr[rem] = d;
            return ;
        }
        else{
            rem++;
            rem = rem%7;
        }
    }
}

void hashadt::display(){
    for (int i = 0; i < 7; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<""<<endl;
}

void hashadt::hdelete(int d){
    int rem = d%7;
    int times = 0 ; 
    while (arr[rem] != d && times < 8){
        rem++;
        rem = rem%7;
        times++;
    }
    if (times >7){
        cout<<"value not present! "<<endl;
        return ;
    }
    arr[rem] = -1;

}