//
//  Patition.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef Patition_hpp
#define Patition_hpp

#include <stdio.h>

ListNode* partition(ListNode* aHead, int x) {

    ListNode* theLessNode = new ListNode(0);
    ListNode* theLargeNode = new ListNode(0);
    ListNode* theLessStar = theLessNode;
    ListNode* theLargeStar = theLargeNode;
    
    while(aHead){
        if(aHead->val >= x){
            theLargeNode->next = aHead;
            theLargeNode = theLargeNode->next;
        }
        else{
            theLessNode->next = aHead;
            theLessNode = theLessNode->next;
        }
        aHead = aHead->next;
    }
    
    
    theLessNode->next = theLargeStar->next;
    theLargeNode->next = nullptr;
    
    return theLessStar->next;
}

ListNode* partition_optimize(ListNode* aNode, int x) {
    ListNode* head = aHead;
    ListNode* tail = aHead;
        
    while(aHead){
        ListNode* next = aHead->next;
        if(aHead->val < x){
            aHead->next  = head;
            head = aHead;
        }
        else
        {
            tail->next = aHead;
            tail = aHead;
        }
    }
    
    tail->next = nullptr;
    return head;
}


#endif /* Patition_hpp */
