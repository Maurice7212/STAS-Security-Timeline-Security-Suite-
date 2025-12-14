#ifndef SQLITE_DB_H
#define SQLITE_DB_H

#include <string>
#include <vector>
#include "dynamic_timeline.h"  // For Event

struct sqlite3;

class SQLiteDB {
private:
    sqlite3* db;
public:
    SQLiteDB(const std::string& dbfile);
    ~SQLiteDB();
    void storeEvents(const std::vector<Event>& events);
};

#endif