#include <iostream>
#include "SharedPointer.hpp"
#include <vector>
#include "FlyweightWithGC.hpp"
using namespace std;

int main(){
    std::cout<<"Garbage collector with flyweight pattern using shared pointers - test"<<endl;
    
    FlyweightWithGC<int> intDatabase = FlyweightWithGC<int>();

    intDatabase.requestPointer(5);
    cout<<intDatabase.getNumberOfObjects()<<endl;
    
    SharedPointer<int> sp10 = intDatabase.requestPointer(10);
    cout<<intDatabase.getNumberOfObjects()<<endl;
    
    intDatabase.requestPointer(5);
    cout<<intDatabase.getNumberOfObjects()<<endl;

    SharedPointer<int> sp5 =intDatabase.requestPointer(5);
    cout<<intDatabase.getNumberOfObjects()<<endl;

    SharedPointer<int> sp10_2 = intDatabase.requestPointer(10);
    cout<<intDatabase.getNumberOfObjects()<<endl;

    cout<<"Test finished."<<endl;
}
