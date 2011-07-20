/*
 * main.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner
 */
#include <iostream>
#include "Database/SQLiteDB.h"
#include "Parsers/PDBLoopParser.h"
#include "Parsers/X3DNAParser.h"
#include "BioModels/Entity.h"

#include "Tests/test_biomodels.h"
#include "Tests/test_database.h"

using namespace std;

int main () {
//	SQLiteDB* db = new SQLiteDB("db");

	PDBLoopParser loop_parser("PDBs/A2_open_2HU_78bp_1/");

	Loop l = loop_parser.parse();
	cout << l << endl;

	l.run_x3dna();

	X3DNAParser x3dna_parser(l);
	x3dna_parser.parse();

	cout << "done" << endl;
//
//	// Commit all changes to database!
//	if (l.commit(*db)) {
//		cout << "Successfully saved Database" << endl;
//	}
//	else {
//		cout << "Error saving Database";
//	}
//
//	db->close();
//	test_database();
	return 0;
}
