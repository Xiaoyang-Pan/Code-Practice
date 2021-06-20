//
//  MinimalTree.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef MinimalTree_hpp
#define MinimalTree_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include "TreeNode.hpp"

using namespace std;

TreeNode* createMinimalBST(vector<int> aVals,int aStart,int aEnd){
    if(aStart < aEnd){
        return nullptr;
    }
    int theMid = aStart+(aEnd-aStart)/2;
    TreeNode* theCurNode = new TreeNode(aVals[theMid]);
    theCurNode->left = createMinimalBST(aVals,aStart,theMid-1);
    theCurNode->right = createMinimalBST(aVals,theMid+1,aEnd);
    return theCurNode;
}

TreeNode* createMinimalBST(vector<int> aVals){
    return createMinimalBST(aVals,0,aVals.size()-1);
}

#endif /* MinimalTree_hpp */
