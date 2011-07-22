/*
 * Structure.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner*/

#include "Structure.h"


Structure::Structure() : m_is_ideal(false), ideal_sibling(NULL) {}

Structure::Structure(string name) : m_is_ideal(false), ideal_sibling(NULL)  {
	path p_name(name);
	set_name(p_name.stem());
}

Structure::~Structure() {
	// TODO Auto-generated destructor stub
}

ostream& operator<< (ostream &out, Structure &s) {
	if (s.is_ideal()) {
		out << "<Ideal ";
	}
	else {
		out << "<";
	}
	out << "Structure: " << s.get_name();
	if (s.ideal_structure() != NULL) {
		out << " (" << s.ideal_structure()->get_name() << ")";
	}
	out << " with " << s.n_of<Chain*>() << " chains>";
	return out;
}

void Structure::as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {
	foreach(Entity *ce, get_child_vector()) {
		chain_count += 1;
		ce->as_pdb(chain_count, residue_count, atom_count, pdbfile);
	}
}

Vector3D<double> Structure::center_of_mass() {
	vector<Atom*> atoms = get_all<Atom*>();

	// TODO: Raise
	if (atoms.size() == 0) {
		cout << "No atoms found" << endl;
	}

	double c[3];
	int CA_count = 0;

	for (int i=0; i < atoms.size(); i++) {
		Atom* a = atoms[i];
		if (!a->is_CA()) continue;
		c[X] += a->position()[X];
		c[Y] += a->position()[Y];
		c[Z] += a->position()[Z];
		CA_count += 1;
	}

	Vector3D<double> d = Vector3D<double>(c[0], c[1], c[2]);
	d /= (double)CA_count;
	return d;
}

Structure* Structure::ideal_structure() {
	// TODO: Raise if null
	return ideal_sibling;
}

void Structure::set_ideal_structure(Structure* s) {
	if (ideal_sibling != NULL && DEBUG) {
		cout << "WARNING: Replacing an already set ideal structure";
	}
	ideal_sibling = s;
}
