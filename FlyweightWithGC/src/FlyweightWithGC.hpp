#pragma once
#include "SharedPointer.hpp"
#include <vector>
#include <thread>
#include <chrono>
#include <algorithm>
#include <iostream>
using namespace  std;

template<class T>
class FlyweightWithGC{
    
    public:
    
    FlyweightWithGC<T>(){
        allSavedPointers_ = vector<SharedPointer<T>>();
    }
   
    ~FlyweightWithGC(){
        allSavedPointers_.clear();
    }
    
    SharedPointer<T> requestPointer(T content){       
        for(auto &sp : allSavedPointers_){
            if(*sp==content){
                return sp;
            }
        }
        clearNotUsedPointers();
        allSavedPointers_.push_back(SharedPointer<T>(new T(content)));
        return allSavedPointers_.back();
    }
    
    int getNumberOfObjects(){
        return allSavedPointers_.size();
    }
    


    private: 
    
    vector<SharedPointer<T>> allSavedPointers_;
    
    void clearNotUsedPointers(){
        if(allSavedPointers_.size()>=1)
            allSavedPointers_.erase(   
                remove_if(allSavedPointers_.begin(),
                        allSavedPointers_.end(),
                        [](SharedPointer<T> pointer){
                            return (pointer.get_counter()==2);
                            //2=1 in database, 2nd as copy used in lambda expression
                }),
                allSavedPointers_.end()
            );
    }
};
