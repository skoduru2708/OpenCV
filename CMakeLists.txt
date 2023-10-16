cmake_minimum_required(VERSION 3.27.0)
project(OpenCVTest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#set(OpenCV_DIR  "C:\\dev\\tools\\OpenCV")
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(OpenCVTest ch6.cpp)

target_link_libraries(OpenCVTest ${OpenCV_LIBS})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)