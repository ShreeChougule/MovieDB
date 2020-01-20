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
    DBManager() noexcept;
    DBManager(const DBManager&) noexcept;
    DBManager(DBManager&&) noexcept;
    DBManager& operator=(const DBManager&) noexcept;
    DBManager& operator=(DBManager&&) noexcept;
    virtual ~DBManager() noexcept;

    error_e insertMovieData(Movie*);
    error_e deleteMovieData(dbId);
    error_e getAllMovieData(filter_type_e, filter_t, movie_list&);

   public:
    static std::shared_ptr<DBManager> getInstance();

   private:
    static std::shared_ptr<DBManager> instance;
    IMovieDataBaseShrdPtr impl;
};

using DBManagerShrdPtr_t = std::shared_ptr<DBManager>;

} /* namespace moviedb */

#endif /* MOVIEDATABASE_DBMANAGER_H_ */
