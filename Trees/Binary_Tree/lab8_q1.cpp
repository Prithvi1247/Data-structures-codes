#include <iostream>

using namespace std;

int maxArr(int[], int);

int maxFirstTow(int[], int);

void selSort(int[], int);

int main()
{

    cout << "Enter no of testcases: ";

    int tc;

    cin >> tc;

    for (int i = 0; i < tc; i++)
    {

        cout << "Enter no of towers for testcase " << i + 1 << ": ";

        int tow;

        cin >> tow;

        int *arr = (int *)malloc(sizeof(int) * tow);

        for (int j = 0; j < tow; j++)
        {

            cin >> arr[j];
        }

        cout << "Answer: " << maxFirstTow(arr, tow) << endl;
    }

    return 0;
}

// Returns the highest possible block size in tower 1

int maxFirstTow(int arr[], int size)
{

    selSort(arr, size);

    while (arr[0] != maxArr(arr, size))
    {

        int i = 0;

        while (i < size)
        {

            while (arr[0] < arr[i])
            {

                arr[0]++;

                arr[i]--;
            }

            i++;
        }
    }

    return arr[0];
}

// Returns the maximum element present in the array

int maxArr(int arr[], int size)
{

    int maxelem = arr[0];

    for (int i = 1; i < size; i++)
    {

        if (arr[i] > maxelem)
        {

            maxelem = arr[i];
        }
    }

    return maxelem;
}

void selSort(int arr[], int size)
{ // SELECTION SORTING OF ARRAY

    for (int i = 1; i < size - 1; i++)
    {

        int min = arr[i];

        int ind = i;

        for (int j = i + 1; j < size; j++)
        {

            if (arr[j] < min)
            {

                min = arr[j];

                ind = j;
            }
        }

        int temp = arr[i];

        arr[i] = min;

        arr[ind] = temp;
    }
}