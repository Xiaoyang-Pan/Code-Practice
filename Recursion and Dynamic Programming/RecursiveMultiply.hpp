//
//  RecursiveMultiply.hpp
//  Code Practice
//
//  Created by Reid on 6/25/21.
//

#ifndef RecursiveMultiply_hpp
#define RecursiveMultiply_hpp

#include <stdio.h>
#include <iostream>

using namespace std;
int product =0;

void getProduct(int aLarNum, int& aSmaNum,int aProduct,int aMultiple){
    
    if(aMultiple > aSmaNum)
        return;
    
    getProduct(aLarNum,aSmaNum,aProduct<<1,aMultiple<<1);
    if(aSmaNum-aMultiple>=0){
        aSmaNum-=aMultiple;
        product+=aProduct;
    }
}

int minProduct(int aNum1, int aNum2){
    product = 0;
    if(aNum2 == 0)
        return 0;
    
    if(aNum1 < aNum2)
        return minProduct(aNum2,aNum1);
    
    int theProduct = aNum1;
    getProduct(aNum1, aNum2, theProduct,1);
    return product;
}

int getProduct_BottomUp(int aLarNum, int aSmaNum){
    
    if(aSmaNum ==0)
        return 0;
    if(aSmaNum ==1)
        return aLarNum;
    
    int theNewSmall = aSmaNum>>1;
    
    int theHalfSum = getProduct_BottomUp(aLarNum,theNewSmall);
    if(theNewSmall == aSmaNum-theNewSmall)
        return theHalfSum+theHalfSum;
    else
        return theHalfSum+theHalfSum+aLarNum;
}

int minProduct_BottomUp(int aNum1, int aNum2){
    if(aNum2 == 0)
        return 0;
    
    if(aNum1 < aNum2)
        return minProduct_BottomUp(aNum2,aNum1);
    
    return getProduct_BottomUp(aNum1,aNum2);
}

#endif /* RecursiveMultiply_hpp */
