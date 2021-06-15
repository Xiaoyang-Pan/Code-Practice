//
//  Palindrone_Permutation.hpp
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef Palindrone_Permutation_hpp
#define Palindrone_Permutation_hpp

#include <stdio.h>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

//Time complexity: O(N^2) compare each word with all other words, N is the size of the input word
//Space complexity: O(1) constant memory usage
bool isPermutationOfPalindrome(string aWord){
    int theLetterOccur[26] = {0};
    int theOddCount =0;
    for(int i = 0 ; i<aWord.size();i++)
    {
        int theCharVal = tolower(aWord[i])-'a';
        if(theCharVal<0 || theCharVal > 25)
            continue;
        
        if(theLetterOccur[theCharVal]!=  0)
            continue;
        
        for(int j = i; j < aWord.size();j++)
        {
            if(tolower(aWord[i]) ==tolower(aWord[j])){
                theLetterOccur[theCharVal]++;
            }
        }
        if(theLetterOccur[theCharVal]%2==1)
        {
            theOddCount+=1;
            
            if(theOddCount>1)
                return false;
        }
    }
    return true;
}


//Time complexity: O(N) N is the size of the input word
//Space complexity: O(1) constant memory usage

bool isPermutationOfPalindrome_Optimize(string aWord){
    
    int theLetterOccur[26] = {0};
    int theOddCount =0;
    for(int i = 0 ; i<aWord.size();i++)
    {
        int theCharVal = tolower(aWord[i])-'a';
        if(theCharVal<0 || theCharVal > 25)
            continue;
        
        theLetterOccur[theCharVal] +=1;
    }
    
    for(int j = 0; j < 26;j++)
    {
        if(theLetterOccur[j]%2 ==1){
            theOddCount+=1;
            if(theOddCount>1)
                return false;
        }
    }
    
    return true;
}




#endif /* Palindrone_Permutation_hpp */
