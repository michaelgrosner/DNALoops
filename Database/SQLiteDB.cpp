/*
 * SQLiteDB.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
 */

#include "SQLiteDB.h"

SQLiteDB::SQLiteDB(string filename) :
m_filename(filename) {
	open();
}
;

SQLiteDB::~SQLiteDB() {
	// TODO Auto-generated destructor stub
}

bool SQLiteDB::open() {
	if (sqlite3_open(m_filename.c_str(), &database) == SQLITE_OK) {
		return true;
	} else {
		return false;
	}
}

vector<vector<string> > SQLiteDB::query(char* query) {
	sqlite3_stmt *statement;
	vector<vector<string> > results;

	if (sqlite3_prepare_v2(database, query, -1, &statement, 0) == SQLITE_OK) {
		int cols = sqlite3_column_count(statement);
		int result = 0;
		while (true) {
			result = sqlite3_step(statement);

			if (result == SQLITE_ROW) {
				vector<std::string> values;
				for (int col = 0; col < cols; col++) {

					// The next lines may seem repetative but *ptr is needed to ensure a NULL pointer has not been returned, which would cause a crash.
					string s;
					char *ptr = (char*) sqlite3_column_text(statement, col);
					if (ptr)
						s = ptr;
					values.push_back(s);
				}
				results.push_back(values);
			} else {
				break;
			}
		}
		sqlite3_finalize(statement);
	}

	string error = sqlite3_errmsg(database);
	if (error != "not an error")
		cout << query << " " << error << endl;

	return results;

}

void SQLiteDB::close() {
	sqlite3_close(database);
}
