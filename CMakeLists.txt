cmake_minimum_required(VERSION 3.22)
project(untitled1)

set(CMAKE_CXX_STANDARD 17)

# Указываем пути к заголовочным файлам
include_directories(models/headers)

# Указываем исходные файлы
set(SOURCES
        main.cpp
        models/sources/Map.cpp
        models/sources/Ship.cpp
        models/sources/ShipManager.cpp
        models/sources/Game.cpp
        models/sources/Constants.cpp
)

# Добавляем исполняемый файл
add_executable(untitled1 ${SOURCES})