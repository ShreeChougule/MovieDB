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

DBManager::DBManager() noexcept { impl = std::make_shared<MovieDatabaseImpl>(); }

DBManager::DBManager(const DBManager& Source) noexcept : impl(Source.impl) {}

DBManager::DBManager(DBManager&& Source) noexcept : impl(std::move(Source.impl)) {}

DBManager& DBManager::operator=(const DBManager& Source) noexcept {
    impl = Source.impl;
    return *this;
}

DBManager& DBManager::operator=(DBManager&& Source) noexcept {
    impl = std::move(Source.impl);
    return *this;
}

DBManager::~DBManager() noexcept { impl.reset(); }

DBManagerShrdPtr_t DBManager::getInstance() {
    if (!DBManager::instance) DBManager::instance = std::make_shared<DBManager>();
    return DBManager::instance;
}

error_e DBManager::insertMovieData(Movie* moviePtr) { return impl->insertMovieData(moviePtr); }

error_e DBManager::deleteMovieData(dbId id) { return impl->deleteMovieData(id); }

error_e DBManager::getAllMovieData(filter_type_e type, filter_t filter, movie_list& list) {
    return impl->getAllMovieData(type, filter, list);
}

} /* namespace moviedb */
