/*
 * Structure.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Structure : public Entity {
public:

	// Construction and destruction
	Structure();
	Structure(string name);
	virtual ~Structure();

	// Getters
	bool is_ideal() {return m_is_ideal;};

	// Setters
	void set_ideal() {m_is_ideal = true;};

	friend ostream &operator<<(ostream &out, const Structure &s);

	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);

	string class_name() {return "Structure";};

private:
	bool m_is_ideal;
};

#endif /* STRUCTURE_H_ */
