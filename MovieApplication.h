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
    /**
     * @brief constructor
     */
    MovieApplication() noexcept;
    /**
     * @brief copy constructor
     * @param reference of MovieApplication class
     */
    MovieApplication(const MovieApplication&) noexcept;
    /**
     * @brief move constructor
     * @param rvalue reference of MovieApplication class
     */
    MovieApplication(const MovieApplication&&) noexcept;
    /**
     * @brief assignment operator
     * @param reference of MovieApplication class
     * @return reference of MovieApplication class
     */
    MovieApplication& operator=(const MovieApplication&) noexcept;
    /**
     * @brief move assignment operator
     * @param rvalue reference of MovieApplication class
     * @return reference of MovieApplication class
     */
    MovieApplication& operator=(const MovieApplication&&) noexcept;
    /**
     * destructor
     */
    virtual ~MovieApplication() noexcept;

    /**
     * @brief shows all available movies
     * @return status
     */
    auto showMovies() -> error_e;
    /**
     * @brief shows list of required movies
     * @return status
     */
    auto searchMovie() -> error_e;
    /**
     * @brief updates movie list according to user
     * @param list operation
     * @return status
     */
    auto updateMovieList(const list_operations_e&) -> error_e;

   private:
    Movie* getMovieData();
    void showList(const movie_list&);
    void showListDetails(const movie_list&);
    std::string getGenreStr(const genre_e&);

   private:
    /**
     * ! \brief singletone object pointer of MovieManagerImpl class
     */
    MovieManagerImpl* m_movieMgr;
};

}  // namespace moviedb
#endif /* MOVIEAPPLICATION_H_ */
