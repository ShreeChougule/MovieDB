cmake_minimum_required (VERSION 2.6)
project (MovieDB)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fstack-protector-all -pthread")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)
include_directories(${PROJECT_SOURCE_DIR}/MovieDBCore)

add_subdirectory(MovieDBCore)

set (SOURCES
    "main.cpp"
    "MovieApplication.cpp"
)

set(LIBS 
	${LIBS}
	moviedb_core
)

add_executable(movie_db ${SOURCES})
target_link_libraries(movie_db ${LIBS})





















