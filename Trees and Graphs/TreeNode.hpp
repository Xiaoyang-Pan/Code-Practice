//
//  TreeNode.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

struct TreeNode{
    TreeNode(int aVal): val(aVal),left(nullptr),right(nullptr),parent(nullptr){
    }
    
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
};

#endif /* TreeNode_hpp */
