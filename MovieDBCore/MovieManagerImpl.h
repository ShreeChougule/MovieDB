/*
 * MovieManagerImpl.h
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */
#include "MovieBrowserImpl.h"
#include "Sources/SourceProvider.h"

#ifndef MOVIEMANAGERIMPL_H_
#define MOVIEMANAGERIMPL_H_

namespace moviedb {

class MovieManagerImpl {
   public:
    static MovieManagerImpl* getInstance();
    static error_e releaseInstance();
    error_e Initialize();
    error_e OnRequestMovieList(filter_type_e, filter_t, movie_list&);

    // use template or auto
    error_e OnUpdateMovieList(list_operations_e, u_int);
    error_e OnUpdateMovieList(list_operations_e, Movie*);

   private:
    MovieManagerImpl() noexcept;
    MovieManagerImpl(const MovieManagerImpl&) = delete;
    MovieManagerImpl(MovieManagerImpl&&) = delete;
    MovieManagerImpl& operator=(const MovieManagerImpl&) = delete;
    MovieManagerImpl& operator=(MovieManagerImpl&&) = delete;
    virtual ~MovieManagerImpl() noexcept;

   private:
    static MovieManagerImpl* instance;
    MovieBrowserUniqPtr m_movieBrowser;
    MovieSourceShrdPtr_t m_source;
};

}  // namespace moviedb
#endif /* MOVIEMANAGERIMPL_H_ */
