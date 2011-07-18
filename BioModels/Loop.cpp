/*
 * Loop.cpp
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
 */

#include "Loop.h"

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

ostream& operator<< (ostream &out, const Loop &l) {
	out << "<Loop "<< l.get_name() <<" with " << l.n_children() << " structures>";
	return out;
}
