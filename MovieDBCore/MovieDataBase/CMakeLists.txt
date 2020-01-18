cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -fstack-protector-all -pthread")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)

set (SOURCES
    "DBManager.cpp"
    "MovieDatabaseImpl.cpp"
)

set(LIBS 
	${LIBS}
)

add_library(movieDbHandler SHARED ${SOURCES})

target_link_libraries(movieDbHandler ${LIBS})





















