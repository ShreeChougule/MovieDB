cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fstack-protector-all -pthread")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)
include_directories(MovieDataBase)
include_directories(Sources)

add_subdirectory(MovieDataBase)
add_subdirectory(Sources)

set (SOURCES
    "MovieBrowserImpl.cpp"
    "MovieManagerImpl.cpp"
)

set(LIBS 
	${LIBS}
	movieDbHandler
	movieDbSources
)

add_library(moviedb_core SHARED ${SOURCES})

target_link_libraries(moviedb_core ${LIBS})





















