/*
 * Atom.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#ifndef ATOM_H_
#define ATOM_H_

#include "Includes.h"
#include "Entity.h"

class Atom : public Entity {
public:

	// Constructors and Destructors
	Atom(string name, double x, double y, double z);
	Atom();
	virtual ~Atom();

	void set_residue_pk(int fk);

	Vector3D<double> position();

	// Output methods
	friend ostream &operator<<(ostream &out, const Atom &a);
	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);

	// Get a string representing class name. Useful for the Entity base class
	string class_name() const {return "Atom";};

	// Is this atom an alpha carbon? Return true if so.
	bool is_CA();

	Vector3D<double> as_vector() {return Vector3D<double>(x,y,z);};

	// Database Methods
	bool table_exists(SQLiteDB &db);
	bool commit(SQLiteDB &db) {return false;};

private:
	double x;
	double y;
	double z;

};

#endif /* ATOM_H_ */
