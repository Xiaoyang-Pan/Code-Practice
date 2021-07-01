//
//  PeaksAndValleys.hpp
//  Code Practice
//
//  Created by Reid on 6/30/21.
//

#ifndef PeaksAndValleys_hpp
#define PeaksAndValleys_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void sprtValleyPeak(vector<int> &aNums){
    
    vector<int> theTempNums = aNums;
    int theStart = 0;
    int theEnd = aNums.size()-1;
    sort(theTempNums.begin(),theTempNums.end());
    
    int theIndex =0;
    while(theStart < theEnd){
        aNums[theIndex] = theTempNums[theEnd];
        aNums[theIndex+1] = theTempNums[theStart];
        
        theStart++;
        theEnd--;
        theIndex+=2;
    }
}

void sprtValleyPeak_swap(vector<int> &aNums){
    
    sort(aNums.begin(),aNums.end());
    
    for(int i =1; i< aNums.size();i+=2){
        int theTemp = aNums[i];
        aNums[i] = aNums[i-1];
        aNums[i-1] = theTemp;
    }
}

void sprtValleyPeak_swap_optimize(vector<int> &aNums){
    
    
    for(int i =1; i< aNums.size();i+=2){
        
        int theLeftVal = aNums[i-1];
        int theMidVal = aNums[i];
        int theRightVal = i+1 < aNums.size() ? aNums[i+1] : INT_MIN;
        
        int theMinIndex;
        int theMinVal = min(theLeftVal,min(theMidVal,theRightVal));
        
        if(theMinVal == theLeftVal)
            theMinIndex = i-1;
        else if(theMinVal == theMidVal)
            theMinIndex = i;
        else
            theMinIndex = i+1;
        
        if(theMinIndex !=i){
            int theTemp = aNums[i];
            aNums[i] = aNums[theMinIndex];
            aNums[theMinIndex] = theTemp;
        }
        
    }
}



#endif /* PeaksAndValleys_hpp */
