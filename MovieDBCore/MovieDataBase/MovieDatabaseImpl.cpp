/*
 * MovieDatabaseImpl.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "MovieDatabaseImpl.h"
#include <iostream>

namespace moviedb {

dbId MovieDatabaseImpl::m_movieId = 0;

MovieDatabaseImpl::MovieDatabaseImpl() {}

MovieDatabaseImpl::~MovieDatabaseImpl() {}

error_e MovieDatabaseImpl::insertMovieData(Movie* objPtr) {
    m_dbMap.emplace(std::make_pair(++m_movieId, objPtr));
    objPtr->m_Id = m_movieId;
    return NO_ERROR;
}

error_e MovieDatabaseImpl::deleteMovieData(dbId key) {
    auto dbItor = m_dbMap.find(key);
    m_dbMap.erase(dbItor);
    return NO_ERROR;
}

error_e MovieDatabaseImpl::getAllMovieData(filter_type_e searchType, filter_t filter,
                                           movie_list& list) {
    if (m_dbMap.empty()) return DATA_NOT_FOUND;

    switch (searchType) {
        case ALL: {
            for (auto it : m_dbMap) { list.push_back(it.second); }
        } break;

        case TITLE: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_title.find(filter) != std::string::npos) {
                    list.push_back(it.second);
                }
            }
        } break;

        case HERO: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_hero.find(filter) != std::string::npos) {
                    list.push_back(it.second);
                }
            }
        } break;

        case HEROINE: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_heroine.find(filter) != std::string::npos) {
                    list.push_back(it.second);
                }
            }
        } break;

        case DIRECTOR: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_director.find(filter) != std::string::npos) {
                    list.push_back(it.second);
                }
            }
        } break;

        case GENRE: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_genre == std::stoi(filter)) { list.push_back(it.second); }
            }
        } break;

        case CASTING: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_casting.find(filter) != std::string::npos) {
                    list.push_back(it.second);
                }
            }
        } break;

        case YEAR: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_year == std::stoi(filter)) { list.push_back(it.second); }
            }
        } break;
    }
    return NO_ERROR;
}

}  // namespace moviedb
