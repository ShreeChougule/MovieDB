/*
 * SampleSource.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "IMovieSource.h"

#ifndef SOURCES_SAMPLESOURCE_H_
#define SOURCES_SAMPLESOURCE_H_

namespace moviedb {

class SampleSource : IMovieSource {
   public:
    SampleSource();
    virtual ~SampleSource();
    void Initialize() override;
};

} /* namespace moviedb */

#endif /* SOURCES_SAMPLESOURCE_H_ */
