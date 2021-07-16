cmake_minimum_required(VERSION 3.5)

project(TestGate LANGUAGES CXX)

find_package(QT NAMES Qt5 Qt6 COMPONENTS Test REQUIRED)
find_package(Qt${QT_VERSION_MAJOR} COMPONENTS Test REQUIRED)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
enable_testing()

add_executable(TestGate
    tst_testgate.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../../src/gate.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../utils/protocol.cpp
)
add_test(NAME TestGate COMMAND TestGate)

target_link_libraries(TestGate PRIVATE Qt${QT_VERSION_MAJOR}::Test)

# This must be defined before ../../src so that we can override the include in gate.h
# with a mock Protocol
target_include_directories(TestGate PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../utils
)

# This is required to find Gate
target_include_directories(TestGate PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/../../src
)

