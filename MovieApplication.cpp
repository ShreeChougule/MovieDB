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

int MovieApplication::showMovies(){
	m_movieMgr->gettMovieList();
	return 0;
}

int MovieApplication::searchMovie(){
	m_movieMgr->searchtMovieList();
	return 0;
}

int MovieApplication::updateMovieList(list_operations_e op){
	return 0;
}

