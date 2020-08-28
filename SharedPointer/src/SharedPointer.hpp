#pragma once
#include <iostream>
using namespace  std;


template<class T>
class SharedPointer{
    public: 
    explicit SharedPointer(T* ptr){
        counter_ = new int(1);
        pointer_ = ptr;
    }
    SharedPointer(const SharedPointer<T>& other){
        pointer_ = other.pointer_;
        counter_ = other.counter_;
        (*counter_)++;
    }
    SharedPointer(SharedPointer<T>& other){
        pointer_ = other.pointer_;
        counter_ = other.counter_;
        (*counter_)++;
    }
    
    ~SharedPointer(){
        if(*counter_ == 1){
            delete pointer_;
            delete counter_;
        }
        else {
            (*counter_)--;
        }
    }

       SharedPointer& operator=(const SharedPointer<T>& other){
           if(&other != this){
               if(*counter_ == 1){
                   delete pointer_;
                   delete counter_;
               }
               else {
                   (*counter_)--;
               }
               pointer_ = other.pointer_;
               counter_ = other.counter_;
               (*counter_)++;
           }
           return *this;
       }

        SharedPointer& operator=(SharedPointer<T>&& other){
            if(&other != this){
                if(*counter_ == 1){
                    delete pointer_;
                    delete counter_;
                }
                else {
                    (*counter_)--;
                }
                pointer_ = other.pointer_;
                counter_ = other.counter_;
                (*counter_)++;
            }
            return *this;
        }

        int get_counter(){ return *counter_;}

        T* get(){return pointer_;}

        T* operator->(){return pointer_;}
        
        T& operator*(){ return *pointer_;}
        
        friend ostream& operator<<(ostream& os, const SharedPointer& sharedPointer){
            os<<"pointer: "<<*(sharedPointer.pointer_)<<" counter: "<<*(sharedPointer.counter_)<<endl;
        }


    private:
        T* pointer_;
        int* counter_;
};