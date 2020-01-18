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

DBManager::DBManager() {
    // TODO Auto-generated constructor stub
}

DBManager::~DBManager() {
    // TODO Auto-generated destructor stub
}

DBManagerShrdPtr_t DBManager::getInstance() {
    if (!instance)
        std::cout << "\n instance is null !!!!";
    else
        std::cout << "\n instance is :  !!!!" << instance;
}

} /* namespace moviedb */
