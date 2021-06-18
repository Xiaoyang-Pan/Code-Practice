//
//  AnimalShelter.hpp
//  Code Practice
//
//  Created by Reid on 6/18/21.
//

#ifndef AnimalShelter_hpp
#define AnimalShelter_hpp

#include <stdio.h>
#include <queue>
#include <iostream>
#include <utility>
#include <string>

using namespace std;
class AnimialQueue{
    AnimialQueue(){
        dogs = {};
        cats = {};
        order = 0;
    }
    
    void enqueue(string aName, bool aIsDog){
        if(aIsDog){
            dogs.push({order,aName});
        }
        else{
            cats.push({order,aName});
        }
        order++;
    }
    
    pair<int,string> dequeCats(){
        if(cats.empty())
            return {};
        
        auto theCat = cats.front();
        cats.pop();
        return theCat;
    }
    
    pair<int,string> dequeDogs(){
        if(dogs.empty())
            return {};
        
        auto theDog = dogs.front();
        dogs.pop();
        return theDog;
    }
    
    pair<int,string> dequeAny(){
        if(dogs.empty())
            return dequeCats();
        else if(cats.empty())
            return dequeCats();
        else{
            if(dogs.front().first < cats.front().first){
                auto theDog = dogs.front();
                dogs.pop();
                return theDog;
            }
            else{
                auto theCat = cats.front();
                cats.pop();
                return theCat;
            }
        }
    }
    
    int order;
    queue<pair<int,string>> dogs;
    queue<pair<int,string>> cats;;
};
#endif /* AnimalShelter_hpp */
