/*
 * DBManager.cpp
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include "DBManager.h"

#include <iostream>

namespace moviedb {

std::shared_ptr<DBManager> DBManager::instance = nullptr;

DBManager::DBManager() { impl = new MovieDatabaseImpl(); }

DBManager::~DBManager() {
    if (impl) {
        delete impl;
        impl = nullptr;
    }
}

DBManagerShrdPtr_t DBManager::getInstance() {
    if (!instance) instance = std::make_shared<DBManager>();

    return DBManager::instance;
}

error_e DBManager::insertMovieData(Movie* moviePtr) { return impl->insertMovieData(moviePtr); }

error_e DBManager::deleteMovieData(dbId id) { return impl->deleteMovieData(id); }

error_e DBManager::getAllMovieData(filter_type_e type, filter_t filter, movie_list& list_r) {
    return impl->getAllMovieData(type, filter, list_r);
}

} /* namespace moviedb */
