//
//  FlipBitToWin.hpp
//  Code Practice
//
//  Created by Reid on 6/22/21.
//

#ifndef FlipBitToWin_hpp
#define FlipBitToWin_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int longestSequence(int aNum){
    int theCount = 0;
    
    while(aNum>0){
        int theZeroCount= 0;
        int theTempCount=0;
        int theTempVal =aNum;
        
        while(theTempVal >0)
        {
            if((theTempVal&1)==0){
                theZeroCount++;
                if(theZeroCount==2){
                    break;
                }
            }
            theTempCount++;
            theTempVal>>=1;
        }
        theCount = max(theCount,theTempCount);
        aNum>>=1;
    }

    return theCount;
}

int longestSequence_optimize(int aNum)
{
    int theLeftOne = 0;
    int theRightOne = 0;
    int theCount = 0;
    while(aNum>0)
    {
        if((aNum&1) == 1){
            theRightOne++;
            aNum>>=1;
        }
        else{
            aNum>>=1;
            while((aNum&1) == 1){
                theLeftOne++;
                aNum>>=1;
            }
            
            theCount = max(theCount,theLeftOne+theRightOne+1);
            theRightOne = theLeftOne;
            theLeftOne=0;
        }
    }
    
    theCount = max(theCount,theLeftOne+theRightOne+1);
    
    return theCount;
}

#endif /* FlipBitToWin_hpp */
