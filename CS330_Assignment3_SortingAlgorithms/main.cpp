#include <iostream>
using namespace std;
static int swaps = 0, comps = 0;

// merge function
void merge(int a[], int Firstindex, int m, int Lastindex)
{
    int x;
    int y;
    int z;
    int sub1 = m - Firstindex + 1;
    int sub2 =  Lastindex - m;


    int First[sub1];  //temp array

    int Second[sub2];


    for (x = 0; x < sub1; x++) // copying data to temp arrays
        First[x] = a[Firstindex + x];
    for (y = 0; y < sub2; y++)
        Second[y] = a[m + 1+ y];


    x = 0;
    y = 0;
    z = Firstindex;
    while (x < sub1 && y < sub2)
    {
        if (First[x] <= Second[y])
        {
            comps++;
            a[z] = First[x];
            x++;
        }
        else
        {
            comps++;
            a[z] = Second[y];
            y++;
        }
        z++;
    }
    while (x < sub1)
    {
        a[z] = First[x];
        x++;
        z++;
    }
    while (y < sub2)
    {
        a[z] = Second[y];
        y++;
        z++;
    }
}

void mergeSort(int arr[], int l, int r) {

    if(l<r){
        int m = l + (r-l)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr,l,m,r);

    }
}

void bubbleSort(int arr[], int n) {
    swaps = 0;
    comps = 0;

    for (int i=0; i<n; i++){
        for(int j=0; j<n-i-1; j++) {
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swaps++;
            }
            comps++;
        }
    }
}

void selectionSort(int arr[], int n) {
    swaps = 0;
    comps = 0;

    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            comps++;
            if (arr[j] < arr[i]) {
                swaps++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void insertionSort (int arr[], int n)
{
    swaps = 0;
    comps = 0;
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        comps++;
        key = arr[i];
        j = i - 1;
/* Move elements of arr[0..i-1], that are greater than key, to one
position ahead of their current position */
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            comps++;
            swaps++;
            j = j - 1;
        }
        arr[j + 1] = key;
        swaps++;
    }
}
// A utility function to print an array of size n
void printArray (int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}
// A utility function to print swaps and comparisons
void printSwapComp ()
{
    cout << "Swaps: " << swaps << ", Comparisons: " << comps << endl;
}


int main ()
{
    int size;
    cout << "how big do you want the array?" << endl;
    cin >> size;
//initialize array
    int array[size];
//Generate equal element array
//    cout << "Equal Array: " << size << " elements" << endl;
//    for (int i = 0; i < size; i++)
//    {
//        array[i] = 1;
//    }
//Generate increasing array
//        cout << "Increasing Array: " << size << " elements" << endl;
//        for (int i = 0; i < size; i++)
//        {
//            array[i] = i + 1;
//        }
//Generate decreasing array
//        cout << "Decreasing Array: " << size << " elements" << endl;
//        for (int i = 0; i < size; i++)
//        {
//            array[i] = size - i;
//        }
//generate random array
//        srand ((unsigned) time (0));
//        for (int i = 0; i < size; i++)
//        {
//            array[i] = (rand () % 100) + 1;
//        }
//print the array
    printArray (array, size);
//insertion sort
//            insertionSort (array, size);
//            printArray (array, size);
//            printSwapComp ();
//Bubble sort
            cout << endl;
            bubbleSort(array, size);
            printArray(array, size);
            printSwapComp();
//selection sort
//            cout << endl;
//            selectionSort(array, size);
//            printArray(array, size);
//            printSwapComp();
//merge sort
    //        cout << endl;
    //        mergeSort(array,0, size-1);
    //        printArray(array, size);
    //        printSwapComp();

    return 0;
}