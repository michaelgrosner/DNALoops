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

Loop test_loopdepth() {
	Loop *l = new Loop();

	Structure *s = new Structure();
	l->add_child(s);

	Chain *c = new Chain();
	s->add_child(c);

	Residue *r = new Residue();
	c->add_child(r);

	Atom *a1 = new Atom("a1", 1.0, 0.0, 2.0);
	Atom *a2 = new Atom("a2", 2.0, 1.5, 1.0);
	r->add_child(a1);
	r->add_child(a2);

	return l;
}

void test_biomodels() {

	Loop l = test_loopdepth();

	foreach(Entity *s, l.get_child_vector()) {
		cout << "Structure: " << s->n_children() << endl;
	}

	cout << "Completed without error" << endl;

}
