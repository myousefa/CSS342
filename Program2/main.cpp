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

bool MatchingPair(char open, char close){
    if(open == '(' && close == ')'){
        return true;
    }
    if(open == '{' && close == '}'){
        return true;
    }
    if(open == '[' && close == ']'){
        return true;
    }
    else {
        return false;
    }
}

bool isValid(string expression){
    stack<char> myStack;
    //if string is empty automatically return it is balanced
    if(expression.length() == 0){
        return true;
    }
    //any odd number expression can not be balanced
    if(expression.length() % 2 != 0){
        return false;
    }

    if(!expression.length()){
        for(int i = 0; i < expression.length(); i++){
            if(expression[i] == '(' || expression[i] == '{' || expression[i] == '['){
                myStack.push(expression[i]);
                continue;
            }
            else {
                if(myStack.empty()){
                    return false;
                }
                if(MatchingPair(myStack.top(), expression[i])){
                    myStack.pop();
                }
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
    //string expression = "[][]";
    string expression = "[][]";
    //fillingStack(expression);
    if(isValid(expression)){
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