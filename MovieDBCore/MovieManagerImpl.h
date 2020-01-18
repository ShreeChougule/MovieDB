/*
 * MovieManagerImpl.h
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */
#include "MovieBrowserImpl.h"
#include "MovieDataBase/DBManager.h"

#ifndef MOVIEMANAGERIMPL_H_
#define MOVIEMANAGERIMPL_H_

namespace moviedb {

class MovieManagerImpl {
   public:
    static MovieManagerImpl* getInstance();
    static error_e releaseInstance();
    error_e Initialize();
    movie_list gettMovieList();
    movie_list searchtMovieList();

    // use template or auto
    error_e updateMovieList(list_operations_e, u_int);
    error_e updateMovieList(list_operations_e, Movie&&);

   private:
    MovieManagerImpl() { m_movieBrowser = std::make_unique<MovieBrowserImpl>(); }
    virtual ~MovieManagerImpl() {}

   private:
    static MovieManagerImpl* instance;
    DBManagerShrdPtr_t m_dbMgr;
    MovieBrowserUniqPtr m_movieBrowser;
};

}  // namespace moviedb
#endif /* MOVIEMANAGERIMPL_H_ */
