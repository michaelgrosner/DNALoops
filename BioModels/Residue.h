/*
 * Residue.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef RESIDUE_H_
#define RESIDUE_H_

#include "Includes.h"
#include "BioModels/Entity.h"
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
	string class_name() {return "Residue";};

private:
	int position;

	int pk;

};

#endif /* RESIDUE_H_ */
