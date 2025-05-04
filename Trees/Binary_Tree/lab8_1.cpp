#include <iostream>
#include <algorithm>
using namespace std;

int findHeighestFirsttow(int[], int);
int maxArr(int[], int);
int sumArr(int[], int);
int countarr(int[], int, int);

int main()
{
    cout << "enter no of test cases :";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter no of towers for testcase " << i + 1 << " : ";
        int tow;
        cin >> tow;
        int *arr = (int *)malloc(tow * sizeof(int));
        int data = 0;
        for (int j = 0; j < tow; j++)
        {
            cin >> arr[j];
        }

        int hfirsttow = findHeighestFirsttow(arr, tow);
        cout << "answer : " << hfirsttow << endl;
    }

    return 0;
}

int maxArr(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int countarr(int arr[], int size, int elem)
{
    int ct = 0;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
        {
            ct++;
        }
    }
    return ct;
}

int sumArr(int arr[], int size)
{
    long sm = 0;
    for (int i = 0; i < size; i++)
    {
        sm += arr[i];
    }
    return sm;
}

int findHeighestFirsttow(int arr[], int size)
{

    
        while (!((arr[0] == maxArr(arr, size))))
        {
            int i = 0;
            while ((i < size - 1))
            {
                while (arr[0] < arr[i + 1])
                {
                    arr[0]++;
                    arr[i + 1]--;
                }
                i++;
            }
        }
        return arr[0];
    

}
