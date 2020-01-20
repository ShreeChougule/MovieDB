/*
 * IMovieDatabase.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */
#include "movieTypes.h"

#ifndef MOVIEDATABASE_IMOVIEDATABASE_H_
#define MOVIEDATABASE_IMOVIEDATABASE_H_

namespace moviedb {

class IMovieDataBase {
   public:
    /**
     * @brief destructor
     */
    virtual ~IMovieDataBase() {}
    /**
     * @brief interface function to add data in database
     * @param address of movie object
     * @return status
     */
    virtual error_e insertMovieData(Movie*) = 0;
    /**
     * @brief interface function to remove
     * @param id of movie
     * @return status
     */
    virtual error_e deleteMovieData(u_int) = 0;
    /**
     * @brief interface function to fetch required data
     * @param filter type
     * @param filter value
     * @param reference of movie list object
     * @return status
     */
    virtual error_e getAllMovieData(filter_type_e, filter_t, movie_list&) = 0;
};

using IMovieDataBaseShrdPtr = std::shared_ptr<IMovieDataBase>;

}  // namespace moviedb
#endif /* MOVIEDATABASE_IMOVIEDATABASE_H_ */
