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
    /**
     * @brief constructor
     */
    SampleSource() noexcept;
    /**
     * @brief copy constructor
     * @param reference of source class
     */
    SampleSource(const SampleSource&) noexcept;
    /**
     * @brief move constructor
     * @param rvalue reference of source class
     */
    SampleSource(SampleSource&&) noexcept;
    /**
     * @brief assignment operator
     * @param reference of source class
     * @return address of newly created object
     */
    SampleSource& operator=(const SampleSource&) noexcept;
    /**
     * @brief move assignment operator
     * @param reference of source class
     * @return address of newly created object
     */
    SampleSource& operator=(SampleSource&&) noexcept;
    /**
     * @brief destructor
     */
    virtual ~SampleSource() noexcept;
    /**
     * @brief initializes class
     */
    void Initialize() override;

   private:
    /**
     * @brief to fill database with raw data
     */
    void FillDataBase();

   private:
    /**
     * ! \brief shared pointer of Database manager class
     */
    DBManagerShrdPtr_t m_dbMgr;
};

} /* namespace moviedb */

#endif /* SOURCES_SAMPLESOURCE_H_ */
