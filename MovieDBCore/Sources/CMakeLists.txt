cmake_minimum_required (VERSION 2.6)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -fstack-protector-all -pthread")

include_directories(${PROJECT_SOURCE_DIR})
include_directories(${PROJECT_SOURCE_DIR}/api)

set (SOURCES
    "SampleSource.cpp"
    "SourceProvider.cpp"
)

set(LIBS 
	${LIBS}
)

add_library(movieDbSources SHARED ${SOURCES})

target_link_libraries(movieDbSources ${LIBS})





















