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

error_e MovieManagerImpl::releaseInstance() {
    if (instance) delete instance;
    instance = nullptr;
    return Error::NO_ERROR;
}

error_e MovieManagerImpl::Initialize() {
    m_source = SourceProvider::getSource();
    m_source->Initialize();
    m_movieBrowser->Initialize();

    return Error::NO_ERROR;
}

error_e MovieManagerImpl::OnRequestMovieList(filter_type_e filterType, filter_t filter,
                                             movie_list& listObj) {
    listObj = m_movieBrowser->requestMovieList(filterType, filter);
    return Error::NO_ERROR;
}

error_e MovieManagerImpl::OnUpdateMovieList(list_operations_e op, u_int id) {
    return m_movieBrowser->requestRemoveMovie(id);
}

error_e MovieManagerImpl::OnUpdateMovieList(list_operations_e op, Movie* moviePtr) {
    return m_movieBrowser->requestAddMovie(moviePtr);
}

}  // namespace moviedb
