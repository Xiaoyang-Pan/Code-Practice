//
//  OneAwayEdit.hpp
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef OneAwayEdit_hpp
#define OneAwayEdit_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;


int countNumberOfReplace(string aWord, string aTargetWord)
{
    int theCount = 0;
    for(int i = 0; i< aWord.length();i++){
        if(aWord[i] != aTargetWord[i])
            theCount++;
    }
    return theCount;
}

//Time Complexity: O(N) N is the length of longer word
//Space Complexity: O(1) constant memory usage
bool oneEdit(string aWord, string aTargetWord){
    
    if(aWord.length() > aTargetWord.length())
        return oneEdit(aTargetWord,aWord);
    
    if(aTargetWord.size()-aWord.size()>=2)
        return false;
    
    if(aTargetWord.length() == aWord.length() && countNumberOfReplace(aWord,aTargetWord)>1)
        return false;
    
    if(aWord.length() < aTargetWord.length())
    {
        int theTargetIndex = 0;
        for(int i =0;i < aWord.length();i++)
        {
            if(aWord[i] != aTargetWord[theTargetIndex])
            {
                if(theTargetIndex ==i)
                {
                    i--;
                }
                else{
                    return false;
                }
            }
            theTargetIndex++;
        }
    }
    return true;
}


#endif /* OneAwayEdit_hpp */
