/*
 * Structure.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner*/
#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include "Includes.h"
#include "Entity.h"
#include "Atom.h"
#include "BasePair.h"
#include "Chain.h"

class Structure : public Entity {
public:

	// Construction and destruction
	Structure();
	Structure(string name);
	virtual ~Structure();

	// Getters
	bool is_ideal() {return m_is_ideal;};
	Vector3D<double> center_of_mass();
	Structure* ideal_structure();

	// Setters
	void set_ideal() {m_is_ideal = true;};
	void set_ideal_structure(Structure* s);

	friend ostream &operator<<(ostream &out, Structure &s);

	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);

	string class_name() const {return "Structure";};

	bool commit(SQLiteDB &db) {return false;};

private:
	bool m_is_ideal;

	/* When dealing with a real Structure, this denotes it's idealized version */
	Structure *ideal_sibling;
};

#endif /* STRUCTURE_H_ */
