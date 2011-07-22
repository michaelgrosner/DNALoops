/*
 * test_database.h
 *
 *  Created on: Jul 19, 2011
 *      Author: grosner
 */

#ifndef TEST_DATABASE_H_
#define TEST_DATABASE_H_

#include "Includes.h"

bool test_database () {
	SQLiteDB* db = new SQLiteDB("test_db");

	db->create_table("Atom", "a INTEGER, b INTEGER");

//	db->query("CREATE TABLE a (a INTEGER, b INTEGER);");
//	db->query("INSERT INTO a VALUES(1,2);");
//	db->query("INSERT INTO a VALUES(5,4);");
//
//	vector<vector<string> > result;
//	result = db->query("SELECT a,b FROM a;");
//
//	vector<vector<string> >::iterator it;
//	for (it = result.begin(); it < result.end(); ++it) {
//		vector<string> row = *it;
//		cout << "A=" << row.at(0) << "B=" << row.at(1) << endl;
//	}

	db->close();

	// Clean up
	system("rm -rf test_db");
	cout << "done" << endl;
	return true;
}

#endif /* TEST_DATABASE_H_ */
