/**
 * Author: Mohammed Ali
 * Version: 12082019
 * 
 * This program times loading nodes,
 * adding nodes, and deleting nodes into
 * a red black tree. 
 * 
 * Be sure to run un c++ version 11: -std=c++11
 */ 

#include "RBT.h"
#include <time.h>
#include <fstream>

int main(int argc, char* argv[])
{
    //create red black tree
	rb_tree<int> tree;
    //import text files
    ifstream loadfile("SBT1.txt");
    ifstream addfile("SBT2.txt");
    ifstream removefile("SBT3.txt");

    //stores number to put into tree
    int num;
    //timer for loading nodes
    clock_t begin1;
    clock_t end1;
    double timeFinal1;
    begin1 = clock();
    while (loadfile >> num){
        //inserts each number into tree
        tree.insert(num);
    }
    //end timer + calculation
    end1 = clock();
    timeFinal1 = (double) (end1 - begin1) / CLOCKS_PER_SEC;
    

	//print time to load nodes
    std:: cout << "RBT time to LOAD: " << timeFinal1 << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    //timer for adding nodes
    clock_t begin2;
    clock_t end2;
    double timeFinal2;
    begin2 = clock();
    while (addfile >> num){
        // add each number in
        tree.insert(num);
    }
    //end timer + calculation 
    end2 = clock();
    timeFinal2 = (double) (end2 - begin2) / CLOCKS_PER_SEC;
    
    
    //print time to add nodes
    std:: cout << "RBT to time ADD: " << timeFinal2 << std::endl;
    std::cout << "-------------------------------------" << std::endl;


    //timer for deleting nodes
    clock_t begin3;
    clock_t end3;
    double timeFinal3;
    begin3 = clock();
    while (removefile >> num){
        //erase/delete each node in tree
        tree.erase(num);
    }
    //end timer + calculation
    end3 = clock();
    timeFinal3 = (double) (end3 - begin3) / CLOCKS_PER_SEC;


    //print time to remove nodes
    std:: cout << "RBT time to REMOVE: " << timeFinal3 << std::endl;
    std::cout << "-------------------------------------" << std::endl;
 	return 0;
 }