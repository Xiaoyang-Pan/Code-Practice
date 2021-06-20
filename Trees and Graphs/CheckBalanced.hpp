//
//  CheckBalanced.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef CheckBalanced_hpp
#define CheckBalanced_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

int compareHeight(TreeNode* aNode, bool &anIsBalanced){
    if(!aNode)
        return 0;
    
    if(!anIsBalanced)
        return -3;
    
    int theLeftHeight = compareHeight(aNode->left,anIsBalanced);
    int theRightHeight = compareHeight(aNode->right,anIsBalanced);
    
    int theHeight = abs(theLeftHeight-theRightHeight);
    
    if(theHeight>1)
        anIsBalanced = false;

    return max(theLeftHeight,theRightHeight)+1;
}

bool isBalanced(TreeNode* aRoot) {
    bool theIsBalanced = true;
    compareHeight(aRoot,theIsBalanced);
    return theIsBalanced;
}

#endif /* CheckBalanced_hpp */
