/**
 * Author: Mohammed Ali
 * Version: 10132019
 * This program times iteration vs recursion
 * on numerical look-up on arrays with random
 * numbers
 */ 
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <map>
#include <iterator>
#include <vector>
using namespace std;

int* fillArray(int * arr, int sz, int upper_bound){
    // create arrays here
    //random number seed and using time to ensure the numbers change each time
    srand(time(NULL));
    //loop to fill elements of array
    for(int i=0; i < sz; i++){
        //storing numbers in varaible "num" and ensuring numbers are 0-100
        int num = (rand() % upper_bound);
        //placing numbers in elements of the array as it iterates through
        arr[i] = num;
        //printing numbers as it goes 
        cout << i << " --> " << arr[i] << endl;
    }
    //returning the array
    return arr;
}

int SimpleIteration(int * randomArray, int array_size,int freq){
    //variable to count freq
    int count = 0;
    //loop to iterate through array
    for(int i = 0; i < array_size; i++){
        //checking if element is equal to the frequency number
        if(randomArray[i] == freq){
            count++;
        }
    }
    return count;
}

int SimpleRecursion(int * randomArray, int finder, int array_size, int num, int count) {
    //base case of the numbers meeting in the middle of the array

    //if elements on the left are equal to frequency number reutrn and add to counter
    if (randomArray[finder] == num){ 
        count++;
    }
    if (finder+1 == array_size){
        return count;
    }
    //calling method to repeat over and over
    return SimpleRecursion(randomArray, finder + 1, array_size, num, count); 
}

void timeIteration(int * random, int array_size, int lookup_num){
    //begin time clock 
    clock_t begin;
    clock_t end;
    double timeFinal;

    begin = clock();
    //calling SimpleIteration function
    int frequency_iter = SimpleIteration(random,array_size,lookup_num);
    cout << "[ITERATION] Frequency = " << frequency_iter << endl;
    //end time 
    end = clock();
    //calculate time 
    timeFinal = end - begin / CLOCKS_PER_SEC;
    cout << "Iteration Time = " << timeFinal << endl;

}

void timeRecursion(int * random, int array_size, int lookup_num){
    //begin time clock 
    clock_t begin;
    clock_t end;
    double timeFinal;

    begin = clock();
    //calling SimpleRecursion function
    int count = 0;
    int idx = 0;
    int frequency_rec = SimpleRecursion(random,idx,array_size,lookup_num,count);
    end = clock();
    timeFinal = end - begin / CLOCKS_PER_SEC;
    cout << "[RECURSION] Frequency = " << frequency_rec << endl;
    cout << "Iteration Time = " << timeFinal << endl;
}

int main(){
    // -- Program Configurations --
    int array_size = 10000;
    // number we are looking for
    int lookup_num = 5;
    int randomNum_upperBound = 101;

    // allocate memory for array_size numbers
    int * random = new int[array_size];
    //function to fill array
    random = fillArray(random, array_size, randomNum_upperBound);

    timeIteration(random,array_size,lookup_num);
    timeRecursion(random,array_size,lookup_num);

    return 0;
}
