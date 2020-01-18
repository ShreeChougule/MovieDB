/*
 * MovieApplication.cpp
 *
 *  Created on: 14-Jan-2020
 *      Author: kpit
 */

#include "MovieApplication.h"
#include <iostream>

namespace moviedb {

MovieApplication::MovieApplication() { m_movieMgr = MovieManagerImpl::getInstance(); }

MovieApplication::~MovieApplication() { MovieManagerImpl::releaseInstance(); }

error_e MovieApplication::showMovies() {
    m_movieMgr->gettMovieList();
    return NO_ERROR;
}

error_e MovieApplication::searchMovie() {
    m_movieMgr->searchtMovieList();
    return NO_ERROR;
}

error_e MovieApplication::updateMovieList(list_operations_e op) {
    if (op == REMOVE_MOVIE) {
        u_int id;
        std::cout << "\n\t Enter Movie No. : ";
        std::cin >> id;
        m_movieMgr->updateMovieList(op, id);
    } else if (op == ADD_MOVIE) {
        m_movieMgr->updateMovieList(op, std::move(getMovieData()));
    }
    return NO_ERROR;
}

Movie MovieApplication::getMovieData() {
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

    return Movie((genre_e)genre, (lanuguage_e)lang, year, title, hero, heroine, director, casting);
}

}  // namespace moviedb
