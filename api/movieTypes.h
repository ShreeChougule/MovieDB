/*
 * Movie.h
 *
 *  Created on: 11-Jan-2020
 *      Author: kpit
 */

#include <string>
#include <utility>
#include <list>

#ifndef MOVIE_H_
#define MOVIE_H_

typedef unsigned int u_int;
typedef enum language { HINDI = 0, ENGLIS, MARATHI, TAMIL } lanuguage_e;

typedef enum list_operations{ADD_MOVIE=0, UPDATE_MOVIE, REMOVE_MOVIE}list_operations_e;

typedef enum error{}error_e;

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
  /**
   * @param genre
   * @param lang
   * @param year
   * @param title
   * @param hero
   * @param heroine
   * @param director
   * @param casting
   */
  Movie(const genre_e& genre, const lanuguage_e& lang, const u_int& year,
        const std::string& title, const std::string& hero,
        const std::string& heroine, const std::string& director,
        const std::string& casting)
      : m_genre(genre),
        m_language(lang),
        m_year(year),
        m_title(title),
        m_hero(hero),
        m_heroine(heroine),
        m_director(director),
        m_casting(casting) {}

  virtual ~Movie() {}

  /**
   * @param Source
   */
  Movie(const Movie& Source)
      : m_genre(Source.m_genre),
        m_language(Source.m_language),
        m_year(Source.m_year),
        m_title(Source.m_title),
        m_hero(Source.m_hero),
        m_heroine(Source.m_heroine),
        m_director(Source.m_director),
        m_casting(Source.m_casting) {}
  /**
   * @param Source
   */
  Movie(Movie&& Source)
      : m_genre(std::move(Source.m_genre)),
        m_language(std::move(Source.m_language)),
        m_year(std::move(Source.m_year)),
        m_title(std::move(Source.m_title)),
        m_hero(std::move(Source.m_hero)),
        m_heroine(std::move(Source.m_heroine)),
        m_director(std::move(Source.m_director)),
        m_casting(std::move(Source.m_casting)) {}
  /**
   * @param Source
   * @return
   */
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
  /**
   * @param Source
   * @return
   */
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

#endif /* MOVIE_H_ */
