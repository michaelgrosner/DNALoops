/*
 * test_biomodels.cpp
 *
 *  Created on: Jul 18, 2011
 *      Author: grosner
 */

#include "BioModels/Entity.h"
#include "BioModels/Atom.h"
#include "BioModels/Residue.h"
#include "BioModels/Chain.h"
#include "BioModels/Structure.h"
#include "BioModels/Loop.h"

#include "boost/foreach.hpp"

Loop* test_loopconstruction() {
	Loop *l = new Loop();

	Structure *s = new Structure("S1");
	l->add_child(s);

	Chain *c = new Chain();
	s->add_child(c);

	Residue *r = new Residue();
	c->add_child(r);

	Atom *a1 = new Atom("a1", 1.0, 0.0, 2.0);
	Atom *a2 = new Atom("a2", 2.0, 1.5, 1.0);
	r->add_child(a1);
	r->add_child(a2);

	Structure *s2 = new Structure("S2");
	l->add_child(s2);

	Chain *c2 = new Chain();
	s->add_child(c2);

	Residue *r2 = new Residue();
	c->add_child(r2);

	Atom *a12 = new Atom("a1", 1.0, 0.0, 2.0);
	Atom *a22 = new Atom("a2", 2.0, 1.5, 1.0);
	r->add_child(a12);
	r->add_child(a22);

	return l;
}

void test_biomodels() {

	Loop *l = test_loopconstruction();

	foreach(Entity *s, l->get_child_vector()) {
		cout << "Structure: " << s << endl;
	}

	cout << "Number of atoms in Loop: " << l->get_atoms().size() << endl;

	cout << "Completed without error" << endl;

}
