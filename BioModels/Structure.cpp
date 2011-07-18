/*
 * Structure.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "Structure.h"

Structure::Structure() {}

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
