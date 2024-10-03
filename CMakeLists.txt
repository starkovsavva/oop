cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled1 main.cpp
        models/headers/Ship.h
        models/headers/Ship.h
        models/headers/Segment.h
        models/headers/Cell.h
        models/headers/Map.h
        models/sources/Map.cpp
        models/sources/Segment.cpp
        models/sources/Segment.cpp
        models/sources/Cell.cpp
        models/sources/Ship.cpp
        models/headers/ShipManager.h
        models/sources/ShipManager.cpp)
