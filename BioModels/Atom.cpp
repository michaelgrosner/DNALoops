/*
 * Atom.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "Atom.h"

Atom::Atom(string name, double x, double y, double z) : x(x),
														y(y),
														z(z) {
	set_name(name);
	is_bottom = true;
}

Atom::~Atom() {
	// TODO Auto-generated destructor stub
}

ostream& operator<< (ostream &out, const Atom &a) {
	out << "<Atom: " << a.get_name();
	out << ", x = " << a.x;
	out << ", y = " << a.y;
	out << ", z = " << a.z;
	out << ">";
	return out;
}
