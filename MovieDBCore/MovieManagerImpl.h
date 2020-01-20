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
    /**
     * @brief static function to get address of class
     * @return address of own object which is unique
     */
    static MovieManagerImpl* getInstance();
    /**
     * @brief removes the instance of class
     * @return status
     */
    static error_e releaseInstance();
    /**
     * @brief initializes the class
     * @return status
     */
    error_e Initialize();
    /**
     *
     * @param filter type
     * @param filter string
     * @param reference of movie list object
     * @return status
     */
    error_e OnRequestMovieList(filter_type_e, filter_t, movie_list&);
    /**
     * @brief update movie in list requirement procedure
     * @param operation
     * @param movie id
     * @return status
     */
    error_e OnUpdateMovieList(list_operations_e, u_int);
    /**
     * @brief update movie in list requirement procedure
     * @param operation
     * @param address of newly created movie object
     * @return status
     */
    error_e OnUpdateMovieList(list_operations_e, Movie*);

   private:
    /**
     * @brief constructor
     */
    MovieManagerImpl() noexcept;
    MovieManagerImpl(const MovieManagerImpl&) = delete;
    MovieManagerImpl(MovieManagerImpl&&) = delete;
    MovieManagerImpl& operator=(const MovieManagerImpl&) = delete;
    MovieManagerImpl& operator=(MovieManagerImpl&&) = delete;
    /**
     * @brief destructor
     */
    virtual ~MovieManagerImpl() noexcept;

   private:
    /**
     * ! \brief static instance of own object
     */
    static MovieManagerImpl* instance;
    /**
     * ! \brief unique instance of MovieBrowserImpl class
     */
    MovieBrowserUniqPtr m_movieBrowser;
    /**
     * ! \brief common instance which holds the movies source
     */
    MovieSourceShrdPtr_t m_source;
};

}  // namespace moviedb
#endif /* MOVIEMANAGERIMPL_H_ */
