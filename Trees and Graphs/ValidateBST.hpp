//
//  ValidateBST.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef ValidateBST_hpp
#define ValidateBST_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <iostream>

using namespace std;

bool checkBST(TreeNode* aNode, int aMin,int aMax){
    if(!aNode)
        return true;
    
    if(aNode->val < aMin || aNode->val > aMax)
        return false;
    
    return checkBST(aNode->left, aMin, aNode->val) && checkBST(aNode->right,aNode->val,aMax);
}

bool checkBST(TreeNode* aRoot){
    return checkBST(aRoot, INT_MIN,INT_MAX);
}

#endif /* ValidateBST_hpp */
