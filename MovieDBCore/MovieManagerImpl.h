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
	static int releaseInstance();
	int Initialize();
	movie_list gettMovieList();
	movie_list searchtMovieList();


private:
	MovieManagerImpl(){}
	virtual ~MovieManagerImpl(){}
	int createMovieList();

private:
    static MovieManagerImpl *instance;
	std::unique_ptr<MovieBrowserImpl> m_movieBrowser;
};

#endif /* MOVIEMANAGERIMPL_H_ */
