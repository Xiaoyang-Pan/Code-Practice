//
//  Insertion.hpp
//  Code Practice
//
//  Created by Reid on 6/22/21.
//

#ifndef Insertion_hpp
#define Insertion_hpp

#include <stdio.h>
#include <bitset>
#include "FlipBitToWin.hpp"
//#include <iostream>

using namespace std;

int updateBits(int aNum1,int aNum2, int aEnd, int aStart){
    
    if(aEnd > aStart || aEnd < 0 || aStart >= 32)
        return 0;
        
    int theUpdateVal;
    int mask1 = aStart<31?(-1 <<aStart+1):0;
    int mask2 = (1<<aEnd)-1;
    
    theUpdateVal = (aNum1 & mask1) | (aNum1 & mask2);
    theUpdateVal = theUpdateVal | (aNum2 << aEnd);
    
    return 0;
}

#endif /* Insertion_hpp */
