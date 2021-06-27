//
//  PermutationsWithoutDups.hpp
//  Code Practice
//
//  Created by Reid on 6/25/21.
//

#ifndef PermutationsWithoutDups_hpp
#define PermutationsWithoutDups_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> getPerms(string aString){
    if(aString.size()==0)
        return {};
    if(aString.size()==1)
        return {aString};
    
    char theChar = aString.back();
    aString.pop_back();
    vector<string> theStrings= getPerms(aString);
    
    vector<string> thePermu;
    for(auto theString:theStrings){
        for(int i = 0; i<=theString.size();i++){
            string theTemp = theString.substr(0,i);
            theTemp.push_back(theChar);
            theTemp.append(theString.substr(i));
            thePermu.push_back(theTemp);
        }
    }
    return thePermu;
}

vector<string> getPerms_alternative(string aString){
    if(aString.size()==0)
        return {};
    if(aString.size()==1)
        return {aString};
    
    vector<string> theStrings;

    for(int i = 0; i< aString.size();i++){
        char theChar = aString[i];
        string theTemp = aString.substr(0,i);
        theTemp.append(aString.substr(i+1));
        auto thePerms = getPerms_alternative(theTemp);
        
        for(auto thePerm:thePerms){
            thePerm.push_back(theChar);
            theStrings.push_back(thePerm);
        }
    }
    
    return theStrings;
}

#endif /* PermutationsWithoutDups_hpp */
