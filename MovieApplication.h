/*
* MovieApplication.h
*
*  Created on: 12-Jan-2020
*      Author: kpit
*/

#include "MovieManagerImpl.h"

#ifndef MOVIEAPPLICATION_H_
#define MOVIEAPPLICATION_H_

namespace moviedb {

class MovieApplication {
   public:
    MovieApplication();
    virtual ~MovieApplication();
    error_e showMovies();
    error_e searchMovie();
    error_e updateMovieList(const list_operations_e&);

   private:
    Movie* getMovieData();
    void showList(const movie_list&);

   private:
    MovieManagerImpl* m_movieMgr;
};

}  // namespace moviedb
#endif /* MOVIEAPPLICATION_H_ */
