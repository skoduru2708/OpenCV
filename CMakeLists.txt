cmake_minimum_required(VERSION 3.27.0)
project(OpenCVTest VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

include_directories( ${PROJECT_SOURCE_DIR}/saaicom/include )

add_executable(OpenCVTest ch8.cpp)

target_link_libraries(OpenCVTest ${OpenCV_LIBS})

# Add all .cpp files from the saaicom folder to the executable
file(GLOB SUBFOLDER_SOURCES "saaicom/*.cpp")
target_sources(OpenCVTest PRIVATE ${SUBFOLDER_SOURCES})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)