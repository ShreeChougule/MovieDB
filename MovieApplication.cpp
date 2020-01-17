/*
 * MovieApplication.cpp
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */

#include "MovieApplication.h"

MovieApplication::MovieApplication() {
	m_movieMgr = MovieManagerImpl::getInstance();
}

MovieApplication::~MovieApplication() {
	MovieManagerImpl::releaseInstance();
}

error_e MovieApplication::showMovies(){
	m_movieMgr->gettMovieList();
	return NO_ERROR;
}

error_e MovieApplication::searchMovie(){
	m_movieMgr->searchtMovieList();
	return NO_ERROR;
}

error_e MovieApplication::updateMovieList(list_operations_e op){
	return NO_ERROR;
}

