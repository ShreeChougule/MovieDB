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
    MovieBrowserImpl() noexcept;
    MovieBrowserImpl(const MovieBrowserImpl&) noexcept;
    MovieBrowserImpl(MovieBrowserImpl&&) noexcept;
    MovieBrowserImpl& operator=(const MovieBrowserImpl&) noexcept;
    MovieBrowserImpl& operator=(MovieBrowserImpl&&) noexcept;
    virtual ~MovieBrowserImpl() noexcept;

    error_e Initialize();
    movie_list requestMovieList(filter_type_e, filter_t);
    error_e requestAddMovie(Movie*);
    error_e requestRemoveMovie(u_int);

   private:
    static movie_list createMovieList(filter_type_e, filter_t, MovieBrowserImpl*);

   private:
    DBManagerShrdPtr_t m_dbMgr;
    movie_list m_movieList;
};
using movieListFetchTask_t =
    std::packaged_task<movie_list(filter_type_e, filter_t, MovieBrowserImpl*)>;

using movieListFuture_t = std::future<movie_list>;

using MovieBrowserUniqPtr = std::unique_ptr<MovieBrowserImpl>;

}  // namespace moviedb
#endif /* MOVIEBROWSERIMPL_H_ */
