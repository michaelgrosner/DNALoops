/*
 * main.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner
 */

#include "Includes.h"

#include "Parsers/PDBLoopParser.h"
#include "Parsers/X3DNAParser.h"
#include "Parsers/IdealStructureBuilder.h"
#include "BioModels/BasePair.h"
#include "BioModels/Entity.h"

#include "Tests/test_biomodels.h"
#include "Tests/test_database.h"

using namespace std;

vector<path> files_in(string directory) {
	const path p = path(directory);
	directory_iterator end_itr;

	vector<path> files;

	// TODO: Raise an exception
	//if (!exists(p)) return false;

	for (directory_iterator itr(directory); itr != end_itr; itr++) {
		// If this is a file,
		if (is_regular_file(itr->path())) {
			files.push_back(itr->path());
		}
	}
	return files;
}

int main () {
//	SQLiteDB* db = new SQLiteDB("db");

	PDBLoopParser loop_parser("PDBs/A1_open_1HU_78bp_1");

	Loop l = loop_parser.parse();
	cout << l << endl;

	l.run_x3dna();

	X3DNAParser x3dna_parser(l);
	x3dna_parser.parse();

	/*vector<Entity*> bps;
	l.get_sub_entities("StepParameter", bps);
	cout << bps.size() << endl;*/

	vector<Structure*> ideal_structures;
	foreach(path p, files_in("IdealStructures")) {
		IdealStructureBuilder isb(p);
		ideal_structures.push_back( isb.parse() );
	}

	l.list_ideal_sites(ideal_structures);

	cout << "Exited with code 0" << endl;
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
