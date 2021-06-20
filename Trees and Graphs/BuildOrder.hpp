//
//  BuildOrder.hpp
//  Code Practice
//
//  Created by Reid on 6/19/21.
//

#ifndef BuildOrder_hpp
#define BuildOrder_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

vector<string> findBuildOrder(vector<string> aProjects,vector<vector<string>> aDependecies){
    
    unordered_map<string,vector<string>> theDependcies;
    unordered_map<string,int> theParents;
    
    for(auto theEdges:aDependecies){
        theDependcies[theEdges[0]].push_back(theEdges[1]);
        theParents[theEdges[1]]++;
    }
    
    vector<string> theBuildOrder;
    vector<string> theAvaiNodes;
    
    for(auto theProject:aProjects){
        if(theParents[theProject]==0){
            theAvaiNodes.push_back(theProject);
            theBuildOrder.push_back(theProject);
        }
    }
    
    while(!theAvaiNodes.empty()){
        vector<string> theNextAvail;
        for(auto theAvai:theAvaiNodes){
            
            for(auto theNode: theDependcies[theAvai])
            {
                theParents[theNode]--;
                if(theParents[theNode]==0){
                    theNextAvail.push_back(theNode);
                    theBuildOrder.push_back(theNode);
                }
            }
        }
        theAvaiNodes = theNextAvail;
    }
    
    if(aProjects.size()==theBuildOrder.size())
        return theBuildOrder;
    
    return {};
}

#endif /* BuildOrder_hpp */
