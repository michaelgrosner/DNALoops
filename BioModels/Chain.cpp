/*
 * Chain.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
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
