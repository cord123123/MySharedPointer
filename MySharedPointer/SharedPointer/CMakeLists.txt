add_library(
    SharedPointer
    src/SharedPointer.hpp
    src/SharedPointer.cpp
)
target_include_directories(SharedPointer PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")