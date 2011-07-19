/*
 * Atom.cpp
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#include "Atom.h"

Atom::Atom(string name, double x, double y, double z) :
	x(x), y(y), z(z) {
	set_name(name);
	is_bottom = true;
}

Atom::~Atom() {
	// TODO Auto-generated destructor stub
}

ostream& operator<<(ostream &out, const Atom &a) {
	out << "<Atom: " << a.get_name();
	out << ", x = " << a.x;
	out << ", y = " << a.y;
	out << ", z = " << a.z;
	out << ">";
	return out;
}

void Atom::as_pdb(int &chain_count, int &residue_count, int &atom_count,
		ofstream &pdbfile) {
	char *uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char chain_name = uppercase[chain_count];

	char buffer[100];
	sprintf(buffer,
			"%-6s%5i  %-4s%3s %1c%4i    % 8.3f% 8.3f% 8.3f  1.00 15.00\n",
			"ATOM", atom_count, get_name().c_str(),
			get_parent()->get_name().c_str(), chain_name, residue_count, x, y,
			z);

	cout << buffer;
	pdbfile << buffer;

	//cout << atom_count << " " << chain_count << " " << residue_count << " " << get_name() << endl;
}
