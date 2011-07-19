/*
 * Loop.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
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

void Loop::print_pdb() {
	int structure_count = 0;
	int chain_count     = 0;
	int residue_count   = 0;
	int atom_count      = 0;

	foreach(Entity *le, get_child_vector()) {
		structure_count += 1;
		Structure *s = dynamic_cast<Structure*>(le);

		foreach(Entity *ce, le->get_child_vector()) {
			chain_count += 1;
			Chain *c = dynamic_cast<Chain*>(ce);

			foreach(Entity *cr, ce->get_child_vector()) {
				residue_count += 1;
				Residue *r = dynamic_cast<Residue*>(cr);

				foreach(Entity *ae, cr->get_child_vector()) {
					atom_count += 1;
					Atom *a = dynamic_cast<Atom*>(ae);
					cout << structure_count << " " << chain_count << " " << residue_count << " " << a->get_name() << endl;
				}

			}

		}

	}
}

ostream& operator<< (ostream &out, const Loop &l) {
	out << "<Loop "<< l.get_name() <<" with " << l.n_children() << " structures>";
	return out;
}
