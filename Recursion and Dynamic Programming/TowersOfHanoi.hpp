//
//  TowersOfHanoi.hpp
//  Code Practice
//
//  Created by Reid on 6/28/21.
//

#ifndef TowersOfHanoi_hpp
#define TowersOfHanoi_hpp

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

void moveDisks(int n, stack<int> &anOrigin, stack<int> &aDest,stack<int> &aBuffer){
    
    if(n<=0)
        return;
    
    moveDisks(n-1, anOrigin, aBuffer,aDest);
    
    int theVal = anOrigin.top();
    anOrigin.pop();
    aDest.push(theVal);
    
    moveDisks(n-1,aBuffer, aDest, anOrigin);
}

#endif /* TowersOfHanoi_hpp */
