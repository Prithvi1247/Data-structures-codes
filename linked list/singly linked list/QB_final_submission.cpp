#include <iostream>
#include "C:\Users\prithvi\Documents\Programming\C++\codes\linked list\header.h"

using namespace std;

int main(){
    linkedlist mylist1, mylist2, mergedlist;

    int inp = 0, value = 0, index = 0, a = 0;

    while (1)
    {

        cout << "1.Insert ascending in list 1 \n2.Insert ascending in list 2\n3.Merge\n4.Display \n5.Exit \nEnter choice: ";

        cin >> inp;

        switch (inp)
        {

        case 1:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist1.insertAsc(value);

            break;

        case 2:

            cout << "Enter value to be inserted : ";

            cin >> value;

            mylist2.insertAsc(value);

            break;

        case 3:

            mergedlist.merge(mylist1, mylist2);

            break;

        case 4:

            a = 0;

            cout << "Enter choice of list (1/2/3) : ";

            cin >> a;

            if (a == 1)
            {

                mylist1.display();
            }

            else if (a == 2)
            {

                mylist2.display();
            }

            else if (a == 3)
            {

                mergedlist.display();
            }

            else
            {

                cout << "Invalid input ";
            }

            break;

        case 5:

            cout << "Exiting..\n";

            return 0;

            break;
        }
    }
}