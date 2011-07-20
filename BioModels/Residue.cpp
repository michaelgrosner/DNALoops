/*
 * Residue.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner Grosner
 */

#include "Residue.h"

Residue::Residue() {}

Residue::Residue(string name, int position) : position(position) {
	set_name(name);
}

Residue::~Residue() {
	// TODO Auto-generated destructor stub
}

ostream& operator<< (ostream &out, const Residue &r) {
	out << "<Residue " << r.get_name() << " with " << r.n_children() << " atoms>";
	return out;
}

void Residue::as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {
	foreach(Entity *ae, get_child_vector()) {
		atom_count += 1;
		ae->as_pdb(chain_count, residue_count, atom_count, pdbfile);
	}
}

bool Residue::is_na() {
	if (boost::trim_copy(get_name()).length() == 1) return true;
	else return false;
}

bool Residue::is_aa() {
	if (is_na()) return false;
	else return true;
}
