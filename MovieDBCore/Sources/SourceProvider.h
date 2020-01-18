/*
 * SourceProvider.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "SampleSource.h"

#ifndef SOURCES_SOURCEPROVIDER_H_
#define SOURCES_SOURCEPROVIDER_H_

namespace moviedb {

class SourceProvider {
   public:
    SourceProvider() = delete;
    virtual ~SourceProvider() = delete;
    static MovieSourceShrdPtr_t getSource();
};

} /* namespace moviedb */

#endif /* SOURCES_SOURCEPROVIDER_H_ */
