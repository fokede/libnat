cmake_minimum_required(VERSION 2.8)

FIND_PACKAGE( Boost 1.66 )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )

if(MSVC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /MP")
endif()

if (NOT BUILD_IN_UVVY)
    include_directories(3rdparty/endian)
endif()

include_directories(include)
add_subdirectory(lib)

if (BUILD_TESTING)
    add_subdirectory(tests)
endif (BUILD_TESTING)
