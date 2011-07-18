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

void PDBParser::parse() {
	if (boost::starts_with(pdb_filename, "/")) {
		cout << pdb_filename << endl;
	}
	ifstream ifs;
	ifs.open(pdb_filename.c_str());
	string line;

	Structure s;
	Chain     c;
	Residue   r;

	while( getline(ifs, line) ) {
		if (boost::starts_with(line, "ATOM")) {
			int a_id      = atoi(line.substr(6,5).c_str());
			string name   = line.substr(13,3);
			string r_name = line.substr(17,3);
			string c_id   = line.substr(21,1);
			int r_id      = atoi(line.substr(23,3).c_str());

			double x = atof(line.substr(31,7).c_str());
			double y = atof(line.substr(38,7).c_str());
			double z = atof(line.substr(46,7).c_str());

			Atom a(name, x, y, z);
			//cout << a << endl;
		}
		else if (boost::starts_with("TER", line)) {

		}
	}

}
