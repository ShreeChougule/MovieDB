/*
 * MovieDatabaseImpl.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "MovieDatabaseImpl.h"
#include <iostream>
#include <algorithm>

namespace moviedb {

dbId MovieDatabaseImpl::m_movieId = 0;

MovieDatabaseImpl::MovieDatabaseImpl() noexcept {}

MovieDatabaseImpl::MovieDatabaseImpl(const MovieDatabaseImpl& Source) noexcept
    : m_dbMap(Source.m_dbMap) {}

MovieDatabaseImpl::MovieDatabaseImpl(MovieDatabaseImpl&& Source) noexcept
    : m_dbMap(std::move(Source.m_dbMap)) {}

MovieDatabaseImpl& MovieDatabaseImpl::operator=(const MovieDatabaseImpl& Source) noexcept {
    m_dbMap = Source.m_dbMap;
    return *this;
}

MovieDatabaseImpl& MovieDatabaseImpl::operator=(MovieDatabaseImpl&& Source) noexcept {
    m_dbMap = std::move(Source.m_dbMap);
    return *this;
}

MovieDatabaseImpl::~MovieDatabaseImpl() noexcept {}

error_e MovieDatabaseImpl::insertMovieData(Movie* objPtr) {
    m_dbMap.emplace(std::make_pair(++m_movieId, objPtr));
    objPtr->m_Id = m_movieId;
    return Error::NO_ERROR;
}

error_e MovieDatabaseImpl::deleteMovieData(dbId key) {
    error_e ret = Error::NO_ERROR;

    auto search = m_dbMap.find(key);
    if (search != m_dbMap.end())
        m_dbMap.erase(search);
    else
        ret = Error::DATA_NOT_FOUND;

    return ret;
}

error_e MovieDatabaseImpl::getAllMovieData(filter_type_e searchType, filter_t filter,
                                           movie_list& list) {
    if (m_dbMap.empty()) return Error::DATA_NOT_FOUND;

    auto findCaseInsensitiveData = [](auto data, auto toSearch) {
        auto status = false;
        std::transform(data.begin(), data.end(), data.begin(), ::tolower);
        std::transform(toSearch.begin(), toSearch.end(), toSearch.begin(), ::tolower);
        if (data.find(toSearch) != std::string::npos) status = true;
        return status;
    };

    switch (searchType) {
        case FilterType::ALL: {
            for (auto it : m_dbMap) { list.emplace_back(it.second); }
        } break;

        case FilterType::TITLE: {
            for (auto it : m_dbMap) {
                if (findCaseInsensitiveData((it.second)->m_title, filter))
                    list.emplace_back(it.second);
            }
        } break;

        case FilterType::HERO: {
            for (auto it : m_dbMap) {
                if (findCaseInsensitiveData((it.second)->m_hero, filter))
                    list.emplace_back(it.second);
            }
        } break;

        case FilterType::HEROINE: {
            for (auto it : m_dbMap) {
                if (findCaseInsensitiveData((it.second)->m_heroine, filter))
                    list.emplace_back(it.second);
            }
        } break;

        case FilterType::DIRECTOR: {
            for (auto it : m_dbMap) {
                if (findCaseInsensitiveData((it.second)->m_director, filter))
                    list.emplace_back(it.second);
            }
        } break;

        case FilterType::GENRE: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_genre == std::stoi(filter)) list.emplace_back(it.second);
            }
        } break;

        case FilterType::CASTING: {
            for (auto it : m_dbMap) {
                if (findCaseInsensitiveData((it.second)->m_casting, filter))
                    list.emplace_back(it.second);
            }
        } break;

        case FilterType::YEAR: {
            for (auto it : m_dbMap) {
                if ((it.second)->m_year == std::stoi(filter)) { list.emplace_back(it.second); }
            }
        } break;
    }
    return Error::NO_ERROR;
}

}  // namespace moviedb
