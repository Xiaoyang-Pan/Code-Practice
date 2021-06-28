//
//  Coins.hpp
//  Code Practice
//
//  Created by Reid on 6/27/21.
//

#ifndef Coins_hpp
#define Coins_hpp

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

int makeChanges(int anAmount, vector<int> aCoins, int anIndex){
    if(anIndex == aCoins.size()-1){
        if(anAmount%aCoins[anIndex]!=0)
            return 0;
        return 1;
    }
    
    int theWays = 0;
    for(int theCoinVal = 0; theCoinVal <= anAmount;theCoinVal+=aCoins[anIndex]){
        theWays += makeChanges(anAmount-theCoinVal,aCoins,anIndex+1);
    }
    return theWays;
}

int makeChanges(int anAmount, vector<int> aCoins){
    
    return makeChanges(anAmount,aCoins,0);
}

int rowSize;
int colSize;

int makeChanges(int anAmount, vector<int> aCoins, int anIndex, vector<vector<int>> &aMemo){
    if(anIndex == aCoins.size()-1){
        if(anAmount%aCoins[anIndex]!=0)
            return 0;
        return 1;
    }
    
    if(aMemo[anAmount][anIndex]>0)
        return aMemo[anAmount][anIndex];
    
    int theWays = 0;
    for(int theCoinVal = 0; theCoinVal <= anAmount;theCoinVal+=aCoins[anIndex]){
        theWays += makeChanges(anAmount-theCoinVal,aCoins,anIndex+1);
    }
    
    aMemo[anAmount][anIndex] = theWays;
    return theWays;
}


int makeChanges_optimize(int anAmount, vector<int> aCoins){
    
    rowSize = anAmount+1;
    colSize = aCoins.size();
    vector<vector<int>> theMemo(anAmount+1,vector<int>(aCoins.size(),0));
    return makeChanges(anAmount,aCoins,0,theMemo);
}

#endif /* Coins_hpp */
