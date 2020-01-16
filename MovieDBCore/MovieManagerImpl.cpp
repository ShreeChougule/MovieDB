/*
 * MovieManagerImpl.cpp
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "MovieManagerImpl.h"

MovieManagerImpl* MovieManagerImpl::instance=nullptr;


MovieManagerImpl* MovieManagerImpl::getInstance(){
	if (!instance)
	      instance = new MovieManagerImpl;
    return instance;
}

int MovieManagerImpl::releaseInstance(){
	delete instance;
	instance=nullptr;
	return 0;
}

int MovieManagerImpl::Initialize(){
//	m_movieBrowser =
	createMovieList();
	return 0;
}

int MovieManagerImpl::createMovieList(){
	return 0;
}

movie_list MovieManagerImpl::searchtMovieList(){

	movie_list list;

	return list;
}

movie_list MovieManagerImpl::gettMovieList(){
	movie_list list;

	return list;
}





