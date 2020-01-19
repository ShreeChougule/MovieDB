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
    DBManager();
    virtual ~DBManager();

    error_e insertMovieData(Movie*);
    error_e deleteMovieData(dbId);
    error_e getAllMovieData(filter_type_e, filter_t, movie_list&);

   public:
    static std::shared_ptr<DBManager> getInstance();

   private:
    static std::shared_ptr<DBManager> instance;
    IMovieDataBase* impl;
};

using DBManagerShrdPtr_t = std::shared_ptr<DBManager>;

} /* namespace moviedb */

#endif /* MOVIEDATABASE_DBMANAGER_H_ */
