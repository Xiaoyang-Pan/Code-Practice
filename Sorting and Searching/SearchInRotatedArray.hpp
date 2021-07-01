//
//  SearchInRotatedArray.hpp
//  Code Practice
//
//  Created by Reid on 6/29/21.
//

#ifndef SearchInRotatedArray_hpp
#define SearchInRotatedArray_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

int search(vector<int>& aNums, int aTarget) {
        
        int theStart= 0;
        int theEnd = aNums.size()-1;
        
        while(theStart <= theEnd){
            
            int theMid = theStart+ (theEnd-theStart)/2;
            if(aNums[theMid] == aTarget)
                return theMid;
            
            if(aNums[theMid] >= aNums[theStart]){
                if(aTarget >= aNums[theStart] && aTarget <aNums[theMid])
                    theEnd = theMid-1;
                else
                    theStart = theMid+1;
            }
            else
            {
                if(aTarget > aNums[theMid] && aTarget <= aNums[theEnd])
                    theStart = theMid+1;
                else
                    theEnd = theMid-1;
            }
            
        }
        return -1;
    }

#endif /* SearchInRotatedArray_hpp */
