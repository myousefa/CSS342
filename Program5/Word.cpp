/**
 * Author: Mohammed Ali 
 * Version 11212019
 * This program reads in a file and prints the top 25 words
 * by frequency.
 * 
 * */

#include <iostream>
#include <map>
#include <fstream> 
#include <string>
#include <vector>
using namespace std;

pair<string,int> find_max_word(map<string,int>& words){
    //iterator to go through map
    map <string, int > :: iterator it = words.begin();
    //counter number 
    int currentmax = 0;
    //string storer 
    string maxword = "";
    //pair that stores "maxword" and "currentmax"
    pair<string,int> top_word;

    // finds the most maximum number associated with keys
    for(it = words.begin(); it != words.end(); it++){
        if (it->second > currentmax){
            currentmax = it->second;
        }
    }
    // finds the string associated with that value
    for(it = words.begin(); it != words.end(); it++){
        if (it->second == currentmax){
            maxword = it->first;
            currentmax = it->second;

            top_word.first = maxword;
            top_word.second = currentmax;

            // Remove this entry
            words.erase(maxword);
            return top_word;
        }
        
    }
    
    return top_word;
}


int main(){
    
    bool debug = false;
    string word;
    map<string, int> myDictionary;
    // gets txt file
    ifstream myFile("MobyDick.txt");
    // reads file and puts each word into dictionary 
    while(myFile >> word){

        if(myDictionary.find(word) == myDictionary.end()){
            myDictionary[word] = 1;
        } else { 
            myDictionary[word]++;
        }
    }
    // used for debugging not important to solution
    if(debug){
        for(map<string,int>::iterator it = myDictionary.begin(); it != myDictionary.end(); it++){
            cout << "[KEY]: " << it->first << " ---- VALUE: " << it->second << endl;
        }
    }
    // vector to store all 25 keys and values
    vector<pair<string,int>> top_words;
    // for loop runs method 25 times to get top 25 words
    for (int i = 0; i < 25; i++){
        pair<string,int> res = find_max_word(myDictionary);
        top_words.push_back(res);        
    }

    // prints vector
    for(pair<string,int> item : top_words){
        cout << "[KEY]: " << item.first << " ---- [VALUE]: " << item.second << endl;
    }
    return 0;   
}