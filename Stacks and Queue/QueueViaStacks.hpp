//
//  QueueViaStacks.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef QueueViaStacks_hpp
#define QueueViaStacks_hpp

#include <stdio.h>
#include <stack>
#include <iostream>

using namespace std;
class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int aVal) {
        stack1.push(aVal);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int theVal = peek();
        stack2.pop();
        return theVal;
    }
    
    /** Get the front element. */
    int peek() {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        
        return stack2.top();

    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
    stack<int> stack1;
    stack<int> stack2;
};
#endif /* QueueViaStacks_hpp */
