//
//  PairwiseSwap.hpp
//  Code Practice
//
//  Created by Reid on 6/23/21.
//

#ifndef PairwiseSwap_hpp
#define PairwiseSwap_hpp

#include <stdio.h>
#include <iostream>

int swapOddEventBits(int aVal){
    return (((aVal&0xaaaaaaaa)>>1) | ((aVal&0x55555555)<<1));
}

#endif /* PairwiseSwap_hpp */
