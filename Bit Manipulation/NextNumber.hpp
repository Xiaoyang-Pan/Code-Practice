//
//  NextNumber.hpp
//  Code Practice
//
//  Created by Reid on 6/23/21.
//

#ifndef NextNumber_hpp
#define NextNumber_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

int getNext(int aVal)
{
    int theZeroCount = 0;
    int theOneCount = 0;
    int theTemp = aVal;
    
    int theZeroIndex =-1;
    while(theTemp>0){
        if((theTemp&1)==1){
            theOneCount++;
            theTemp>>=1;
        }
        else{
            if(theZeroIndex!=-1)
                break;
            
            while((theTemp&1)==0){
                theZeroCount++;
                theTemp>>=1;
            }
            theZeroIndex =0;
        }
    }
    
    if(theZeroCount+theOneCount==31 || theZeroCount+theOneCount==0)
        return -1;
    
    int theBit =theOneCount+theZeroCount;
    aVal = aVal | (1<<theBit);
    aVal = aVal & (-1<<theBit);
    aVal = aVal | ((1<<(theOneCount-1))-1);
    
    return aVal;
    
}

int getPrev(int aVal)
{
    int theZeroCount = 0;
    int theOneCount = 0;
    int theTemp = aVal;
    
    int theOneIndex =-1;
    while(theTemp>0){
        if((theTemp&1)==0){
            theZeroCount++;
            theTemp>>=1;
        }
        else{
            if(theOneIndex!=-1)
                break;
            
            while((theTemp&1)==1){
                theOneCount++;
                theTemp>>=1;
            }
            theOneIndex =0;
        }
    }
    
    if(theZeroCount+theOneCount==31 || theZeroCount+theOneCount==0)
        return -1;
    
    int theBit =theOneCount+theZeroCount;
    aVal = aVal &(-1<<theBit+1);
    int theOnes = (1<<(theOneCount+1))-1;
    aVal = aVal | (theOnes<<theZeroCount-1);
    
    return aVal;
}

#endif /* NextNumber_hpp */
