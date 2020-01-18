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
    error_e createMovieList();
    movie_list requestMovieList();

   private:
    DBManagerShrdPtr_t m_dbMgr;
    movie_list m_movieList;
    movie_list m_searchResultList;
};

using MovieBrowserUniqPtr = std::unique_ptr<MovieBrowserImpl>;

}  // namespace moviedb
#endif /* MOVIEBROWSERIMPL_H_ */
