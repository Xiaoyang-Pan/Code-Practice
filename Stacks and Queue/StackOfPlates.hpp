//
//  StackOfPlates.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef StackOfPlates_hpp
#define StackOfPlates_hpp

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

class DinnerPlates{
    DinnerPlates(int aCapacity) {
        capacity = aCapacity;
    }
    
    void push(int aVal) {
        
        if(unFullPlate.empty()){
            plateStacks.push_back(stack<int>());
            unFullPlate.insert(plateStacks.size()-1);
        }
        int theIndex = *unFullPlate.begin();
        plateStacks[theIndex].push(aVal);
        
        if(plateStacks[theIndex].size() == capacity)
            unFullPlate.erase(unFullPlate.begin());
    }
    
    int pop() {
        if(plateStacks.empty()){
            return -1;
        }
        
        if(!plateStacks.empty() && plateStacks.back().size() == capacity)
            unFullPlate.insert(plateStacks.size()-1);
        
        int theVals = plateStacks.back().top();
        plateStacks.back().pop();
        
        while(!plateStacks.empty() && plateStacks.back().empty()){
            unFullPlate.erase(--unFullPlate.end());
            plateStacks.pop_back();
        }

        return theVals;
    }
    
    int popAtStack(int anIndex) {

        if(anIndex < 0 || anIndex > plateStacks.size() || plateStacks[anIndex].empty())
            return -1;
        
        if(anIndex == plateStacks.size()-1)
        {
            return pop();
        }

        int theVal = plateStacks[anIndex].top();
        plateStacks[anIndex].pop();
        unFullPlate.insert(anIndex);

        return theVal;
        
    }
    
    int capacity;
    set<int> unFullPlate;
    vector<stack<int>> plateStacks;
};

#endif /* StackOfPlates_hpp */
