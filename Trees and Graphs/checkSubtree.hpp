//
//  checkSubtree.hpp
//  Code Practice
//
//  Created by Reid on 6/21/21.
//

#ifndef checkSubtree_hpp
#define checkSubtree_hpp

#include <stdio.h>
#include <iostream>
#include "TreeNode.hpp"
#include <string>

using namespace std;

void getTreeString(TreeNode* aNode,string& theString){
    if(!aNode)
        theString.push_back('N');
    
    theString.append(to_string(aNode->val));
    theString.push_back(' ');
    getTreeString(aNode->left,theString);
    getTreeString(aNode->right,theString);
}


bool containsTree(TreeNode* aTree1,TreeNode* aTree2){
    if(!aTree2)
        return true;
    
    string theString1, theString2;
    getTreeString(aTree1,theString1);
    getTreeString(aTree2,theString2);
    
    return theString1.find(theString2)!=-1;
    
}

#endif /* checkSubtree_hpp */
