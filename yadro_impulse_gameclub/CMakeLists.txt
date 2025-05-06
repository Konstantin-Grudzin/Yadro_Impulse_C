cmake_minimum_required(VERSION 3.14)
project(GameClubProject CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCE_DIRS
    GamerMaster
    GamerQueue
    Output
    Parser
    TableMaster
    Time
)

set(SOURCES "")
foreach(dir ${SOURCE_DIRS})
    file(GLOB_RECURSE dir_sources CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/${dir}/*.cpp)
    list(APPEND SOURCES ${dir_sources})
endforeach()

list(REMOVE_ITEM SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/main.cpp")

foreach(dir ${SOURCE_DIRS})
    list(APPEND INCLUDE_DIRS "${CMAKE_CURRENT_SOURCE_DIR}/${dir}")
endforeach()

add_executable(main_exec main.cpp ${SOURCES})
target_include_directories(main_exec PRIVATE ${INCLUDE_DIRS})
target_link_libraries(main_exec pthread)

