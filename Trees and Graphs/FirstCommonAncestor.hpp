//
//  FirstCommonAncestor.hpp
//  Code Practice
//
//  Created by Reid on 6/21/21.
//

#ifndef FirstCommonAncestor_hpp
#define FirstCommonAncestor_hpp

#include <stdio.h>
#include <iostream>
#include "TreeNode.hpp"

using namespace std;

TreeNode*  commonAncestor(TreeNode* aNodeP, aNodeQ){
    TreeNode* theTempP = aNodeP;
    TreeNode* theTempQ = aNodeQ;
    
    while(theTempQ != theTempP){
        if(!theTempQ->parent)
            theTempQ = aNodeP;
        else
            theTempQ = theTempQ->parent;
        
        if(!theTempP->parent)
            theTempP = aNodeQ;
        else
            theTempP = theTempP->parent;
    }
    
    return theTempQ;
}

TreeNode* theAncestor;
    
bool findAncestor(TreeNode *aNode,TreeNode *aNodeP, TreeNode *aNodeQ){
    if(!aNode)
        return false;
    
    if(aNode == aNodeP && aNode==aNodeQ){
        theAncestor = aNode;
        return true;
    }
    
    auto theLeft = findAncestor(aNode->left,aNodeP,aNodeQ);
    auto theRight = findAncestor(aNode->right,aNodeP,aNodeQ);
    
    bool isMatched = aNode == aNodeP || aNode == aNodeQ;
    
    if(theLeft+theRight+isMatched>=2){
        theAncestor = aNode;
    }
    return theLeft||theRight||isMatched;
}

TreeNode* commonAncestor(TreeNode* aRoot, TreeNode* aNodeP, TreeNode* aNodeQ)     {
    findAncestor(aRoot,aNodeP,aNodeQ);
    return theAncestor;
}

#endif /* FirstCommonAncestor_hpp */
