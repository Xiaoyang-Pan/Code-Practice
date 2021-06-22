//
//  TreeNode.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>
#include <cstdlib>

struct TreeNode{
    TreeNode(int aVal): val(aVal),left(nullptr),right(nullptr),parent(nullptr){
        size = 1;
    }
    
    void insert(int aVal){
        size++;
        if(aVal>val)
        {
            if(!right)
                right = new TreeNode(aVal);
            else
                right->insert(aVal);
        }
        else{
            if(!left)
                left = new TreeNode(aVal);
            else
                left->insert(aVal);
        }
    }
    
    TreeNode* getRandomNode(){
        int theLeftSize = !left ?0 : left->getSize();
        int theRightSize = !right ?0 : right->getSize();
        
        int theRan = rand()%getSize();
        if(theRan ==0)
            return this;
        else if(theRan < theLeftSize+1)
            return left->getRandomNode();
        else
            return right->getRandomNode();
    }
    
    bool find(int aVal){
        if(aVal == val)
            return true;
        else if(aVal>val)
        {
            if(!right)
                return false;
            else
                return right->find(aVal);
        }
        else{
            if(!left)
                return false;
            else
                return left->find(aVal);
        }
    }
    
    int getSize(){
        return size;
    }
    
    int getVal(){
        return val;
    }
    
    int val;
    int size;
    TreeNode* left;
    TreeNode* right;
    TreeNode* parent;
    
};

#endif /* TreeNode_hpp */
