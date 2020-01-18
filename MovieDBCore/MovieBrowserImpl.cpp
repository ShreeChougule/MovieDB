/*
 * MovieBrowserImpl.cpp
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "MovieBrowserImpl.h"

namespace moviedb {

MovieBrowserImpl::MovieBrowserImpl() {}

MovieBrowserImpl::~MovieBrowserImpl() {}

error_e MovieBrowserImpl::Initialize() {
    m_dbMgr = DBManager::getInstance();
    createMovieList();
    return NO_ERROR;
}

error_e MovieBrowserImpl::createMovieList() {
    error_e ret = m_dbMgr->getAllMovieData(m_movieList);
    if (ret == DATA_NOT_FOUND) std::cout << "\nWARNING : No Movies Available right now !\n";
    return ret;
}

movie_list MovieBrowserImpl::requestMovieList() { return m_movieList; }

}  // namespace moviedb
