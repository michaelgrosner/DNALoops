/*
 * BasePair.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#ifndef BASEPAIR_H_
#define BASEPAIR_H_

#include "Includes.h"
#include "Entity.h"
#include "Loop.h"
#include "Residue.h"

class BasePairEntity: public Entity, public BasePair {
public:

	// BasePairEntitys should not be called by the blank constructor. Instead,
	// They should use the crazy constructor below to load the BasePair super
	// class method beforehand to take advantage of the DNASim libary's methods.
	BasePairEntity();
	virtual ~BasePairEntity();

	BasePairEntity(const vector<int>& pairing, const int& position,
			const CoordinateSystem& coords, Entity& e);

	void as_pdb(int &chain_count, int &residue_count, int &atom_count,
			ofstream &pdbfile) {}
	string class_name() const {return "BasePair";}

	// Output methods
	friend ostream &operator<<(ostream &out, const BasePairEntity &bp);

	bool commit(SQLiteDB &db) {return false;};

private:
	int strand_position;
};

#endif /* BASEPAIR_H_ */
