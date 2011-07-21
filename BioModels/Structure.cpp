/*
 * Structure.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner*/
#include "Structure.h"

Structure::Structure() {
	m_is_ideal = false;
}

Structure::Structure(string name) {
	set_name(name);
}

Structure::~Structure() {
	// TODO Auto-generated destructor stub
}

ostream& operator<< (ostream &out, const Structure &s) {
	out << "<Structure: " << s.get_name() << " with " << s.n_children() << " chains>";
	return out;
}

void Structure::as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {
	foreach(Entity *ce, get_child_vector()) {
		chain_count += 1;
		ce->as_pdb(chain_count, residue_count, atom_count, pdbfile);
	}
}
