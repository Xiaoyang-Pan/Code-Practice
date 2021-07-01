//
//  SparseSearch.hpp
//  Code Practice
//
//  Created by Reid on 6/30/21.
//

#ifndef SparseSearch_hpp
#define SparseSearch_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int search(vector<string> aStrings, string aStr, int aStart, int aEnd){
    if(aStart > aEnd)
        return -1;
    
    int theMid = aStart+(aEnd-aStart)/2;
    int theMidLeft = theMid;
    int theMidRight = theMid;
    
    while(theMidLeft >= aStart || theMidRight <= aEnd){
        if(theMidLeft >= aStart)
        {
            if(!aStrings[theMidLeft].empty()){
                theMid = theMidLeft;
                break;
            }
            theMidLeft++;
        }
        
        if(theMidRight <= aEnd){
            if(!aStrings[theMidRight].empty()){
                theMid = theMidRight;
                break;
            }
            theMidRight++;
        }
    }
    
    cout << theMid << endl;
    
    if(aStrings[theMid] == aStr)
        return theMid;
    else if(aStrings[theMid] > aStr)
        return search(aStrings, aStr,aStart,theMid-1);
    else
        return search(aStrings,aStr,theMid+1, aEnd);
}

int search(vector<string> aStrings, string aStr){
    if(aStrings.empty() || aStr.empty())
        return -1;
    return search(aStrings, aStr, 0, aStrings.size()-1);
}

#endif /* SparseSearch_hpp */
