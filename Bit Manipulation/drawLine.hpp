//
//  drawLine.hpp
//  Code Practice
//
//  Created by Reid on 6/23/21.
//

#ifndef drawLine_hpp
#define drawLine_hpp

#include <stdio.h>
#include <iostream>
#include <cstdint>

using namespace std;

//uint8_t [] aScreen
void drawLine(uint8_t aScreen[],int aWidth, int aX1, int aX2, int aY){
    
    int theStartOffset = aX1 % 8;
    int theFirstFullByte = aX1/8;
    
    if(theStartOffset != 0){
        theFirstFullByte +=1;
    }
    
    int theEndOffset = aX2%8;
    int theEndFullByte = aX2/8;
    
    if(theEndOffset!=7)
    {
        theEndFullByte-=1;
    }
    
    for(int i = theFirstFullByte; i <= theEndFullByte;i++){
        aScreen[i] = 0xff;
    }
    
    if(aX1/8 == aX2/8){
        uint8_t theMask = (0xff>>theStartOffset) | (0xff <<(7-theEndOffset));
        aScreen[aWidth/8*aY + aX1/8] |= theMask;
    }
    else{
        if(theStartOffset != 0){
            aScreen[aWidth/8*aY + aX1/8] |= (0xff>>theStartOffset);
        }
        if(theEndOffset!=7){
            aScreen[aWidth/8*aY + aX2/8] |= (0xff <<(7-theEndOffset));
        }
    }
}

#endif /* drawLine_hpp */
