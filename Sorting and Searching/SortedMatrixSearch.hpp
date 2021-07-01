//
//  SortedMatrixSearch.hpp
//  Code Practice
//
//  Created by Reid on 6/30/21.
//

#ifndef SortedMatrixSearch_hpp
#define SortedMatrixSearch_hpp

#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

bool searchMatrix(vector<vector<int>>& aMatrix, int aTarget) {
    int theRow = 0;
    int theCol = aMatrix[0].size()-1;
    
    while(theRow < aMatrix.size() && theCol >=0)
    {
        if(aMatrix[theRow][theCol]==aTarget)
        {
            return true;
        }
        else if(aMatrix[theRow][theCol]>aTarget)
            theCol--;
        else
            theRow++;
    }
    
    return false;
}

#endif /* SortedMatrixSearch_hpp */
