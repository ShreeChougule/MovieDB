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
    return Error::NO_ERROR;
}

movie_list MovieBrowserImpl::createMovieList(filter_type_e filter_type, filter_t filter,
                                             MovieBrowserImpl* instance) {
    movie_list list;
    error_e status = instance->m_dbMgr->getAllMovieData(filter_type, filter, list);
    return list;
}

movie_list MovieBrowserImpl::requestMovieList(filter_type_e filter_type, filter_t filter) {
    m_movieList.clear();

    movieListFetchTask_t task(MovieBrowserImpl::createMovieList);
    movieListFuture_t m_movieListPromise = task.get_future();

    std::thread thread(std::move(task), filter_type, filter, this);
    thread.detach();

    m_movieList = m_movieListPromise.get();
    return m_movieList;
}

error_e MovieBrowserImpl::requestAddMovie(Movie* ptr) { return m_dbMgr->insertMovieData(ptr); }

error_e MovieBrowserImpl::requestRemoveMovie(u_int id) { return m_dbMgr->deleteMovieData(id); }

}  // namespace moviedb
