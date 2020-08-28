add_executable(MySharedPointer Main.cpp)

target_link_libraries(MySharedPointer PUBLIC SharedPointer)
target_link_libraries(MySharedPointer PUBLIC FlyweightWithGC)

