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

class SampleSource : public IMovieSource {
   public:
    SampleSource() noexcept;
    SampleSource(const SampleSource&) noexcept;
    SampleSource(SampleSource&&) noexcept;
    SampleSource& operator=(const SampleSource&) noexcept;
    SampleSource& operator=(SampleSource&&) noexcept;
    virtual ~SampleSource() noexcept;

    void Initialize() override;

   private:
    void FillDataBase();

   private:
    DBManagerShrdPtr_t m_dbMgr;
};

} /* namespace moviedb */

#endif /* SOURCES_SAMPLESOURCE_H_ */
