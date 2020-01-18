/*
 * MovieDatabaseImpl.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#ifndef MOVIEDATABASE_MOVIEDATABASEIMPL_H_
#define MOVIEDATABASE_MOVIEDATABASEIMPL_H_
#include "IMovieDatabase.h"

namespace moviedb {

class MovieDatabaseImpl : public IMovieDataBase {
   public:
    MovieDatabaseImpl();
    virtual ~MovieDatabaseImpl();
};

}  // namespace moviedb
#endif /* MOVIEDATABASE_MOVIEDATABASEIMPL_H_ */
