/**
 * Author: Mohammed Ali
 * Version: 10172019
 * This program checks if a string is balanced. 
 * It checks if brackets, parenthesis, or curly braces
 * are opened and closed in the correct order. 
 * 
 **/

#include <iostream>
#include <cstdlib>
#include <stack>
#include <string>
using namespace std;

//returns true if brackets, parethesis, or curly brace are matching pairs
//takes in two parameters, one being the opener and closer bracket
bool MatchingPair(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }
    if(open == '{' && close == '}'){
        return true;
    }
    if(open == '[' && close == ']'){
        return true;
    } else {
        //return false if not matching pair
        return false;
    }
}

bool BalancedStatement(string expression){
    stack<char> myStack;
    //if string is empty automatically return it is balanced
    if(expression.length() == 0){
        return true;
    }
    //any odd number expression can not be balanced
    if(expression.length() % 2 != 0){
        return false;
    }
    //ensuring only larger than 1 length strings can go through
    if(!expression.length()){
        //using for loop to iterate through string
        for(int i = 0; i < expression.length(); i++){
            //identifying elements that are opening brackets and adding to stack
            if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                myStack.push(expression[i]);
                continue;
            }
            else {
                //if the stack is empty there is nothing to see
                if(myStack.empty()){
                    return false;
                }
                //check for pairs being in the right order and pop the top off
                if(MatchingPair(myStack.top(), expression[i])){
                    myStack.pop();
                }
                //if they do not match return false and not balanced 
                else {
                    return false;
                }
            }
        }
    }
    return myStack.empty();
}

int main(){
    //example expression
    string expression = "[][]";
    //run method to see if balanced or not. 
    if(BalancedStatement(expression)){
        cout << "--------------------------------" << endl;
        cout << "The Expression is Balanced" << endl;
        cout << "--------------------------------" << endl;
        return 1;
    }
    else{
        cout << "--------------------------------" << endl;
        cout << "The Expression is NOT Balanced" << endl; 
        cout << "--------------------------------" << endl;
        return 0;
    }
}