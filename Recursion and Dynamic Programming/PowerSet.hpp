//
//  PowerSet.hpp
//  Code Practice
//
//  Created by Reid on 6/27/21.
//

#ifndef PowerSet_hpp
#define PowerSet_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> getSubsets(vector<int> aSet,int anIndex){
    
    vector<vector<int>> theSubsets;
    if(anIndex == -1){
        theSubsets.push_back({});
        return theSubsets;
    }
    
    for(auto theSubset:getSubsets(aSet,anIndex-1)){
        theSubsets.push_back(theSubset);
        vector<int> theNewSubset = theSubset;
        theNewSubset.push_back(aSet[anIndex]);
        theSubsets.push_back(theNewSubset);
    }
    
    return theSubsets;
}

vector<vector<int>> getSubsets(vector<int> aSet){
    
    return getSubsets(aSet,aSet.size()-1);
}

vector<int> findSubset(vector<int> aSet, int aVal){
    
    vector<int> theSubset = {};
    int i = 0;
    while(aVal >0){
        if((aVal&1) == 1){
            theSubset.push_back(aSet[i]);
        }
        aVal>>=1;
        i++;
    }
    return theSubset;
}

vector<vector<int>> getSubsets_binary(vector<int> aSet){
    
    int theMaxSize = 1<<aSet.size();
    vector<vector<int>> theSubsets;
    for(int i = 0; i< theMaxSize;i++){
        theSubsets.push_back(findSubset(aSet,i));
    }
    
    return theSubsets;
}


#endif /* PowerSet_hpp */
