//
//  isUnique.h
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef isUnique_h
#define isUnique_h

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>


using namespace std;

//Brute Force
//Compare one charact with all other characters
//Time Complexsity: O(N^2), N is the size of aStr
//Space Complexity: O(1), no additional memory usage

//Time Complexsity: O(Nlog(N)), N is the size of aStr
//Space Complexity: O(N), memory for sorting
bool isUniqueChar_Sorting(string aStr){
    sort(aStr.begin(),aStr.end());
    
    for(int i = 1; i< aStr.size();i++)
    {
        if(aStr[i] = aStr[i-1])
        {
            return false;
        }
    }
    return true;
}

//Time Complexsity: O(N)), N is the size of aStr
//Space Complexity: O(1), constant memory
bool isUniqueChar_Array(string aStr){
    if(aStr.size()>128)
        return false;
    
    bool theCharacters[128] = {false};
    
    for(auto theChara:aStr)
    {
        if(theCharacters[theChara])
            return false;
        theCharacters[theChara] = true;
    }
    return true;
}






#endif /* isUnique_h */
