/*
 * SQLiteDB.h
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner*/

#ifndef SQLITEDB_H_
#define SQLITEDB_H_

#include "Includes.h"

using namespace std;

class SQLiteDB {
public:
	SQLiteDB(string filename);
	virtual ~SQLiteDB();

	bool open();
	vector<vector<string> > query(char* query);

	int create_table(char* table_name);

	void close();
private:
	sqlite3* database;
	string   m_filename;
};

#endif /* SQLITEDB_H_ */
