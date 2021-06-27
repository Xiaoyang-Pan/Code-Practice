//
//  MagicIndex.hpp
//  Code Practice
//
//  Created by Reid on 6/25/21.
//

#ifndef MagicIndex_hpp
#define MagicIndex_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

int magicIndex_NoDup(vector<int> aNums){
    for(int i = 0; i < aNums.size();i++)
    {
        if(i == aNums[i]){
            return i;
            break;
        }
    }
    return -1;
}

int magicIndex_NoDup_Optimize(vector<int> aNums){
    
    int theStart = 0;
    int theEnd = aNums.size()-1;
    
    while(theStart < theEnd)
    {
        int theMid = theStart+(theEnd-theStart)/2;
        if(theMid = aNums[theMid])
            return theMid;
        else if(theMid < aNums[theMid])
            theEnd = theMid-1;
        else
            theStart = theMid+1;
    }
    return -1;
}

int findMagicIndex(vector<int>aNums, int aStart,int aEnd){
    
    if(aStart <aEnd)
        return -1;
    
    int theMid = aStart + (aEnd-aStart)/2;
    if(theMid == aNums[theMid])
        return theMid;
    
    int theLeft  = min(theMid-1,aNums[theMid]);
    int theIndex;
    if((theIndex=findMagicIndex(aNums,aStart,theLeft))!=-1)
    {
        return theIndex;
    }
    
    int theRight = max(theMid+1,aNums[theMid]);
    if((theIndex=findMagicIndex(aNums,theRight,aEnd))!=-1)
    {
        return theIndex;
    }
    return -1;
}

int magicIndex_WithDup_Optimize(vector<int> aNums){
    
    int theStart = 0;
    int theEnd = aNums.size()-1;
    
    while(theStart < theEnd)
    {
        int theMid = theStart+(theEnd-theStart)/2;
        if(theMid = aNums[theMid])
            return theMid;
        else if(theMid < aNums[theMid])
            theEnd = theMid-1;
        else
            theStart = theMid+1;
    }
    return -1;
}

#endif /* MagicIndex_hpp */
