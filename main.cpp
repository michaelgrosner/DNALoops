/*
 * main.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
 */

#include <iostream>
#include "Database/SQLiteDB.h"
#include "Parsers/PDBLoopParser.h"
using namespace std;

int main () {
	/*SQLiteDB* db;
	db = new SQLiteDB("db");

	db->query("CREATE TABLE a (a INTEGER, b INTEGER);");
	db->query("INSERT INTO a VALUES(1,2);");
	db->query("INSERT INTO a VALUES(5,4);");

	vector<vector<string> > result;
	result = db->query("SELECT a,b FROM a;");

	vector<vector<string> >::iterator it;
	for (it = result.begin(); it < result.end(); ++it) {
		vector<string> row = *it;
		cout << "A=" << row.at(0) << "B=" << row.at(1) << endl;
	}

	db->close();*/

	PDBLoopParser* loop_parser;
	loop_parser = new PDBLoopParser("/home/grosner/Dropbox/DNALoops/PDBs/A2_open_2HU_78bp_1/");
	loop_parser->parse();

}
