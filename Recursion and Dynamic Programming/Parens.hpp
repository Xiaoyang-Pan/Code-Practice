//
//  Parens.hpp
//  Code Practice
//
//  Created by Reid on 6/26/21.
//

#ifndef Parens_hpp
#define Parens_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

void generateParens(string aParen, int aNumOfLeft, int aNumOfRight,vector<string>& aParens){
    
    if(aNumOfLeft ==0 && aNumOfRight ==0){
        aParens.push_back(aParen);
        return;
    }
    
    if(aNumOfLeft){
        aParen.push_back('(');
        generateParens(aParen,aNumOfLeft-1,aNumOfRight,aParens);
        aParen.pop_back();
    }
    if(aNumOfRight > aNumOfLeft){
        aParen.push_back(')');
        generateParens(aParen,aNumOfLeft,aNumOfRight-1,aParens);
        aParen.pop_back();
    }
}

vector<string> generateParens(int aPairOfParens){
    
    if(aPairOfParens <=0)
        return {};
    
    vector<string> theParens;
    generateParens("",aPairOfParens,aPairOfParens,theParens);
    return theParens;
}


#endif /* Parens_hpp */
