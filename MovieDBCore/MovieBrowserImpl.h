/*
 * MovieBrowserImpl.h
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "movieTypes.h"
#include "MovieDataBase/DBManager.h"

#ifndef MOVIEBROWSERIMPL_H_
#define MOVIEBROWSERIMPL_H_

namespace moviedb {

class MovieBrowserImpl {
   public:
    MovieBrowserImpl();
    virtual ~MovieBrowserImpl();
    error_e Initialize();
    movie_list requestMovieList(filter_type_e, filter_t);
    error_e requestAddMovie(Movie*);
    error_e requestRemoveMovie(u_int);

   private:
    error_e createMovieList(filter_type_e, filter_t);

   private:
    DBManagerShrdPtr_t m_dbMgr;
    movie_list m_movieList;
};

using MovieBrowserUniqPtr = std::unique_ptr<MovieBrowserImpl>;

}  // namespace moviedb
#endif /* MOVIEBROWSERIMPL_H_ */
