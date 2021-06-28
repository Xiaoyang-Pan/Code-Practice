//
//  PermutationsWithDups.hpp
//  Code Practice
//
//  Created by Reid on 6/25/21.
//

#ifndef PermutationsWithDups_hpp
#define PermutationsWithDups_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

int strSize =0;

void printPerms(unordered_map<char,int> &aCharFreqs, vector<string> &aPerms,string aStr){
    
    if(aStr.size() == strSize){
        aPerms.push_back(aStr);
        return;
    }
    
    for(auto &theCharFreq:aCharFreqs){
        if(theCharFreq.second==0)
            continue;
        
        theCharFreq.second-=1;
        aStr.push_back(theCharFreq.first);
        printPerms(aCharFreqs,aPerms,aStr);
        aStr.pop_back();
        theCharFreq.second+=1;
    }
}

vector<string> printPerms(string aStr){
    
    unordered_map<char,int> theCharFreq;
    for(auto theChar:aStr){
        theCharFreq[theChar]++;
    }
        
    strSize = aStr.size();
    vector<string> thePerms;
    printPerms(theCharFreq, thePerms, "");
    return thePerms;
}

#endif /* PermutationsWithDups_hpp */
