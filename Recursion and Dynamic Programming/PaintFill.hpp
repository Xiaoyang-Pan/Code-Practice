//
//  PaintFill.hpp
//  Code Practice
//
//  Created by Reid on 6/27/21.
//

#ifndef PaintFill_hpp
#define PaintFill_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool paintFill(vector<vector<string>> &aScreen, int aRow,int aCol, string aColorOld, string aColorNew){
    
    if(aRow <0 || aRow >= aScreen.size() || aCol < 0|| aCol >= aScreen[aRow].size())
        return false;
    
    if(aScreen[aRow][aCol] == aColorOld){
        aScreen[aRow][aCol] = aColorNew;
        int direct[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        for(int i = 0 ; i< 4;i++){
            paintFill(aScreen,aRow+direct[i][0],aCol+direct[i][1],aColorOld,aColorNew);
        }
    }
    return true;
}

bool paintFill(vector<vector<string>> aScreen, int aRow,int aCol, string aColor){
    
    if(aScreen[aRow][aCol]==aColor)
    {
        return false;
    }
    
    return paintFill(aScreen,aRow,aCol,aScreen[aRow][aCol],aColor);
}

#endif /* PaintFill_hpp */
