/*
 * DBManager.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include <memory>
#include "MovieDatabaseImpl.h"

#ifndef MOVIEDATABASE_DBMANAGER_H_
#define MOVIEDATABASE_DBMANAGER_H_

namespace moviedb {

class DBManager {
   public:
    /**
     * @brief constructor
     */
    DBManager() noexcept;
    /**
     * @brief copy constructor
     * @param reference of source object
     */
    DBManager(const DBManager&) noexcept;
    /**
     * @brief move constructor
     * @param rvalue reference of source object
     */
    DBManager(DBManager&&) noexcept;
    /**
     * @brief assignment operator
     * @param reference of source object
     * @return reference of newly created object
     */
    DBManager& operator=(const DBManager&) noexcept;
    /**
     * @brief move assignment operator
     * @param rvalue reference of source object
     * @return reference of newly created object
     */
    DBManager& operator=(DBManager&&) noexcept;
    /**
     * @brief destructor
     */
    virtual ~DBManager() noexcept;

    /**
     * @brief forwards movie data to add to implementation class
     * @param address of movie object
     * @return status
     */
    auto insertMovieData(Movie*) -> error_e;
    /**
     * @brief forward movie id to remove movie to implementation class
     * @param id of movie
     * @return status
     */
    auto deleteMovieData(dbId) -> error_e;
    /**
     * @brief forward all info to implementation class to retrieve list
     * @param filter type
     * @param filter data
     * @param reference of list object
     * @return status
     */
    auto getAllMovieData(filter_type_e, filter_t, movie_list&) -> error_e;

   public:
    /**
     * @brief public instance of own object
     * @return shared pointer of own object
     */
    static std::shared_ptr<DBManager> getInstance();

   private:
    /**
     * ! \brief shared pointer of own object
     */
    static std::shared_ptr<DBManager> instance;
    /**
     * ! \brief shared pointer of implementation class
     */
    IMovieDataBaseShrdPtr impl;
};

using DBManagerShrdPtr_t = std::shared_ptr<DBManager>;

} /* namespace moviedb */

#endif /* MOVIEDATABASE_DBMANAGER_H_ */
