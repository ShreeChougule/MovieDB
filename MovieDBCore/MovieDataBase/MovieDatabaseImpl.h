/*
 * MovieDatabaseImpl.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */
#include <unordered_map>

#include "IMovieDatabase.h"

#ifndef MOVIEDATABASE_MOVIEDATABASEIMPL_H_
#define MOVIEDATABASE_MOVIEDATABASEIMPL_H_

namespace moviedb {
using dbId = unsigned int;

class MovieDatabaseImpl : public IMovieDataBase {
   public:
    /**
     * @brief constructor
     */
    MovieDatabaseImpl() noexcept;
    /**
     * @brief copy constructor
     * @param reference of source class
     */
    MovieDatabaseImpl(const MovieDatabaseImpl &) noexcept;
    /**
     * @brief move constructor
     * @param rvalue reference of source class
     */
    MovieDatabaseImpl(MovieDatabaseImpl &&) noexcept;
    /**
     * @brief assignment operator
     * @param reference of source class
     * @return reference of newly created object
     */
    MovieDatabaseImpl &operator=(const MovieDatabaseImpl &) noexcept;
    /**
     * @brief move assignment operator
     * @param rvalue reference of source class
     * @return reference of newly created object
     */
    MovieDatabaseImpl &operator=(MovieDatabaseImpl &&) noexcept;
    /**
     * @brief destructor
     */
    virtual ~MovieDatabaseImpl() noexcept;

    /**
     * @brief inserts data into the database
     * @param address of movie object
     * @return status
     */
    error_e insertMovieData(Movie *) override;
    /**
     * @brief delete specific data from the database
     * @param id of movie
     * @return status
     */
    error_e deleteMovieData(dbId) override;
    /**
     * @brief reads the data from database and fill the list with required data
     * @param filter type
     * @param filter value
     * @param reference of movie list object
     * @return status
     */
    error_e getAllMovieData(filter_type_e, filter_t, movie_list &) override;

   private:
    /**
     * ! \brief Database which is "std::map<movie id,addresses of movies>"
     */
    std::unordered_map<dbId, Movie *> m_dbMap;
    /**
     * ! \brief static id generator variable
     */
    static dbId m_movieId;
};

}  // namespace moviedb
#endif /* MOVIEDATABASE_MOVIEDATABASEIMPL_H_ */
