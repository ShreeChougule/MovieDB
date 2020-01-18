/*
 * DBManager.h
 *
 *  Created on: 18-Jan-2020
 *      Author: kpit
 */

#include <memory>

#ifndef MOVIEDATABASE_DBMANAGER_H_
#define MOVIEDATABASE_DBMANAGER_H_

namespace moviedb {

class DBManager {
   public:
    static std::shared_ptr<DBManager> getInstance();

   private:
    DBManager();
    virtual ~DBManager();

   private:
    static std::shared_ptr<DBManager> instance;
};

using DBManagerShrdPtr_t = std::shared_ptr<DBManager>;

} /* namespace moviedb */

#endif /* MOVIEDATABASE_DBMANAGER_H_ */
