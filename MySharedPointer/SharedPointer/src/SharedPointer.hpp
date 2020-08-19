#include <unordered_map>

using namespace  std;

class SharedPointer{
    public: 
        SharedPointer();
    private:
        static unordered_map<SharedPointer,int> allSharedPointers();
};