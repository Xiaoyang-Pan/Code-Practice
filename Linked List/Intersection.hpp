//
//  Intersection.hpp
//  Code Practice
//
//  Created by Reid on 6/16/21.
//

#ifndef Intersection_hpp
#define Intersection_hpp

#include <stdio.h>

ListNode *findIntersection_hash(ListNode *aHeadA, ListNode *aHeadB) {
        
    set <ListNode*> theNodes_in_B;
        
    while (aHeadB != nullptr)
    {
        theNodes_in_B.insert(aHeadB);
        aHeadB = aHeadB->next;
    }
        
    while (aHeadA != nullptr)
    {
        if(theNodes_in_B.find(aHeadA) != theNodes_in_B.end())
        {
            return aHeadA;
        }
        aHeadA = aHeadA->next;
    }
        return nullptr;
}

ListNode *findIntersection(ListNode *aHeadA, ListNode *aHeadB) {
        
    ListNode* theTempb = aHeadB;
    ListNode* theTempa = aHeadA;

    while (theTempa && theTempb)
    {
        if (theTempa == theTempb)
            return theTempa;
        if (theTempa->next == nullptr && theTempb->next == nullptr)
            return nullptr;

        if (theTempa->next == nullptr)
            theTempa = aHeadB;
        else
            theTempa = theTempa->next;

        if (theTempb->next == nullptr)
            theTempb = aHeadA;
        else
            theTempb = theTempb->next;
    }

    return nullptr;
}

int getListSize(ListNode* aNode){
        int theSize = 0;
        while(aNode){
            aNode = aNode->next;
            theSize++;
        }
            
        return theSize;
    }
    
ListNode *findIntersection_optimize(ListNode *aHeadA, ListNode *aHeadB) {
    ListNode* theTempA = aHeadA;
    ListNode* theTempB = aHeadB;
    
    int theHeadASize = getListSize(theTempA);
    int theHeadBSize = getListSize(theTempB);

    while(theHeadASize > theHeadBSize){
        aHeadA = aHeadA->next;
        theHeadASize--;
    }
    
    while(theHeadASize < theHeadBSize){
        aHeadB = aHeadB->next;
        theHeadBSize--;
    }
    
    while(aHeadA){
        if(aHeadA == aHeadB){
            return aHeadA;
        }
        aHeadA = aHeadA->next;
        aHeadB = aHeadB->next;
    }
    return nullptr;
}

#endif /* Intersection_hpp */
