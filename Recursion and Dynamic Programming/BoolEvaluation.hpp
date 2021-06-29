//
//  BoolEvaluation.hpp
//  Code Practice
//
//  Created by Reid on 6/28/21.
//

#ifndef BoolEvaluation_hpp
#define BoolEvaluation_hpp

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int countEval(string aExpre, bool aResult){
    
    if(aExpre.size() == 0)
        return 0;
    if(aExpre.size() == 1)
        return aResult == true ?aExpre == "1":aExpre =="0";
    
    int theWays=0;
    for(int i = 1;i < aExpre.size();i+=2){
        
        char theOpera = aExpre[i];
        string theLeftExpre = aExpre.substr(0,i);
        string theRightExpre = aExpre.substr(i+1);
        
//        cout  << theLeftExpre << " " << theRightExpre<<endl;
        
        int theLeftTrue = countEval(theLeftExpre,true);
        int theLeftFalse = countEval(theLeftExpre,false);
        int theRightTrue = countEval(theRightExpre,true);
        int theRightFalse = countEval(theRightExpre,false);
        
        int theTotalWay = (theLeftTrue+theLeftFalse)*(theRightTrue+theRightFalse);
        int theExpreWays =0;
        if(aExpre[i]=='^'){
            theExpreWays += theLeftTrue*theRightFalse + theLeftFalse*theRightTrue;
        }
        else if(aExpre[i] == '&')
        {
            theExpreWays += theLeftTrue* theRightTrue;
        }
        else if(aExpre[i] == '|')
        {
            theExpreWays = theTotalWay - theLeftFalse*theRightFalse;
        }
        
        if(aResult)
            theWays+=theExpreWays;
        else
            theWays+= theTotalWay-theExpreWays;
    }
    return theWays;
    
}

int countEval_optimize(string aExpre, bool aResult, unordered_map<string,int> &aMemo){
    
    if(aExpre.size() == 0)
        return 0;
    if(aExpre.size() == 1)
        return aResult == true ?aExpre == "1":aExpre =="0";
    
    char theChar = aResult+'0';
    if(aMemo.count(aExpre+theChar))
        return aMemo[aExpre+theChar];
    
    int theWays=0;
    for(int i = 1;i < aExpre.size();i+=2){
        
        char theOpera = aExpre[i];
        string theLeftExpre = aExpre.substr(0,i);
        string theRightExpre = aExpre.substr(i+1);
        
//        cout  << theLeftExpre << " " << theRightExpre<<endl;
        
        int theLeftTrue = countEval(theLeftExpre,true);
        int theLeftFalse = countEval(theLeftExpre,false);
        int theRightTrue = countEval(theRightExpre,true);
        int theRightFalse = countEval(theRightExpre,false);
        
        int theTotalWay = (theLeftTrue+theLeftFalse)*(theRightTrue+theRightFalse);
        int theExpreWays =0;
        if(aExpre[i]=='^'){
            theExpreWays += theLeftTrue*theRightFalse + theLeftFalse*theRightTrue;
        }
        else if(aExpre[i] == '&')
        {
            theExpreWays += theLeftTrue* theRightTrue;
        }
        else if(aExpre[i] == '|')
        {
            theExpreWays = theTotalWay - theLeftFalse*theRightFalse;
        }
        
        if(aResult)
            theWays+=theExpreWays;
        else
            theWays+= theTotalWay-theExpreWays;
    }
    aMemo[aExpre+theChar] = theWays;
    return theWays;
    
}

int countEval_optimize(string aExpre,bool aResult){
    unordered_map<string,int> theMemo;
    return countEval_optimize(aExpre, aResult, theMemo);
}



#endif /* BoolEvaluation_hpp */
