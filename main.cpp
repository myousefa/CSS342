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

// stack<char> fillingStack(string expression, string x){
//     for(int i = 0; i < expression.length(); i++){
//         stack <char> myStack;
//         //push opening braces into stack 
//         if(expression[i] == '{' || expression[i] == '(' || expression[i] == '['){
//             myStack.push((expression[i]));
//         } else { return myStack; }
//         return myStack;
//     }
// }

// bool BalacingExpression (string expression, char elements[]){
//     stack<char> myStack;
//     int index = 0; 

//     for(int i = 0; i < expression.length(); i++){
//         //push opening braces into stack 
//         if(expression[i] == '{' || expression[i] == '(' || expression[i] == '['){
//             myStack.push((expression[i]));
//             continue;
//         } else if(myStack.empty()){ return true; }
//     }

//     while(elements[index]){
//         if(elements[index]==')' || elements[index]=='}' || elements[index]==']') {
//             if (myStack.top() != elements[i]){
//                 return false;
//             }
//             else {
//                 myStack.pop();
//             }
//         }
//     index++;
//     }
//     return myStack.empty();
// }

// bool BalancedExpression(string expression){
//     //stack to put string into
//     stack <char> myStack;
//     //using for loop to put string elements into stack
    
    
//         //check for closing braces
//         if(expression[i] == '}'){
//             //check if top element in stack is equal to closing brace and pop
//             if(!myStack.empty() && myStack.top() == '{'){
//                 myStack.pop();
//             } else { return false; }
//         } else if(expression[i]== ')'){
//             if(!myStack.empty() && myStack.top() == ')'){
//                 myStack.pop();
//             } else { return false; } 
//         } else if(expression[i]== ']'){
//             if(!myStack.empty() && myStack.top() == ']'){
//                 myStack.pop();
//             } else { return false; }   
//         }
//         //if the stack is empty by the end it means expression is balanced
//         if(myStack.empty()){
//             return true;
//         } else {
//             return false;
//         }
//     }
//     return true;
// }

// bool isValid(string expression){
//     stack<char> myStack;
//     //if string is empty automatically return it is balanced
//     if(expression.length() == 0){
//         return true;
//     }
//     //any odd number expression can not be balanced
//     if(expression.length() % 2 != 0){
//         return false;
//     }

//     for(int i = 0; i < expression.length(); i++) {
//         char c = expression[i];
//         //cout << c << endl;
//         if(c == '(' || c == '[' || c == '{'){
//             myStack.push(c);
//         }
//         else if(c == '}' && myStack.top() == '{') {
//             myStack.pop();
//             return true;
//         }
//         else if(c == ')' && myStack.top() == '(') {
//             myStack.pop();
//             return true;
//         }
//         else if(c == ']' && myStack.top() == '[') {
//             myStack.pop();
//             return true;
//         }
//         return myStack.empty();
//     }
//     return myStack.empty();
// }

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