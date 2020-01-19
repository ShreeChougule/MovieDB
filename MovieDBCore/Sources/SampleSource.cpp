/*
 * SampleSource.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "SampleSource.h"
#include "movieTypes.h"

namespace moviedb {

SampleSource::SampleSource() {
    // TODO Auto-generated constructor stub
}

SampleSource::~SampleSource() {}

void SampleSource::Initialize() {
    m_dbMgr = DBManager::getInstance();
    FillDataBase();
}

void SampleSource::FillDataBase() {

    Movie *m = new Movie(0, HORROR, HINDI, 2018, "Stree", "Rajkummar Rao", "Shraddha Kapoor",
                         "Amar Kaushik",
                         "Rajkummar Rao, Shraddha Kapoor, Pankaj Tripathi, Aparshakti Khurana");
    m_dbMgr->insertMovieData(m);

    Movie *m1 = new Movie(0, BIOGRAPY, HINDI, 2019, "Gully Boy", "Ranveer Singh", "Alia Bhatt",
                          "Zoya Akhtar", "Ranveer Singh, Alia Bhatt, Siddhant Chaturvedi");
    m_dbMgr->insertMovieData(m1);

    Movie *m2 = new Movie(0, BIOGRAPY, HINDI, 2019, "Uri: The Surgical Strike", "Vicky Kaushal",
                          "Yami Gautam", "Aditya Dhar",
                          "Vicky Kaushal,Yami Gautam, Paresh Rawal, Mohit Raina, Kirti Kulhari");
    m_dbMgr->insertMovieData(m2);
}

} /* namespace moviedb */
