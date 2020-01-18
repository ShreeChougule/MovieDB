/*
 * Movie.h
 *
 *  Created on: 11-Jan-2020
 *      Author: kpit
 */

#include <string>
#include <utility>
#include <list>
#include <memory>
#include <iostream>
#ifndef MOVIE_H_
#define MOVIE_H_

namespace moviedb {

typedef unsigned int u_int;
typedef enum language { HINDI = 0, ENGLIS, MARATHI, TAMIL } lanuguage_e;

typedef enum list_operations { ADD_MOVIE = 0, UPDATE_MOVIE, REMOVE_MOVIE } list_operations_e;

typedef enum error { NO_ERROR, GENERIC_ERROR, NOT_IMPL } error_e;

typedef enum genre {
    HORROR = 0,
    COMEDY,
    SCI_FI,
    ACTION,
    ADVENTURE,
    ROMANCE,
    DOCUMETRY,
    ANIMATION,
    DRAMA,
    FANTACY,
    BIOGRAPY,
    SUPERHERO,
    MYSTERY,
    SILENT,
    THRILLER
} genre_e;

class Movie {
   public:
    Movie(const genre_e& genre, const lanuguage_e& lang, const u_int& year,
          const std::string& title, const std::string& hero, const std::string& heroine,
          const std::string& director, const std::string& casting)
        : m_genre(genre),
          m_language(lang),
          m_year(year),
          m_title(title),
          m_hero(hero),
          m_heroine(heroine),
          m_director(director),
          m_casting(casting) {
        std::cout << "\nDefault ctor";
    }

    virtual ~Movie() {}

    Movie(const Movie& Source)
        : m_genre(Source.m_genre),
          m_language(Source.m_language),
          m_year(Source.m_year),
          m_title(Source.m_title),
          m_hero(Source.m_hero),
          m_heroine(Source.m_heroine),
          m_director(Source.m_director),
          m_casting(Source.m_casting) {
        std::cout << "\nCopy ctor";
    }

    Movie(Movie&& Source)
        : m_genre(std::move(Source.m_genre)),
          m_language(std::move(Source.m_language)),
          m_year(std::move(Source.m_year)),
          m_title(std::move(Source.m_title)),
          m_hero(std::move(Source.m_hero)),
          m_heroine(std::move(Source.m_heroine)),
          m_director(std::move(Source.m_director)),
          m_casting(std::move(Source.m_casting)) {
        std::cout << "\nMove ctor";
    }

    Movie& operator=(const Movie& Source) {
        m_genre = Source.m_genre;
        m_language = Source.m_language;
        m_year = Source.m_year;
        m_title = Source.m_title;
        m_hero = Source.m_hero;
        m_heroine = Source.m_heroine;
        m_director = Source.m_director;
        m_casting = Source.m_casting;
        return *this;
    }

    Movie& operator=(Movie&& Source) {
        m_genre = std::move(Source.m_genre);
        m_language = std::move(Source.m_language);
        m_year = std::move(Source.m_year);
        m_title = std::move(Source.m_title);
        m_hero = std::move(Source.m_hero);
        m_heroine = std::move(Source.m_heroine);
        m_director = std::move(Source.m_director);
        m_casting = std::move(Source.m_casting);
        return *this;
    }

   public:
    genre_e m_genre;
    lanuguage_e m_language;
    u_int m_year;
    std::string m_title;
    std::string m_hero;
    std::string m_heroine;
    std::string m_director;
    std::string m_casting;
};

typedef std::list<Movie*> movie_list;

}  // namespace moviedb
#endif /* MOVIE_H_ */
