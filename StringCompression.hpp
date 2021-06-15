//
//  StringCompression.hpp
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef StringCompression_hpp
#define StringCompression_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <utility>


//TimeComplexity: O(N), where N is the size of the input str
//SpaceComplexity: O(N), new temporary string is used to store information
string compressedString(string aStr)
{
    if(aStr.length() <=1)
        return aStr;
    
    int theCount =1;
    string theCompressedStr("");
    for(int i = 0; i < aStr.length()-1;i++){
        if(aStr[i] != aStr[i+1]){
            theCompressedStr.push_back(aStr[i]);
            theCompressedStr.append(to_string(theCount));
            theCount =1;
        }
        else{
            theCount +=1;
        }
    }
    
    theCompressedStr.push_back(aStr[aStr.length()-1]);
    theCompressedStr.append(to_string(theCount));
    
    if(theCompressedStr.size() >= aStr.size())
        return aStr;
    
    return theCompressedStr;
}




#endif /* StringCompression_hpp */
