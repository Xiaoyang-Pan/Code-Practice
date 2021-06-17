//
//  Palindrome.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef Palindrome_hpp
#define Palindrome_hpp

#include <stdio.h>

bool isPalindrome(ListNode* aHead) {
        
    ListNode* theReverse = nullptr;
    ListNode* theStart = aHead;
    int theSize = 0;
    while(aHead){
        ListNode* theCur = new ListNode(aHead->val);
        theCur->next = theReverse;
        theReverse = theCur;
        aHead= aHead->next;
        theSize ++;
    }
    int i =0;
    while(theReverse && i < theSize/2){
        if(theReverse->val !=theStart->val){
            return false;
        }
        theReverse = theReverse->next;
        theStart = theStart->next;
        i++;
    }
    
    return true;
    
}



bool result =true;
ListNode* CompareNode(ListNode* aNode, int aListSize, int aDepth){
    if((aListSize+1)/2 == aDepth){
        return aNode;
    }
            
    ListNode* theRNode;
    if((aListSize)/2 == aDepth)
        theRNode = aNode;
    else
        theRNode = CompareNode(aNode->next,aListSize, aDepth+1);
    
    if(!theRNode)
        return nullptr;
    
    if(aNode->val != theRNode->val){
        result = false;
        return nullptr;
    }
    return theRNode->next;
}

bool isPalindrome_optimize(ListNode* aHead) {
    result = true;
    int theListSize= 0;
    ListNode* theTempNode = aHead;
    while(theTempNode){
        theTempNode= theTempNode->next;
        theListSize++;
    }
    
    CompareNode(aHead,theListSize,0);
    return result;
}



#endif /* Palindrome_hpp */
