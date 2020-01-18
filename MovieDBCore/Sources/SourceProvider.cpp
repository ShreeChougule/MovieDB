/*
 * SourceProvider.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "SourceProvider.h"

namespace moviedb {

MovieSourceShrdPtr_t SourceProvider::getSource() { return (std::make_shared<SampleSource>()); }

} /* namespace moviedb */
