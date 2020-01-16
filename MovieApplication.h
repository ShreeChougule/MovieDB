/*
 * MovieApplication.h
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include"MovieManagerImpl.h"

#ifndef MOVIEAPPLICATION_H_
#define MOVIEAPPLICATION_H_

class MovieApplication {
public:
	MovieApplication();
	virtual ~MovieApplication();
	int showMovies();
	int searchMovie();
	int updateMovieList(list_operations_e);

private:
	MovieManagerImpl* m_movieMgr;
};

#endif /* MOVIEAPPLICATION_H_ */
