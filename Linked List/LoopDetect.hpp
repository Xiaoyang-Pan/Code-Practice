//
//  LoopDetect.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef LoopDetect_hpp
#define LoopDetect_hpp

#include <stdio.h>


ListNode* findBeginning(ListNode* aHead){
    
    ListNode* theSlowNode = aHead;
    ListNode* theFastNode = aHead;
    
    while(theFastNode && theFastNode->next){
        theSlowNode = theSlowNode->next;
        theFastNode = theFastNode->next->next;
        
        if(theSlowNode == theFastNode){
            break;
        }
    }
    
    if(theFastNode == nullptr || theFastNode->next){
        return nullptr;
    }
    
    theSlowNode = aHead;
    while(theSlowNode !=theFastNode){
        theSlowNode = theSlowNode->next;
        theFastNode = theFastNode->next;
    }
    
    return theSlowNode;
}

#endif /* LoopDetect_hpp */
