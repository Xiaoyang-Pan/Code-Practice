//
//  Conversion.hpp
//  Code Practice
//
//  Created by Reid on 6/22/21.
//

#ifndef Conversion_hpp
#define Conversion_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

int bitSwapRequired(int aNum1, int aNum2){
    
    int theXor = aNum1^aNum2;
    int theCount = 0;
    while(theXor > 0){
        if((theXor&1)==1)
            theCount++;
        theXor>>=1;
    }
    return theCount;
}

#endif /* Conversion_hpp */
