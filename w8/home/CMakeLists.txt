cmake_minimum_required(VERSION 3.7)
project(home)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
#        244_w8_home_prof.cpp
        Account.cpp
        Account.h
        CheckingAccount.cpp
        CheckingAccount.h
        SavingsAccount.cpp
        SavingsAccount.h
        w8_at_home.cpp)

add_executable(home ${SOURCE_FILES})