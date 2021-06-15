//
//  URLify.hpp
//  Code Practice
//
//  Created by Reid on 6/14/21.
//

#ifndef URLify_hpp
#define URLify_hpp

#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

//Time Complexity:O(N) where N is the true length of the string
//Space Complexity:O(N) a copy of str is needed.
void replaceSpaces(char aStr[],int aTrueLength)
{
    if('\0' == aStr[0])
        return;
        
    string theStr(aStr);
    int index =0;
    for(int i =0; i< aTrueLength;i++)
    {
        if(theStr[i] != ' '){
            aStr[index] = theStr[i];
            index+=1;
        }
        else
        {
            aStr[index] ='%';
            aStr[index+1] = '2';
            aStr[index+2] = '0';
            index+=3;
        }
    }
    cout << aStr<<endl;
}


//Time Complexity: O(N) where N is the true length of the string
//Space Complexity: O(1) no additional memory needed
void replaceSpace_backward(char aStr[],int aTrueLength)
{

    int theNewSize = -1;
    for(int i =0; i< aTrueLength;i++){
        if(aStr[i] ==' ')
            theNewSize+=2;
        theNewSize+=1;
    }

    for(int i =aTrueLength-1; i >=0;i--){

        if(aStr[i] != ' '){
            aStr[theNewSize] = aStr[i];
            theNewSize-=1;
        }
        else
        {
            aStr[theNewSize] ='0';
            aStr[theNewSize-1] = '2';
            aStr[theNewSize-2] = '%';
            theNewSize-=3;
        }
    }
    cout << aStr << endl;
}

#endif /* URLify_hpp */
