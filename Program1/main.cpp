/**
 * Author: Mohammed Ali
 * Version: 10132019
 * This program times iteration vs recursion
 * on numerical look-up on arrays with random
 * numbers
 * 
 * How to build/compile (with Makefile):
 * Run the following command in bash:
 *  $ make
 * This will compile the program and output a
 * runnable executable.
 * 
 * How to build/compile (without Makefile):
 * Run the following command in bash:
 *  $ g++ main.cpp -std=c++14 -o Program1
 * This will compile the program and output a
 * runnable executable.
 * 
 * How to run the program:
 * Run the following command in bash:
 *  $ ./run.sh
 * This will run the program and show the results to STDOUT.
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
    bool debug = false;
    // create arrays here
    //random number seed and using time to ensure the numbers change each time
    srand(time(NULL));
    //loop to fill elements of array
    for(int i=0; i < sz; i++){
        //storing numbers in varaible "num" and ensuring numbers are 0-100
        int num = (rand() % upper_bound);
        //placing numbers in elements of the array as it iterates through
        arr[i] = num;
        if(debug){
            //printing numbers as it goes 
            cerr << i << " --> " << arr[i] << endl;
        }
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

double timeIteration(int * random, int array_size, int lookup_num){
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
    timeFinal = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << "Iteration Time = " << timeFinal << " seconds." << endl;
    return timeFinal;
}

double timeRecursion(int * random, int array_size, int lookup_num){
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
    timeFinal = (double) (end - begin) / CLOCKS_PER_SEC;
    cout << "[RECURSION] Frequency = " << frequency_rec << endl;
    cout << "Recursion Time = " << timeFinal << " seconds." << endl;
    return timeFinal;
}

int main(){
    cout << "------------------------------------------------" << endl;
    // -- Program Configurations --
    int array_size = 10000;
    // number we are looking for
    int lookup_num = 5;
    int randomNum_upperBound = 101;

    // allocate memory for array_size numbers
    int * random = new int[array_size];
    //function to fill array
    random = fillArray(random, array_size, randomNum_upperBound);

    double iter_time = timeIteration(random,array_size,lookup_num);
    double recur_time = timeRecursion(random,array_size,lookup_num);

    if(iter_time < recur_time){
        cout << "[LOG]: Iteration was faster by: " << recur_time - iter_time << " seconds.\n";
    }
    else if(recur_time < iter_time){
        cout << "[LOG]: Recursion was faster by: " << iter_time - recur_time << " seconds.\n";
    }
    cout << "------------------------------------------------" << endl;
    return 0;
}