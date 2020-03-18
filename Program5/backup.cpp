#include <iostream>
#include <map>
#include <fstream> 
#include <string>

using namespace std;


int main(){
    string word;
    map<string, int> myDictionary;
    ifstream myFile("MobyDick.txt");
    
    while(myFile >> word){
        //cout << word << endl;
        if(myDictionary.find(word) == myDictionary.end()){
            myDictionary[word] = 1;
        } else { 
            myDictionary[word]++;
        }
    }

    map <string, int > :: iterator it = myDictionary.begin();
    int currentmax = 0;
    string maxword = "";
    for (int i = 0; i <= 25; i++){}
        for(it = myDictionary.begin(); it != myDictionary.end(); it++){
            if (it->second > currentmax){
                maxword = it->first;
                currentmax = it->second;
                it->second = 0;
            }
            cout << "Value: " << maxword << " Key: " << currentmax << endl;
    }
}
     
