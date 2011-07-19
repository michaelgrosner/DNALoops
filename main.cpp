/*
 * main.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
 */
#include <iostream>
#include "Database/SQLiteDB.h"
#include "Parsers/PDBLoopParser.h"
#include "Parsers/X3DNAParser.h"
#include "BioModels/Entity.h"
#include "Tests/test_biomodels.h"
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

	PDBLoopParser loop_parser("PDBs/A2_open_2HU_78bp_1/");

	Loop l = loop_parser.parse();
	cout << "Child Structures: " << l.n_children() << endl;

	vector<Entity*> atoms;
	//l.get_atoms(atoms);
	//l.run_x3dna();

	X3DNAParser x3dna_parser(l);
	x3dna_parser.get_ref_frames();

	cout << "done" << endl;

	//test_biomodels();
	return 0;
}
