/*
 * Chain.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner Grosner
 */

#include "Chain.h"

Chain::Chain(string name) {
	set_name(name);
}
Chain::Chain() {}

Chain::~Chain() {
	// TODO Auto-generated destructor stub
}

ostream& operator<< (ostream &out, const Chain &c) {
	out << "<Chain " << c.get_name() << " with " << c.n_children() << " residues>";
	return out;
}

void Chain::as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {
	foreach(Entity *cr, get_child_vector()) {
		residue_count += 1;
		cr->as_pdb(chain_count, residue_count, atom_count, pdbfile);
	}
}
