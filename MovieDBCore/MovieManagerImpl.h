/*
 * MovieManagerImpl.h
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */

#include <memory>

#include"MovieBrowserImpl.h"
#include"movieTypes.h"

#ifndef MOVIEMANAGERIMPL_H_
#define MOVIEMANAGERIMPL_H_

class MovieManagerImpl {
public:
	static MovieManagerImpl* getInstance();
	static error_e releaseInstance();
	error_e Initialize();
	movie_list gettMovieList();
	movie_list searchtMovieList();
	error_e updateMovieList(list_operations_e,Movie&&);

private:
	MovieManagerImpl(){
		m_movieBrowser=std::make_unique<MovieBrowserImpl>();
	}
	virtual ~MovieManagerImpl(){}

private:
    static MovieManagerImpl *instance;
	std::unique_ptr<MovieBrowserImpl> m_movieBrowser;
};

#endif /* MOVIEMANAGERIMPL_H_ */
