//
//  ListOfDepths.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef ListOfDepths_hpp
#define ListOfDepths_hpp

#include <stdio.h>
#include "TreeNode.hpp"
#include <vector>
#include <iostream>

using namespace std;

vector<vector<TreeNode*>> createLevelLevelNodes(TreeNode* root){
    vector<vector<TreeNode*>> theNodes;
    vector<TreeNode*> theCurNodes({root});
    
    while(!theCurNodes.empty()){
        theNodes.push_back(theCurNodes);
        
        vector<TreeNode*> theNextNodes;
        for(auto theCurNode:theCurNodes){
            if(theCurNode->left)
                theNextNodes.push_back(theCurNode->left);
            if(theCurNode->right)
                theNextNodes.push_back(theCurNode->right);
        }
        
        theCurNodes = theNextNodes;
    }
    return theNodes;
}

#endif /* ListOfDepths_hpp */
