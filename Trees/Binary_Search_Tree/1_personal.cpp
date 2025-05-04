#include <iostream>
// #include <set>
using namespace std;

int thefunction(int , int[],int);
int* fillset(int[],int);
int find(int[] ,int  , int );

int main(){
    cout<<"Enter no of elimination positions: ";
    int k;
    cin>>k;

    int* IndArr = new int[k];
    for (int i = 0; i < k; i++)
    {
        cin>>IndArr[i];
    }
    cout<<"Enter no of queries: ";
    int q;
    cin>>q;
    
    for (int i = 0; i < q; i++)
    {   
        cout<<"Enter n"<<i+1<<": ";
        int n ;
        cin>>n;
        int output = thefunction(n,IndArr,k);
        cout<<"Answer for n"<<i+1<<": "<<output<<endl;
    }

    return 0;
}



int thefunction(int n , int IndArr[], int size){
    int* players = new int[n];
    int temp = n;
    while (true)
    {   
        // filling out the set after each removal step
        players = fillset(players,temp);
        cout<<"players: "<<endl;
        for(int i = 0 ; i< temp ; i++){
            cout<<players[i]<<" ";
        }

        int elim = 0 ; 
        // int currPlayers = players.size();
        int IndArrSize = size;
        for (int i = 0; i < IndArrSize; i++)
        {
            int removeInd = IndArr[i];
            int it = find(players,temp, removeInd);

            if ( it != -1){
                temp --;
                elim ++;
                cout<<"\n Eliminating a player!"<<endl;
            }     
        }
        if (elim == 0 ){
            cout<<"returning"<< temp<<endl;
            return temp;

        }
        

    }
    


}

int* fillset(int arr[],int temp){
    for (int i = 0; i < temp; i++) 
    {
        arr[i]=i+1;
    }
    return arr;

}

int find(int arr[],int size , int key){
    for (int i = 0; i < size; i++)
    {
        if (arr[i]==key){
            return 1;
        }
    }
    return -1;
    
}