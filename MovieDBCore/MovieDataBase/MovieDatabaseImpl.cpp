/*
 * MovieDatabaseImpl.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "MovieDatabaseImpl.h"
#include <iostream>

namespace moviedb {

u_int MovieDatabaseImpl::m_movieId = 0;

MovieDatabaseImpl::MovieDatabaseImpl() {}

MovieDatabaseImpl::~MovieDatabaseImpl() {}

error_e MovieDatabaseImpl::insertMovieData(Movie* objPtr) {
    dbMap.emplace(std::make_pair(++m_movieId, objPtr));
    return NO_ERROR;
}

error_e MovieDatabaseImpl::deleteMovieData(u_int key) {
    dbMap.erase(key);
    return NO_ERROR;
}

error_e MovieDatabaseImpl::getAllMovieData(movie_list& list) {
    if (dbMap.empty()) return DATA_NOT_FOUND;

    for (auto it : dbMap) { list.push_back(it.second); }
    return NO_ERROR;
}

}  // namespace moviedb
