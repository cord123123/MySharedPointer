add_library(
    FlyweightWithGC
    src/FlyweightWithGC.hpp
    src/FlyweightWithGC.cpp
)
target_link_libraries(FlyweightWithGC PUBLIC SharedPointer)

target_include_directories(FlyweightWithGC PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")