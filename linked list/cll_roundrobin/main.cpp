#include <iostream>
#include "C:\Users\prithvi\Documents\Programming\C++\codes\linked list\cll_roundrobin\mycllheader.h"
using namespace std;



int main()
{
    cll mylist;
    int inp =0, ui =0, timeslot =0, pro_time =0, timeleft =0 ;
    cout<<"Enter time slot: ";
    cin>>timeslot;

    while(1){
        cout<<"------------------------------------------";
        cout << "\n\n1.Insert Process\n2.Execute\n3.Exit\n\nEnter choice: ";
        cin >> inp;
        cout<<endl;

        switch (inp)
        {

        case 1 : 
            cout<<"Enter time of process :";
            cin>>ui;
            mylist.insertAtEnd(ui);
            break;
        
        case 2 : 
            pro_time = mylist.deleteAtBeg();
            timeleft = pro_time - timeslot;
            if (timeleft > 0 ){
                mylist.insertAtEnd(timeleft);
                cout<<"\nprocess inserted at end with time "<<timeleft<<endl;
            }
            else{
                cout<<"\nprocess completed"<<endl;
            }
            break;

        case 3:
            cout<<"Exiting.."<<endl;
            return 0;
        default:
            cout<<"Invalid Input"<<endl;
            
        }
    }
}
