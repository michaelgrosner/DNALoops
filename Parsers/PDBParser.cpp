/*
 * PDBParser.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "PDBParser.h"

PDBParser::PDBParser(string filename) : pdb_filename(filename) {

};

PDBParser::~PDBParser() {
	// TODO Auto-generated destructor stub
};

vector<Structure> PDBParser::parse_pdb_file() {

	// Open the file stream
	ifstream ifs;
	ifs.open(pdb_filename.c_str());
	string line;

	// Since some of the PDB files may have multiple Structures inside (i.e.
	// two HUs) seperated by a TER line, need to return multiple Structures
	vector<Structure> add_to_loop;
	Structure s;
	Chain     c;
	Residue   r;

	// Save the previous Residue and Chain PDB IDs to compare and decide whether
	// or not a new one needs to be made.
	int    r_id_prev = 0;
	string c_id_prev = "";
	while( getline(ifs, line) ) {
		if (boost::starts_with(line, "ATOM")) {

			// Information in PDB files follow strict column sizes. This may
			// not be very robust, but works fine with my PDB files.
			int a_id      = atoi(line.substr(6,5).c_str());
			string a_name = line.substr(13,3);
			string r_name = line.substr(17,3);
			string c_id   = line.substr(21,1);
			int r_id      = atoi(line.substr(23,3).c_str());

			double x = atof(line.substr(31,7).c_str());
			double y = atof(line.substr(38,7).c_str());
			double z = atof(line.substr(46,7).c_str());

			// If an Entity has a different ID than the one before,
			if (c_id_prev.compare(c_id) != 0) {
				c = Chain(c_id);	// Create a new chain with new ID
				s.add_child(c);		// Attach to parent Entity
				c_id_prev = c_id;	// Keep track of new ID
			}
			if (r_id_prev != r_id) {
				r = Residue(r_name, r_id);
				c.add_child(r);
				r_id_prev = r_id;
			}

			// Every line should contain a new atom, then attach it to a residue
			Atom a(a_name, x, y, z);
			r.add_child(a);

		}

		/* If a TER comes in the file, denoting multiple structures in the PDB,
		   add the previously parsed structure to the vector which will be
		   loaded into the loop, then start a new structure. If the TER is before
		   the EOF, an empty Structure will be created
		   TODO: Ensure that the empty structure does not get committed to DB */
		else if (boost::starts_with("TER", line)) {
			if (DEBUG) {cout << "Pushing back in " << pdb_filename << endl;}
			add_to_loop.push_back(s);
			s = Structure();
		}
	}

	if (!s.get_child_vector().size() == 0) {
		if (DEBUG) {cout << "Pushing back in " << pdb_filename << endl;}
		add_to_loop.push_back(s);
	}

	return add_to_loop;

}
