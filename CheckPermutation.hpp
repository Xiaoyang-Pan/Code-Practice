//
//  CheckPermutation.hpp
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef CheckPermutation_hpp
#define CheckPermutation_hpp

#include <stdio.h>

//if utilize isCharSameOcuurance_Array function, Time Complexity O(M), M is the size of longer string
//In both situation, Space Complexity: O(1), constant memory usage
bool checkInclusion(string aStr1, string aStr2) {
    if(aStr1.size()>aStr2.size()){
        return(checkInclusion(aStr2,aStr1));
    }
    
    int theS1Count[26] = {0};
    int theS2Count[26] = {0};
        
    for(int i = 0; i< aStr1.size();i++){
        theS1Count[aStr1[i]-'a'] +=1;
        theS2Count[aStr2[i]-'a'] +=1;
    }
        
    int offset = 0;
    while(offset+aStr1.size() <=aStr2.size())
    {
        if(isCharSameOcuurance(theS1Count,theS2Count,aStr1))
            return true;
        if(offset+aStr1.size() ==aStr2.size())
            return false;
        theS2Count[aStr2[offset]-'a']-=1;
        theS2Count[aStr2[offset+s1.size()]-'a']+=1;
        offset+=1;
    }
    
    return false;
}
    
bool isCharSameOcuurance(int aS1Count[26],int aS2Count[26],string aS1){
    for(auto theChara:aS1)
    {
        if(aS1Count[theChara-'a'] != aS2Count[theChara-'a'])
            return false;
    }
    return true;
}

bool isCharSameOcuurance_Array(int aS1Count[26],int aS2Count[26])
{
    for(int i = 0; i < 26;i++)
    {
        if(aS1Count[i] != aS2Count[i])
            return false;
    }
    return true;
}


//Time complexity: O(M) M is the length of the larger string
//Space complexity: O(1) constant memory usage

bool checkInclusion_optimize(string s1, string s2) {
        if (s1.length()>s2.length())
            return checkInclusion_optimize(s2,s1);
        
        int s1letters[26] = {};
        int s2letters[26] = {};
        
        for (int i = 0;i < s1.length();i++)
        {
            s1letters[s1[i]-'a']+=1;
            s2letters[s2[i]-'a']+=1;
        }
        
        int count =0;
        for (int j = 0;j < 26;j++)
        {
            if(s1letters[j] ==s2letters[j])
                count+=1;
        }
        
        for(int i = 0; i < s2.length()-s1.length();i++)
        {
            if (count==26)
                return true;
            
            //cout <<count <<"\n";
            int left = s2[i]-'a';
            int right = s2[i+s1.length()]-'a';

            s2letters[right]++;
            
            if (s2letters[right]-1 == s1letters[right])
                count--;
            else if(s2letters[right] == s1letters[right])
            {
                count++;
            }
            
            s2letters[left]--;
            if (s2letters[left] == s1letters[left])
                count+=1;
            else if(s2letters[left]+1 == s1letters[left])
                count-=1;
            
        }
        
        return count ==26;
    }

#endif /* CheckPermutation_hpp */
