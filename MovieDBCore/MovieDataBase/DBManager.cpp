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

auto DBManager::insertMovieData(Movie* moviePtr) -> error_e {
    return impl->insertMovieData(moviePtr);
}

auto DBManager::deleteMovieData(dbId id) -> error_e { return impl->deleteMovieData(id); }

auto DBManager::getAllMovieData(filter_type_e type, filter_t filter, movie_list& list) -> error_e {
    return impl->getAllMovieData(type, filter, list);
}

} /* namespace moviedb */
