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
    /**
     * @brief Constructor
     */
    MovieBrowserImpl() noexcept;
    /**
     * @brief copy constructor
     * @param reference of source MovieBrowserImpl class
     */
    MovieBrowserImpl(const MovieBrowserImpl&) noexcept;
    /**
     * @brief move constructor
     * @param rvalue reference of source MovieBrowserImpl class
     */
    MovieBrowserImpl(MovieBrowserImpl&&) noexcept;
    /**
     * @brief assignment operator
     * @param reference of source MovieBrowserImpl class
     * @return address of current object
     */
    MovieBrowserImpl& operator=(const MovieBrowserImpl&) noexcept;
    /**
     * @brief move assignement operator
     * @param rvalue reference of source MovieBrowserImpl class
     * @return address of current object
     */
    MovieBrowserImpl& operator=(MovieBrowserImpl&&) noexcept;
    /**
     * @brief destructor
     */
    virtual ~MovieBrowserImpl() noexcept;

    /**
     * @brief initializes class
     * @return status
     */
    auto Initialize() -> error_e;
    /**
     * @brief request movie list from database manager
     * @param filter type by which list will be categorized
     * @param filter the value by which list created
     * @return
     */
    movie_list requestMovieList(filter_type_e, filter_t);
    /**
     * @brief request database manager to add movie
     * @param address of Movie Object
     * @return status
     */
    auto requestAddMovie(Movie*) -> error_e;
    /**
     *  @brief request database manager to remove movie
     * @param id of movie
     * @return status
     */
    auto requestRemoveMovie(u_int) -> error_e;

   private:
    /**
     * @brief static function used by thread to create list
     * @param filter type
     * @param filter data
     * @param address of own object
     * @return status
     */
    static movie_list createMovieList(filter_type_e, filter_t, MovieBrowserImpl*);

   private:
    /**
     * ! \brief local shared pointer of database manager
     */
    DBManagerShrdPtr_t m_dbMgr;
    /**
     * ! \brief local list of movie
     */
    movie_list m_movieList;
};

using movieListFetchTask_t =
    std::packaged_task<movie_list(filter_type_e, filter_t, MovieBrowserImpl*)>;

using movieListFuture_t = std::future<movie_list>;

using MovieBrowserUniqPtr = std::unique_ptr<MovieBrowserImpl>;

}  // namespace moviedb
#endif /* MOVIEBROWSERIMPL_H_ */
