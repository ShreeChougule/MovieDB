/*
 * MovieDB.h
 *
 *  Created on: 11-Jan-2020
 *      Author: Shree
 */

#ifndef MOVIEDB_H_
#define MOVIEDB_H_

class MovieDB {
public:
	MovieDB();
	virtual ~MovieDB();
	MovieDB(const MovieDB &other);
	MovieDB(MovieDB &&other);
	MovieDB& operator=(const MovieDB &other);
	MovieDB& operator=(MovieDB &&other);
};

#endif /* MOVIEDB_H_ */
