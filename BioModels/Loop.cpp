/*
 * Loop.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner Grosner
 */

#include "Loop.h"
#include "Structure.h"
#include "Chain.h"
#include "Residue.h"
#include "Atom.h"

Loop::Loop() {
	is_top = true;
}

Loop::Loop(string name) {
	set_name(name);
	is_top = true;
}

Loop::~Loop() {
	// TODO Auto-generated destructor stub
}

void Loop::as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {
	foreach(Entity *le, get_child_vector()) {
		le->as_pdb(chain_count, residue_count, atom_count, pdbfile);
		pdbfile << "TER\n";
	}
}

ostream& operator<< (ostream &out, const Loop &l) {
	out << "<Loop "<< l.get_name() <<" with " << l.n_children() << " structures>";
	return out;
}
