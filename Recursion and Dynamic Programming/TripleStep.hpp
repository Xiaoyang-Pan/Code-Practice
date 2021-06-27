//
//  TripleStep.hpp
//  Code Practice
//
//  Created by Reid on 6/24/21.
//

#ifndef TripleStep_hpp
#define TripleStep_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

int countWays(int aNum){
    
    if(aNum < 0){
        return 0;
    }
    
    else if(aNum ==0)
        return 1;
    else
        return countWays(aNum-1) + countWays(aNum-2)+countWays(aNum-3);
}

int countWays_optimize(int aNum){
    int theMemo[aNum+1];
    theMemo[0] = 1;
    theMemo[1] = 1;
    theMemo[2] = 2;
    
    for(int i = 3; i<=aNum+1;i++){
        theMemo[i] = theMemo[i-1]+theMemo[i-2]+theMemo[i-3];
    }
    return theMemo[aNum];
}

#endif /* TripleStep_hpp */
