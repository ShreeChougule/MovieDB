/*
 * SampleSource.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "SampleSource.h"
#include "movieTypes.h"

namespace moviedb {

SampleSource::SampleSource() noexcept {}

SampleSource::SampleSource(const SampleSource& Source) noexcept : m_dbMgr(Source.m_dbMgr) {}

SampleSource::SampleSource(SampleSource&& Source) noexcept : m_dbMgr(std::move(Source.m_dbMgr)) {}

SampleSource& SampleSource::operator=(const SampleSource& Source) noexcept {
    m_dbMgr = Source.m_dbMgr;
    return *this;
}

SampleSource& SampleSource::operator=(SampleSource&& Source) noexcept {
    m_dbMgr = std::move(Source.m_dbMgr);
    return *this;
}

SampleSource::~SampleSource() noexcept {}

void SampleSource::Initialize() {
    m_dbMgr = DBManager::getInstance();
    FillDataBase();
}

void SampleSource::FillDataBase() {

    m_dbMgr->insertMovieData(new Movie(
        0, Genre::HORROR, Language::HINDI, 2018, "Stree", "Rajkummar Rao", "Shraddha Kapoor",
        "Amar Kaushik", "Rajkummar Rao, Shraddha Kapoor, Pankaj Tripathi, Aparshakti Khurana"));

    m_dbMgr->insertMovieData(new Movie(0, Genre::BIOGRAPY, Language::HINDI, 2019, "Gully Boy",
                                       "Ranveer Singh", "Alia Bhatt", "Zoya Akhtar",
                                       "Ranveer Singh, Alia Bhatt, Siddhant Chaturvedi"));

    m_dbMgr->insertMovieData(
        new Movie(0, Genre::BIOGRAPY, Language::HINDI, 2019, "Uri: The Surgical Strike",
                  "Vicky Kaushal", "Yami Gautam", "Aditya Dhar",
                  "Vicky Kaushal,Yami Gautam, Paresh Rawal, Mohit Raina, Kirti Kulhari"));

    m_dbMgr->insertMovieData(new Movie(
        0, Genre::DRAMA, Language::ENGLISH, 2019, "Joker", "Joaquin Phoenix", "Zazie Beetz",
        "	Todd Phillips", " Joaquin Phoenix, Robert De Niro,Zazie Beetz, Frances Conroy"));
}

} /* namespace moviedb */
