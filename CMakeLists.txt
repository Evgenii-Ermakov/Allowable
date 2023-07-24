cmake_minimum_required(VERSION 3.24) 

project(Allowable CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(ROOT ${CMAKE_CURRENT_SOURCE_DIR}/Allowable)

set(SOURCE_EXE ${ROOT}/main.cpp 
			   ${ROOT}/allow.cpp 
			   ${ROOT}/protected_class.cpp)
set(HEADER ${ROOT}/allow.h ${ROOT}/protected_class.h)

source_group("Headers" FILES ${HEADER})
source_group("Source" FILES ${SOURCE_EXE})

enable_testing()

add_executable(Allowable ${SOURCE_EXE} ${HEADER})

install(TARGETS Allowable
        CONFIGURATIONS Debug
        RUNTIME DESTINATION Debug/bin)
install(TARGETS Allowable
        CONFIGURATIONS Release
        RUNTIME DESTINATION Release/bin)