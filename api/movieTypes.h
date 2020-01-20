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
/**
 * ! \brief language enum class
 */
typedef enum class Language { HINDI = 0, ENGLIS, MARATHI, TAMIL } lanuguage_e;
/**
 * ! \brief list operations enum class
 */
typedef enum class Operations { ADD_MOVIE = 0, UPDATE_MOVIE, REMOVE_MOVIE } list_operations_e;
/**
 * ! \brief type of filter enum
 */
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
/**
 * ! \brief enum for Errors
 */
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
    /**
     * @brief Default constructor
     * @param Id movie id
     * @param genre genre of movie
     * @param lang movie language
     * @param year launched year
     * @param title movie's title
     * @param hero name of hero
     * @param heroine name of heroine
     * @param director name of director
     * @param casting names of actors
     */
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
    /**
     * destructor of movie
     */
    virtual ~Movie() noexcept { std::cout << "\n~Movie() Called !!!!\n"; }
    /**
     * @brief Copy Constructor
     * @param Source source movie to copy
     */
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
    /**
     * @brief Move Constructor
     * @param Source source movie to move
     */
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
    /**
     * @brief Assignment operator
     * @param Source source movie to assign
     * @return movie object reference
     */
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
    /**
     * @brief Move Assignment operator
     * @param Source source movie to assign
     * @return movie object reference
     */
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
    /**
     * ! \brief movie's unique id
     */
    u_int m_Id;
    /**
     * ! \brief enum - movie's genre
     */
    genre_e m_genre;
    /**
     * ! \brief enum - movie's language
     */
    lanuguage_e m_language;
    /**
     * ! \brief movie's lanched year
     */
    u_int m_year;
    /**
     * ! \brief movie's title
     */
    std::string m_title;
    /**
     * ! \brief name of hero
     */
    std::string m_hero;
    /**
     * ! \brief name of heroine
     */
    std::string m_heroine;
    /**
     * ! \brief name of director
     */
    std::string m_director;
    /**
     * ! \brief names actors are in movie
     */
    std::string m_casting;
};
/**
 * ! \brief list of movie object addresses
 */
using movie_list = std::list<Movie*>;

}  // namespace moviedb
#endif /* MOVIE_H_ */
