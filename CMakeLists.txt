cmake_minimum_required(VERSION 3.18)
project(MySharedPointer VERSION 1.0.0)



add_subdirectory(SharedPointer)
add_subdirectory(FlyweightWithGC)
add_subdirectory(exe)

set_property(TARGET MySharedPointer PROPERTY CXX_STANDARD 17)