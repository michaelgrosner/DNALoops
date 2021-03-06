/*
 * Residue.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner*/
#ifndef RESIDUE_H_
#define RESIDUE_H_

#include "Includes.h"
#include "Entity.h"
#include <boost/algorithm/string.hpp>

class Residue : public Entity {
public:
	Residue();
	Residue(string name, int position);
	virtual ~Residue();

	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);

	// Return true if the residue is a nucleic acid
	bool is_na();

	// Return true if the residue is an amino acid
	bool is_aa();

	// Output
	friend ostream &operator<<(ostream &out, const Residue &r);
	string class_name() const {return "Residue";};

	bool commit(SQLiteDB &db) {return false;};

private:
	int position;

	int pk;

};

#endif /* RESIDUE_H_ */
