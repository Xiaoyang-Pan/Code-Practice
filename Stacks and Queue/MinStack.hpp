//
//  MinStack.hpp
//  Code Practice
//
//  Created by Reid on 6/17/21.
//

#ifndef MinStack_hpp
#define MinStack_hpp

#include <stdio.h>
#include <stack>
#include <iostream>
#include <algorithm>

using namespace std;

class MinStack{
public:
    
    MinStack(){
    }
    
    ~MinStack(){
    }
    
    void push(int aValue){
        valStack.push(aValue);
        if(minStack.empty())
        {
            minStack.push(aValue);
        }
        else{
            int theMin = std::min(aValue,minStack.top());
            minStack.push(theMin);
        }
    }
    
    void pop(){
        if(valStack.empty())
            return;
        minStack.pop();
        valStack.pop();
    }
    
    int top(){
        return valStack.top();
    }
    
    int min(){
        return minStack.top();
    }
    
    stack<int> minStack;
    stack<int> valStack;
};

#endif /* MinStack_hpp */
