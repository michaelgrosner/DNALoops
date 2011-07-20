/*
 * Loop.h
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner Grosner
 */

#ifndef LOOP_H_
#define LOOP_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Loop : public Entity {
public:
	Loop();
	Loop(string name);
	virtual ~Loop();

	friend ostream &operator<<(ostream &out, const Loop &l);

	// TODO: Change this to either stdout or to a file.
	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);
	string class_name() {return "Loop";};

	bool commit(SQLiteDB &db) {return false;};
};

#endif /* LOOP_H_ */
