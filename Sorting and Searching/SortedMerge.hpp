//
//  SortedMerge.hpp
//  Code Practice
//
//  Created by Reid on 6/29/21.
//

#ifndef SortedMerge_hpp
#define SortedMerge_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

void merge(vector<int>& aNums1, int aSize1, vector<int>& aNums2, int aSize2) {
    
    int theIndex = aNums1.size()-1;
    aSize2-=1;
    aSize1-=1;
    while(aSize2 >= 0 && aSize1 >=0){
        
        if(aNums1[aSize1] > aNums2[aSize2]){
            aNums1[theIndex] = aNums1[aSize1];
            aSize1-=1;
        }
        else
        {
            aNums1[theIndex] = aNums2[aSize2];
            aSize2-=1;
        }
        theIndex-=1;
    }
    
    while(aSize2 >=0){
        aNums1[theIndex] = aNums2[aSize2];
        theIndex-=1;
        aSize2-=1;
    }
}

#endif /* SortedMerge_hpp */
