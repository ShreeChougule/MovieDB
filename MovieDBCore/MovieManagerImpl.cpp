/*
 * MovieManagerImpl.cpp
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "MovieManagerImpl.h"
#include <iostream>
namespace moviedb {

MovieManagerImpl* MovieManagerImpl::instance = nullptr;

MovieManagerImpl* MovieManagerImpl::getInstance() {
    if (!instance) instance = new MovieManagerImpl;
    return instance;
}

error_e MovieManagerImpl::releaseInstance() {
    delete instance;
    instance = nullptr;
    return NO_ERROR;
}

error_e MovieManagerImpl::Initialize() { return NO_ERROR; }

movie_list MovieManagerImpl::searchtMovieList() {
    movie_list list;

    return list;
}

movie_list MovieManagerImpl::gettMovieList() {
    movie_list list;

    return list;
}

error_e MovieManagerImpl::updateMovieList(list_operations_e, u_int) { return NO_ERROR; }

error_e MovieManagerImpl::updateMovieList(list_operations_e op, Movie&& movie) {
    /*
        std::cout << "\n##### Title : " << movie.m_title;
        std::cout << "\n##### Hero : " << movie.m_hero;
        std::cout << "\n##### Heroine : " << movie.m_heroine;
        std::cout << "\n##### Director : " << movie.m_director;
        std::cout << "\n##### Casting : " << movie.m_casting;
        std::cout << "\n##### Genre : " << movie.m_genre;
        std::cout << "\n##### Language : " << movie.m_language;
    */
    return NO_ERROR;
}

}  // namespace moviedb
