//
//  RobotInAGrid.hpp
//  Code Practice
//
//  Created by Reid on 6/24/21.
//

#ifndef RobotInAGrid_hpp
#define RobotInAGrid_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_set>
#include <set>

using namespace std;

bool getPath(vector<vector<bool>>& aMaze, int aRow, int aCol, vector<pair<int,int>>& aPath){
    
    //cout << aRow << " "<< aCol<<endl;
    if(aRow <0 || aCol<0 || !aMaze[aRow][aCol]){
        return false;
    }
    
    bool isPath = false;
    if(aRow ==0 &&  aCol==0)
    {
        isPath = true;
    }
    
    if(isPath || getPath(aMaze, aRow-1,aCol,aPath) || getPath(aMaze,aRow,aCol-1,aPath))
    {
        aPath.push_back({aRow,aCol});
        return true;
    }
    
    return false;
}

vector<pair<int,int>> getPath(vector<vector<bool>> aMaze){
    
    if(aMaze.size() == 0)
        return {};
    
    vector<pair<int,int>> thePath;
    int theM = aMaze.size()-1;
    int theN = aMaze[0].size()-1;
    getPath(aMaze,theM,theN,thePath);
    return thePath;
}

bool getPath_optimize(vector<vector<bool>>& aMaze, int aRow, int aCol, vector<pair<int,int>> &aPath, set<pair<int,int>> &aVisited){
    
    if(aRow<0 || aCol < 0 || !aMaze[aRow][aCol]){
        return false;
    }
    
    pair<int,int> theCoord ={aRow,aCol};
    if(aVisited.count(theCoord))
    {
        return false;
    }
    
    if((aRow == 0 && aCol == 0) || getPath_optimize(aMaze,aRow-1,aCol,aPath,aVisited) || getPath_optimize(aMaze,aRow,aCol-1,aPath,aVisited))
    {
        aPath.push_back(theCoord);
        return true;
    }
    
    aVisited.insert(theCoord);
    return false;
}

vector<pair<int,int>> getPath_optimize(vector<vector<bool>> aMaze){
    if(aMaze.size() == 0)
        return {};
    
    vector<pair<int,int>> thePath;
    set<pair<int,int>> theVisited;
    getPath_optimize(aMaze, aMaze.size()-1,aMaze[0].size()-1,thePath,theVisited);
    return thePath;
}




#endif /* RobotInAGrid_hpp */
