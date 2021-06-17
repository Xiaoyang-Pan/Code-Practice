//
//  ReturnKthToLast.hpp
//  Code Practice
//
//  Created by Reid on 6/15/21.
//

#ifndef ReturnKthToLast_hpp
#define ReturnKthToLast_hpp

#include <stdio.h>
#include <iostream>

using namespace std;

//Time Complexity: O(N) where N is the size of the List
//Space Complexity: O(1)
int printKthToLast(ListNode* aHead, int k){
    int theListSize = 0;
    
    ListNode* theTempNode = aHead;
    while(theTempNode){
        theListSize++;
        theTempNode = theTempNode->next;
    }
    
    for(int i =  0;i<theListSize-k;i++)
    {
        aHead = aHead->next;
    }
    
    if(aHead)
        return aHead->val;
    
    return -1;
}

//Time Complexity: O(N) where N is the size of the List
//Space Complexity: O(1)
int printKthToLast_OnePass(ListNode* aHead, int k){
    int theListSize = 0;
    int theKthVal = -1;
    recur_ListNode(aHead,k,theKthVal);
    return theKthVal;
}

int recur_ListNode(ListNode* aCurNode, int k,int& theKthVal){
    if(!aCurNode)
        return 0;
    
    int theKth =recur_ListNode(aCurNode->next)+1;
    if(theKth == k){
        theKthVal = aCurNode->val;
    }
}



#endif /* ReturnKthToLast_hpp */
