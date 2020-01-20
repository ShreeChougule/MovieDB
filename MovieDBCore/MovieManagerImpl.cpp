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

MovieManagerImpl::MovieManagerImpl() noexcept {
    m_movieBrowser = std::make_unique<MovieBrowserImpl>();
}

MovieManagerImpl::~MovieManagerImpl() noexcept { m_movieBrowser.reset(); }

MovieManagerImpl* MovieManagerImpl::getInstance() {
    if (!instance) { instance = new MovieManagerImpl; }

    return instance;
}

auto MovieManagerImpl::releaseInstance() -> error_e {
    if (instance) delete instance;
    instance = nullptr;
    return Error::NO_ERROR;
}

auto MovieManagerImpl::Initialize() -> error_e {
    m_source = SourceProvider::getSource();
    m_source->Initialize();
    m_movieBrowser->Initialize();

    return Error::NO_ERROR;
}

auto MovieManagerImpl::OnRequestMovieList(filter_type_e filterType, filter_t filter,
                                          movie_list& listObj) -> error_e {
    listObj = m_movieBrowser->requestMovieList(filterType, filter);
    return Error::NO_ERROR;
}

auto MovieManagerImpl::OnUpdateMovieList(list_operations_e op, u_int id) -> error_e {
    return m_movieBrowser->requestRemoveMovie(id);
}

auto MovieManagerImpl::OnUpdateMovieList(list_operations_e op, Movie* moviePtr) -> error_e {
    return m_movieBrowser->requestAddMovie(moviePtr);
}

}  // namespace moviedb
