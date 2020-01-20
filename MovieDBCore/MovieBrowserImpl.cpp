/*
 * MovieBrowserImpl.cpp
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "MovieBrowserImpl.h"

namespace moviedb {

MovieBrowserImpl::MovieBrowserImpl() noexcept {}

MovieBrowserImpl::MovieBrowserImpl(const MovieBrowserImpl& Source) noexcept
    : m_dbMgr(Source.m_dbMgr), m_movieList(Source.m_movieList) {}

MovieBrowserImpl::MovieBrowserImpl(MovieBrowserImpl&& Source) noexcept
    : m_dbMgr(std::move(Source.m_dbMgr)) {
    m_movieList = std::move(Source.m_movieList);
}

MovieBrowserImpl& MovieBrowserImpl::operator=(const MovieBrowserImpl& Source) noexcept {
    m_dbMgr = Source.m_dbMgr;
    m_movieList = Source.m_movieList;
    return *this;
}

MovieBrowserImpl& MovieBrowserImpl::operator=(MovieBrowserImpl&& Source) noexcept {
    m_dbMgr = std::move(Source.m_dbMgr);
    m_movieList = std::move(Source.m_movieList);
    return *this;
}

MovieBrowserImpl::~MovieBrowserImpl() noexcept {}

error_e MovieBrowserImpl::Initialize() {
    m_dbMgr = DBManager::getInstance();
    return NO_ERROR;
}

error_e MovieBrowserImpl::createMovieList(filter_type_e filter_type, filter_t filter) {
    m_movieList.clear();
    error_e ret = m_dbMgr->getAllMovieData(filter_type, filter, m_movieList);
    if (ret == DATA_NOT_FOUND) std::cout << "\nWARNING : No Movies Available right now !\n";
    return ret;
}

movie_list MovieBrowserImpl::requestMovieList(filter_type_e filter_type, filter_t filter) {
    createMovieList(filter_type, filter);
    return m_movieList;
}

error_e MovieBrowserImpl::requestAddMovie(Movie* ptr) { return m_dbMgr->insertMovieData(ptr); }

error_e MovieBrowserImpl::requestRemoveMovie(u_int id) { return m_dbMgr->deleteMovieData(id); }

}  // namespace moviedb
