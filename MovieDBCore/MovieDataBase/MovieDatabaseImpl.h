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

class MovieDatabaseImpl : public IMovieDataBase {
   public:
    MovieDatabaseImpl();
    virtual ~MovieDatabaseImpl();

    error_e insertMovieData(Movie *) override;
    error_e deleteMovieData(u_int) override;
    error_e getAllMovieData(movie_list &) override;

   private:
    std::unordered_map<u_int, Movie *> dbMap;
    static u_int m_movieId;
};

}  // namespace moviedb
#endif /* MOVIEDATABASE_MOVIEDATABASEIMPL_H_ */
