//
//  Successor.hpp
//  Code Practice
//
//  Created by Reid on 6/19/21.
//

#ifndef Successor_hpp
#define Successor_hpp

#include <stdio.h>
#include <iostream>

//without parent
TreeNode* inorderSucc(TreeNode* aRoot, TreeNode* aNode) {
    if(aNode->right)
    {
        auto theSuccessor = aNode->right;
        while(theSuccessor->left)
            theSuccessor = theSuccessor->left;
        return theSuccessor;
    }
    
    TreeNode* theSucessor = nullptr;
    TreeNode* theTemp = aRoot;
    
    while(theTemp !=aNode){
        if(theTemp->val > aNode->val){
            theSucessor = theTemp;
            theTemp = theTemp->left;
        }
        else
            theTemp = theTemp->right;
    }
    
    return theSucessor;
}

//with parent
TreeNode* inorderSucc(TreeNode* aNode) {
    if(aNode->right)
    {
        auto theSuccessor = aNode->right;
        while(theSuccessor->left)
            theSuccessor = theSuccessor->left;
        return theSuccessor;
    }
    
    TreeNode* theTemp = aNode->parent;
    
    while(!theTemp){
        if(theTemp->left == aNode)
            return theTemp;
        
        aNode =theTemp;
        theTemp = theTemp->parent;
    }
    
    return nullptr;
}




#endif /* Successor_hpp */
