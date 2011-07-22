/*
 * main.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner
 */

#include "Includes.h"

#include "FileSystem/PDBDirectory.h"

#include "Parsers/PDBLoopParser.h"
#include "Parsers/X3DNAParser.h"
#include "Parsers/IdealStructureBuilder.h"

#include "BioModels/BasePair.h"
#include "BioModels/Entity.h"

#include "Tests/test_biomodels.h"
#include "Tests/test_database.h"

using namespace boost::filesystem;

int main () {
//	SQLiteDB* db = new SQLiteDB("db");

	//"PDBs/P1_open_1HU_78bp_1"
	//"PDBs/P2_open_2HU_78bp_1"

	//foreach (path mp, PDBDirectory().folders_in()) {

	PDBLoopParser loop_parser("PDBs/P2_open_2HU_78bp_1");

	Loop l = loop_parser.parse();

	l.run_x3dna();

	X3DNAParser x3dna_parser(l);
	x3dna_parser.parse();

	/*vector<Entity*> bps;
	l.get_sub_entities("StepParameter", bps);
	cout << bps.size() << endl;*/

	vector<Structure*> ideal_structures;
	foreach(path p, PDBDirectory().files_in("IdealStructures")) {
		IdealStructureBuilder isb(p);
		ideal_structures.push_back( isb.parse() );
	}

	l.find_ideal_sites(ideal_structures);
	cout << "---------------------------------" << endl;
	//}

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
