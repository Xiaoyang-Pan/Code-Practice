//
//  RemoveDups.hpp
//  Code Practice
//
//  Created by Reid on 6/15/21.
//

#ifndef RemoveDups_hpp
#define RemoveDups_hpp

#include <stdio.h>
#include <iostream>
#include <unordered_set>

using namespace std;

//Time Complexity: O(N^2) where N is the size of the List
//Space Complexity: O(1) constant memory usage
ListNode* deleteDuplicatesUnsorted(ListNode* aHead) {
    ListNode* theCurNode = aHead;
    
    while(theCurNode){
        
        ListNode* theTempNode = theCurNode;
        while(theTempNode->next){
            
            if(theTempNode->next->val == theCurNode->val)
            {
                auto theNext = theTempNode->next;
                theTempNode->next = theNext->next;
                //delete theNext;
            }
            else
            {
                theTempNode = theTempNode->next;
            }
        }
        
        theCurNode = theCurNode->next;
    }
    return aHead;
}

//Time Complexity: O(N) where N is the size of the List
//Space Complexity:  O(N) where N is the size of the List
ListNode* deleteDuplicatesUnsorted_optimize(ListNode* aHead) {
    ListNode* theCurNode = aHead;
    unordered_set<int> theVisitedNodesVals;
    theVisitedNodesVals.insert(aHead->val);
    
    while(theCurNode){
        
        ListNode* theTempNode = theCurNode;
        if(theCurNode->next && theVisitedNodesVals.count(theCurNode->next->val)){
            auto theNext = theTempNode->next;
            theTempNode->next = theNext->next;
            //delete theNext;
        }
        else if(theCurNode->next)
        {
            theVisitedNodesVals.insert(theCurNode->next->val);
            theCurNode = theCurNode->next;
        }
        else{
            theCurNode = theCurNode->next;
        }
    }
    return aHead;
}



#endif /* RemoveDups_hpp */
