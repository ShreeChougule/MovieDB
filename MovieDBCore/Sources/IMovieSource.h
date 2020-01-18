/*
 * IMovieSource.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include <memory>
#include "../MovieDataBase/DBManager.h"

#ifndef SOURCES_IMOVIESOURCE_H_
#define SOURCES_IMOVIESOURCE_H_

namespace moviedb {

class IMovieSource {
   public:
    IMovieSource() {}
    virtual ~IMovieSource() {}
    virtual void Initialize() = 0;
};

using MovieSourceShrdPtr_t = std::shared_ptr<IMovieSource>;

}  // namespace moviedb
#endif /* SOURCES_IMOVIESOURCE_H_ */
