//
//  BinaryToString.hpp
//  Code Practice
//
//  Created by Reid on 6/22/21.
//

#ifndef BinaryToString_hpp
#define BinaryToString_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

string printBinary(double aNum){
    if(aNum <=0 || aNum >= 1)
        return "Error";
    
    string theBinary(".");
    double theExp = 0.5;
    while(aNum > 0)
    {
        if(theBinary.size() >= 32)
            return "Error";
        
        if(aNum >= theExp){
            theBinary.push_back('1');
            aNum-=theExp;
        }
        else{
            theBinary.push_back('0');
        }
        theExp *=0.5;
    }
    
    return theBinary;
}

#endif /* BinaryToString_hpp */
