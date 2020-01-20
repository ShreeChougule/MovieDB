/*
 * MovieApplication.cpp
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */

#include "MovieApplication.h"
#include <iostream>

namespace moviedb {

MovieApplication::MovieApplication() noexcept {
    m_movieMgr = MovieManagerImpl::getInstance();
    m_movieMgr->Initialize();
}
MovieApplication::MovieApplication(const MovieApplication& Source) noexcept
    : m_movieMgr(Source.m_movieMgr) {}

MovieApplication::MovieApplication(const MovieApplication&& Source) noexcept
    : m_movieMgr(std::move(Source.m_movieMgr)) {}

MovieApplication& MovieApplication::operator=(const MovieApplication& Source) noexcept {
    m_movieMgr = Source.m_movieMgr;
    return *this;
}

MovieApplication& MovieApplication::operator=(const MovieApplication&& Source) noexcept {
    m_movieMgr = std::move(Source.m_movieMgr);
    return *this;
}

MovieApplication::~MovieApplication() noexcept { MovieManagerImpl::releaseInstance(); }

error_e MovieApplication::showMovies() {
    movie_list list;
    m_movieMgr->OnRequestMovieList(FilterType::ALL, "", list);
    showList(list);
    return Error::NO_ERROR;
}

error_e MovieApplication::searchMovie() {
    u_int searchType;
    filter_t filter;
    movie_list list;

    std::cout << "\n\t# SEARCH BY ? #\n\tTITLE(0), HERO(1), HEROINE(2), DIRECTOR(3), GENRE(4), "
                 "CASTING(5), YEAR(6)\n\tChoose Option : ";
    std::cin >> searchType;
    std::cin.ignore();

    if (searchType == 4) {
        std::cout
            << "\n\tHORROR(0), COMEDY(1), SCI_FI(2), ACTION(3), ADVENTURE(4), ROMANCE(5), "
               "DOCUMETRY(6), ANIMATION(7), DRAMA(8), FANTACY(9), BIOGRAPY(10), SUPERHERO(11), "
               "MYSTERY(12), SILENT(13), THRILLER(14).\n\tChoose Genre : ";
    } else {
        std::cout << "\n\t Search : ";
    }
    std::getline(std::cin, filter);

    m_movieMgr->OnRequestMovieList((filter_type_e)searchType, filter, list);
    showListDetails(list);
    return Error::NO_ERROR;
}

error_e MovieApplication::updateMovieList(const list_operations_e& op) {
    if (op == Operations::REMOVE_MOVIE) {
        u_int id;
        std::cout << "\n\t Enter Movie Id. : ";
        std::cin >> id;
        m_movieMgr->OnUpdateMovieList(op, id);
    } else if (op == Operations::ADD_MOVIE) {
        m_movieMgr->OnUpdateMovieList(op, getMovieData());
    }
    return Error::NO_ERROR;
}

Movie* MovieApplication::getMovieData() {
    u_int genre;
    u_int lang;
    u_int year;
    std::string title;
    std::string hero;
    std::string heroine;
    std::string director;
    std::string casting;

    std::cout << "\n\tHORROR(0), COMEDY(1), SCI_FI(2), ACTION(3), ADVENTURE(4), ROMANCE(5), "
                 "DOCUMETRY(6), ANIMATION(7), DRAMA(8), FANTACY(9), BIOGRAPY(10), SUPERHERO(11), "
                 "MYSTERY(12), SILENT(13), THRILLER(14).\n\tChoose Genre : ";
    std::cin >> genre;

    std::cout << "\n\tHINDI(0), ENGLIS(1), MARATHI(2), TAMIL(3).\n\tChoose Language : ";
    std::cin >> lang;

    std::cout << "\n\t Enter Year : ";
    std::cin >> year;

    std::cin.ignore();
    std::cout << "\n\t Enter Title : ";
    std::getline(std::cin, title);
    std::cout << "\n\t Enter Hero's Name : ";
    std::getline(std::cin, hero);

    std::cout << "\n\t Enter Heroine's Name : ";
    std::getline(std::cin, heroine);

    std::cout << "\n\t Enter Director's Name : ";
    std::getline(std::cin, director);

    std::cout << "\n\t Enter Casting Names : ";
    std::getline(std::cin, casting);

    return new Movie(0, (genre_e)genre, (lanuguage_e)lang, year, title, hero, heroine, director,
                     casting);
}

void MovieApplication::showList(const movie_list& list) {
    std::cout << "\n\tMOVIE ID.\t\tTITLE";
    for (auto it : list) {
        std::cout << "\n\t   " << it->m_Id << "\t\t'" << it->m_title << "'  (" << it->m_year << ")"
                  << "  [" << getGenreStr(it->m_genre) << "]";
    }
}

void MovieApplication::showListDetails(const movie_list& list) {
    std::cout << "\n\t # MOVIE LIST (DETAILS) #";
    for (auto it : list) {
        std::cout << "\n\n\tTITLE : '" << it->m_title << "'  (" << it->m_year << ")"
                  << "  [" << getGenreStr(it->m_genre) << "]\n\tHERO : " << it->m_hero
                  << "\n\tHEROINE : " << it->m_heroine << "\n\tDIRECTOR : " << it->m_director
                  << "\n\tCASTING : " << it->m_casting;
    }
    std::cout << "\n\n";
}

std::string MovieApplication::getGenreStr(const genre_e& genre) {
    std::string ret;
    switch (genre) {
        case HORROR: ret = "HORROR"; break;
        case COMEDY: ret = "COMEDY"; break;
        case SCI_FI: ret = "SCI_FI"; break;
        case ACTION: ret = "ACTION"; break;
        case ADVENTURE: ret = "ADVENTURE"; break;
        case ROMANCE: ret = "ROMANCE"; break;
        case DOCUMETRY: ret = "DOCUMETRY"; break;
        case ANIMATION: ret = "ANIMATION"; break;
        case DRAMA: ret = "DRAMA"; break;
        case FANTACY: ret = "FANTACY"; break;
        case BIOGRAPY: ret = "BIOGRAPY"; break;
        case SUPERHERO: ret = "SUPERHERO"; break;
        case MYSTERY: ret = "MYSTERY"; break;
        case SILENT: ret = "SILENT"; break;
        case THRILLER: ret = "THRILLER"; break;
    }
    return ret;
}

}  // namespace moviedb
