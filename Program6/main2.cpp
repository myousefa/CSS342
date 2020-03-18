/**
 * Author: Mohammed Ali
 * Version: 12082019
 * 
 * This program times loading nodes,
 * adding nodes, and deleting nodes into
 * an AVL tree.
 * 
 * Be sure to run un c++ version 11: -std=c++11
 */ 
#include "AVL.h"
#include <cassert>
#include <time.h>
#include <fstream>

using namespace std;
int main() {

    //create AVL tree
    AVLTree<int> avl;
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
        avl.insert(num);
    }
    //end timer + calculation
    end1 = clock();
    timeFinal1 = (double) (end1 - begin1) / CLOCKS_PER_SEC;
    

	//print time to load tree
	avl.inOrderTraversal();
    std:: cout << "AVL time to LOAD: " << timeFinal1 << std::endl;
    std::cout << "-------------------------------------" << std::endl;

    //timer for adding nodes
    clock_t begin2;
    clock_t end2;
    double timeFinal2;
    begin2 = clock();
    while (addfile >> num){
        // add each number in
        avl.insert(num);
    }
    //end timer + calculation 
    end2 = clock();
    timeFinal2 = (double) (end2 - begin2) / CLOCKS_PER_SEC;
    
    
    //print time to add nodes
	avl.inOrderTraversal();
    std:: cout << "AVL time to ADD: " << timeFinal2 << std::endl;
    std::cout << "-------------------------------------" << std::endl;


    //timer for deleting nodes
    clock_t begin3;
    clock_t end3;
    double timeFinal3;
    begin3 = clock();
    while (removefile >> num){
        //erase/delete each node in tree
        avl.remove(num);
    }
    //end timer + calculation
    end3 = clock();
    timeFinal3 = (double) (end3 - begin3) / CLOCKS_PER_SEC;


    //print time to remove nodes
	avl.inOrderTraversal();
    std:: cout << "AVL time to REMOVE: " << timeFinal3 << std::endl;
    std::cout << "-------------------------------------" << std::endl;
 	return 0;
}