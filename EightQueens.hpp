//
//  EightQueens.hpp
//  Code Practice
//
//  Created by Reid on 6/28/21.
//

#ifndef EightQueens_hpp
#define EightQueens_hpp

#include <stdio.h>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

void printQueens(vector<vector<int>> &aGrid)
{
    for(auto theRow:aGrid){
        for(auto thePiece:theRow){
            cout << thePiece <<" ";
        }
        cout << endl;
    }
}

void placeQueens(vector<vector<int>> &aGrid,int aRow,vector<bool> &aColWithQueen, vector<bool> &aLeftDiaWithQueen,vector<bool> &aRightDiaWithQueen,int aQueenNum){
    if(aQueenNum == 8){
        printQueens(aGrid);
        cout << endl;
        return;
    }
    
    for(int i = 0 ; i< aGrid[aRow].size();i++){
        
        if(aColWithQueen[i] || aLeftDiaWithQueen[i+7-aRow] || aRightDiaWithQueen[aRow+i])
            continue;
        
        aGrid[aRow][i] = 1;
        aColWithQueen[i] = true;
        aLeftDiaWithQueen[i+7-aRow] = true;
        aRightDiaWithQueen[aRow+i] = true;
        placeQueens(aGrid,aRow+1,aColWithQueen,aLeftDiaWithQueen,aRightDiaWithQueen,aQueenNum+1);
        aLeftDiaWithQueen[i+7-aRow] = false;
        aRightDiaWithQueen[aRow+i] = false;
        aColWithQueen[i] = false;
        aGrid[aRow][i] = 0;
    }
    
}

void placeQueens(int aNumOfQueen){
    vector<vector<int>> theGrid(aNumOfQueen,vector<int>(aNumOfQueen,0));
    vector<bool> theColWithQueen(aNumOfQueen,false);
    vector<bool> theLeftDiaWithQueen(aNumOfQueen*2-1,false);
    vector<bool> theRightDiaWithQueen(aNumOfQueen*2-1,false);
    placeQueens(theGrid, 0, theColWithQueen, theLeftDiaWithQueen,theRightDiaWithQueen, 0);
}

#endif /* EightQueens_hpp */
