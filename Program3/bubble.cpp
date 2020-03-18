// C++ program for implementation of Bubble sort 
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

// A function to implement bubble sort 
void bubbleSort(int arr[], int n) 
{ 
	int i, j; 
	for (i = 0; i < n-1; i++)	 
	
	// Last i elements are already in place 
	for (j = 0; j < n-i-1; j++) 
		if (arr[j] > arr[j+1]) 
			swap(&arr[j], &arr[j+1]); 
} 

/* Function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		cout << arr[i] << " "; 
	cout << endl; 
} 

// Driver code 
int main() 
{ 
    clock_t begin;
    clock_t end;
    double timeFinal;
    begin = clock();
    int num = (rand() % 100);
    int arr[100000];
    for(int i =0; i <= 9999; i++){
        arr[i] = num; 
    }  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n); 
	cout<<"Sorted array: \n"; 
	printArray(arr, n);    
    end = clock();
    //calculate time 
    timeFinal = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << "Iteration Time = " << timeFinal << " seconds." << endl;
	return 0; 
} 

// This code is contributed by rathbhupendra 
