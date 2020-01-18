/*
 * MovieBrowserImpl.h
 *
 *  Created on: 12-Jan-2020
 *      Author: kpit
 */

#include "movieTypes.h"

#ifndef MOVIEBROWSERIMPL_H_
#define MOVIEBROWSERIMPL_H_

namespace moviedb {

class MovieBrowserImpl {
   public:
    MovieBrowserImpl();
    virtual ~MovieBrowserImpl();
    error_e createMovieList();
};

using MovieBrowserUniqPtr = std::unique_ptr<MovieBrowserImpl>;

}  // namespace moviedb
#endif /* MOVIEBROWSERIMPL_H_ */
