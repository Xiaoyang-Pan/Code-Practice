//
//  DeleteMiddleNode.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef DeleteMiddleNode_hpp
#define DeleteMiddleNode_hpp

#include <stdio.h>

//Time Complexity: O(1)
//Space Complexity: O(1)

bool deleteNode(ListNode* aNode){
    if(!aNode || !aNode->next){
        return false
    }
    
    auto theMidNode =  aNode->next;
    aNode->next = theMidNode->next;
    //delete theMidNode;
    return true;
}

#endif /* DeleteMiddleNode_hpp */
