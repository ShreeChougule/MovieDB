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
    MovieDatabaseImpl() noexcept;
    MovieDatabaseImpl(const MovieDatabaseImpl &) noexcept;
    MovieDatabaseImpl(MovieDatabaseImpl &&) noexcept;
    MovieDatabaseImpl &operator=(const MovieDatabaseImpl &) noexcept;
    MovieDatabaseImpl &operator=(MovieDatabaseImpl &&) noexcept;
    virtual ~MovieDatabaseImpl() noexcept;

    error_e insertMovieData(Movie *) override;
    error_e deleteMovieData(dbId) override;
    error_e getAllMovieData(filter_type_e, filter_t, movie_list &) override;

   private:
    bool findCaseInsensitiveData(std::string, std::string);

   private:
    std::unordered_map<dbId, Movie *> m_dbMap;

    static dbId m_movieId;
};

}  // namespace moviedb
#endif /* MOVIEDATABASE_MOVIEDATABASEIMPL_H_ */
