//
//  SumLists.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef SumLists_hpp
#define SumLists_hpp

#include <stdio.h>

ListNode* addTwoList(ListNode* aNode1, ListNode* aNode2) {
    
    if(!aNode1)
        return aNode2;
    if(!aNode2)
        return aNode1;
    
    ListNode* theStartNode = new ListNode(0);
    ListNode* theCurNode = theStartNode;
    int carry =0;
    
    while(aNode1 && aNode2){
        int theVal = aNode1->val+aNode2->val+carry;
        theCurNode->next = new ListNode(theVal%10);
        carry = theVal/10;
        aNode1 = aNode1->next;
        aNode2 = aNode2->next;
        theCurNode = theCurNode->next;
    }
    
    while(aNode1){
        int theVal = aNode1->val+carry;
        theCurNode->next = new ListNode(theVal%10);
        carry = theVal/10;
        aNode1 = aNode1->next;
        theCurNode = theCurNode->next;
    }
    
    while(aNode2){
        int theVal = aNode2->val+carry;
        theCurNode->next= new ListNode(theVal%10);
        carry = theVal/10;
        aNode2 = aNode2->next;
        theCurNode = theCurNode->next;
    }
    if(carry){
        theCurNode->next= new ListNode(1);
    }
    
    return theStartNode->next;
}


ListNode* zeroPaddedList(ListNode* aNode,int aSize){
        for(int i =0; i < aSize;i++){
            ListNode* theZeroNode = new ListNode(0);
            theZeroNode->next = aNode;
            aNode = theZeroNode;
            if(i == aSize-1)
                return theZeroNode;
        }
        return nullptr;
    }
    
    pair<ListNode*,int> addSum(ListNode* aNode1, ListNode* aNode2){
        if(!aNode1 || !aNode2)
            return {nullptr,0};
        
        auto theNodeCarry = addSum(aNode1->next,aNode2->next);
        int theSum = aNode1->val+aNode2->val+theNodeCarry.second;
        ListNode* theCurNode = new ListNode(theSum%10);
        theCurNode->next = theNodeCarry.first;
        return {theCurNode,theSum/10};
    }
    
    ListNode* addTwoNumbers_reverse(ListNode* aNode1, ListNode* aNode2) {
        int theNode1Size = 0;
        int theNode2Size = 0;
        
        ListNode* theTempNode = aNode1;
        while(theTempNode){
            theNode1Size++;
            theTempNode= theTempNode->next;
        }
        theTempNode = aNode2;
        while(theTempNode){
            theNode2Size++;
            theTempNode= theTempNode->next;
        }
        
        if(theNode1Size<theNode2Size){
            aNode1 = zeroPaddedList(aNode1,theNode2Size-theNode1Size);
        }
        else if(theNode1Size>theNode2Size){
            aNode2 = zeroPaddedList(aNode2,theNode1Size-theNode2Size);
        }
        
        ListNode* temp = aNode2;
        while(temp){
            temp = temp->next;
        }
        
        auto theResult = addSum(aNode1,aNode2);
        if(theResult.second){
            ListNode* theStartNode = new ListNode(1);
            theStartNode->next = theResult.first;
            return theStartNode;
        }
        return theResult.first;
    }





#endif /* SumLists_hpp */
