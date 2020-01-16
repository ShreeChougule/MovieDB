cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fstack-protector-all -pthread")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)

#add_subdirectory(MovieDataBase)

set (SOURCES
    "MovieBrowserImpl.cpp"
    "MovieManagerImpl.cpp"
)

set(LIBS 
	${LIBS}
	#MovieDbHandler
)

add_library(moviedb_core SHARED ${SOURCES})

target_link_libraries(moviedb_core ${LIBS})





















