//
//  SortStack.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef SortStack_hpp
#define SortStack_hpp

#include <stdio.h>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

stack<int> sort_stack(stack<int> aStack){
    if(aStack.size()<=1)
        return aStack;
    stack<int> theTempStack;
    
    for(int i =aStack.size(); i>=1;i--){
        int theMax = INT_MIN;
        for(int j = 0; j <i;j++){
            theMax = max(aStack.top(),theMax);
            theTempStack.push(aStack.top());
            aStack.pop();
        }
        aStack.push(theMax);
        int count = 1;
        while(!theTempStack.empty()){
            if(theTempStack.top() == theMax && count==1){
                theTempStack.pop();
                count-=1;
                continue;
            }
            aStack.push(theTempStack.top());
            theTempStack.pop();
        }
        
    }
    
    return aStack;
    
}

#endif /* SortStack_hpp */
