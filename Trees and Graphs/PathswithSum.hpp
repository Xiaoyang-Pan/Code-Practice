//
//  PathswithSum.hpp
//  Code Practice
//
//  Created by Reid on 6/21/21.
//

#ifndef PathswithSum_hpp
#define PathswithSum_hpp

#include <stdio.h>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

int getSum(TreeNode* aNode,int aTargetSum,int aCurrentSum,unordered_map<int,int> &aPathCount)
{
    if(!aNode)
        return 0;
    
    aCurrentSum+= aNode->val;
    int thePath = aPathCount[aCurrentSum-aTargetSum];
    
    if(aTargetSum == aCurrentSum)
    {
        thePath++;
    }
    
    aPathCount[aCurrentSum]+=1;
    thePath+=getSum(aNode->left,aTargetSum,aCurrentSum,aPathCount);
    thePath+=getSum(aNode->right,aTargetSum,aCurrentSum,aPathCount);
    aPathCount[aCurrentSum]-=1;

    return thePath;
}

int countPathWithSum_optimize(TreeNode* aRoot, int aTargetSum) {
    unordered_map<int,int> thePathCount;
    return getSum(aRoot,aTargetSum,0,thePathCount);
    //return theCount;
}

int theCount =0;
vector<int> getSum(TreeNode* aNode,int aTargetSum){
    if(!aNode)
        return {};
    
    auto theLeftSum = getSum(aNode->left,aTargetSum);
    auto theRightSum = getSum(aNode->right,aTargetSum);
    
    theLeftSum.insert(theLeftSum.end(),theRightSum.begin(),theRightSum.end());
    
    for(int i = 0;  i < theLeftSum.size();i++){
        theLeftSum[i]+=aNode->val;
        if(theLeftSum[i] == aTargetSum)
            theCount+=1;
    }
    
    theLeftSum.push_back(aNode->val);
    
    if(aNode->val==aTargetSum)
        theCount+=1;
    
    return theLeftSum;
}

int countPathWithSum(TreeNode* aRoot, int aTargetSum) {
    getSum(aRoot,aTargetSum);
    return theCount;
}


#endif /* PathswithSum_hpp */
