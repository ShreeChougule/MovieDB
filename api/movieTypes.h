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
#include <thread>
#include <future>
#include <iostream>

#ifndef MOVIE_H_
#define MOVIE_H_

namespace moviedb {

using u_int = unsigned int;
typedef enum class Language { HINDI = 0, ENGLIS, MARATHI, TAMIL } lanuguage_e;

typedef enum class Operations { ADD_MOVIE = 0, UPDATE_MOVIE, REMOVE_MOVIE } list_operations_e;

typedef enum class FilterType {
    TITLE = 0,
    HERO,
    HEROINE,
    DIRECTOR,
    GENRE,
    CASTING,
    YEAR,
    ALL
} filter_type_e;

using filter_t = std::string;

typedef enum class Error { NO_ERROR, GENERIC_ERROR, DATA_NOT_FOUND, NOT_IMPL } error_e;

typedef enum Genre {
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
    Movie(const u_int& Id, const genre_e& genre, const lanuguage_e& lang, const u_int& year,
          const std::string& title, const std::string& hero, const std::string& heroine,
          const std::string& director, const std::string& casting) noexcept
        : m_Id(Id),
          m_genre(genre),
          m_language(lang),
          m_year(year),
          m_title(title),
          m_hero(hero),
          m_heroine(heroine),
          m_director(director),
          m_casting(casting) {}

    virtual ~Movie() noexcept { std::cout << "\n~Movie() Called !!!!\n"; }

    Movie(const Movie& Source) noexcept
        : m_Id(Source.m_Id),
          m_genre(Source.m_genre),
          m_language(Source.m_language),
          m_year(Source.m_year),
          m_title(Source.m_title),
          m_hero(Source.m_hero),
          m_heroine(Source.m_heroine),
          m_director(Source.m_director),
          m_casting(Source.m_casting) {}

    Movie(Movie&& Source) noexcept
        : m_Id(std::move(Source.m_Id)),
          m_genre(std::move(Source.m_genre)),
          m_language(std::move(Source.m_language)),
          m_year(std::move(Source.m_year)),
          m_title(std::move(Source.m_title)),
          m_hero(std::move(Source.m_hero)),
          m_heroine(std::move(Source.m_heroine)),
          m_director(std::move(Source.m_director)),
          m_casting(std::move(Source.m_casting)) {}

    Movie& operator=(const Movie& Source) noexcept {
        m_Id = Source.m_Id;
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

    Movie& operator=(Movie&& Source) noexcept {
        m_Id = std::move(Source.m_Id);
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
    u_int m_Id;
    genre_e m_genre;
    lanuguage_e m_language;
    u_int m_year;
    std::string m_title;
    std::string m_hero;
    std::string m_heroine;
    std::string m_director;
    std::string m_casting;
};

using movie_list = std::list<Movie*>;

}  // namespace moviedb
#endif /* MOVIE_H_ */
