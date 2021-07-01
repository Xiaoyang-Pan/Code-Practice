//
//  GroupAnagram.hpp
//  Code Practice
//
//  Created by Reid on 6/29/21.
//

#ifndef GroupAnagram_hpp
#define GroupAnagram_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& aStrs) {
    vector<vector<string>> theGroups;
    unordered_map<string,int> theGroupIndex;
    
    for(auto theStr:aStrs){
        
        int theVal[26] = {0};
        for(auto theChar:theStr)
            theVal[theChar-'a']+=1;
        
        string theStrVal;
        for(auto theCharVal:theVal){
            theStrVal+=theCharVal;
            theStrVal.push_back('-');
        }
        
        if(theGroupIndex.count(theStrVal)){
            theGroups[theGroupIndex[theStrVal]].push_back(theStr);
        }
        else
        {
            theGroupIndex[theStrVal] = theGroups.size();
            theGroups.push_back({theStr});
        }
    }
    return theGroups;
}

vector<vector<string>> groupAnagrams_sort(vector<string>& aStrs) {
        
    vector<vector<string>> theGroups;
    unordered_map<string,int> theGroupIndex;
    
    for(auto theStr:aStrs){
        
        string theTempStr = theStr;
        sort(theTempStr.begin(),theTempStr.end());
        
        if(theGroupIndex.count(theTempStr)){
            theGroups[theGroupIndex[theTempStr]].push_back(theStr);
        }
        else
        {
            theGroupIndex[theTempStr] = theGroups.size();
            theGroups.push_back({theStr});
        }
    }
    return theGroups;
}

#endif /* GroupAnagram_hpp */
