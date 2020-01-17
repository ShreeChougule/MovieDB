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

error_e MovieManagerImpl::releaseInstance(){
	delete instance;
	instance=nullptr;
	return NO_ERROR;
}

error_e MovieManagerImpl::Initialize(){
//	m_movieBrowser->createMovieList();
	return NO_ERROR;
}

movie_list MovieManagerImpl::searchtMovieList(){

	movie_list list;

	return list;
}

movie_list MovieManagerImpl::gettMovieList(){
	movie_list list;

	return list;
}

error_e updateMovieList(list_operations_e op,Movie&& movie){

	return NO_ERROR;
}





