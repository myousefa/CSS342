#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <map>
#include <iterator>
#include <vector>
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i=0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
} 

  
// Driver program to test above functions  
int main()  
{   
    clock_t begin;
    clock_t end;
    double timeFinal;
    begin = clock();
    int num = (rand());
    int arr[100000];
    for(int i =0; i <= 9999; i++){
        arr[i] = num; 
    }  
    int n = sizeof(arr)/sizeof(arr[0]);  
    selectionSort(arr, n);  
    cout << "Sorted array: \n";  
    printArray(arr, n);  
    end = clock();
    //calculate time 
    timeFinal = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << "Iteration Time = " << timeFinal << " seconds." << endl;
    return 0;  
}  