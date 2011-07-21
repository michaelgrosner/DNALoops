/*
 * Loop.h
 *
 *  Created on: Jul 15, 2011
 *      Author: Michael Grosner*/
#ifndef LOOP_H_
#define LOOP_H_

#include "Includes.h"
#include "Entity.h"
#include "Structure.h"
#include "BasePair.h"
#include "StepParameter.h"
#include "Structure.h"
#include "Chain.h"
#include "Residue.h"
#include "Atom.h"

class Loop : public Entity {
public:
	Loop();
	Loop(string name);
	virtual ~Loop();

	friend ostream &operator<<(ostream &out, const Loop &l);

	// TODO: Change this to either stdout or to a file.
	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);
	string class_name() const {return "Loop";};

	bool commit(SQLiteDB &db) {return false;};

	void list_ideal_sites(vector<Structure*> ideal_structures);
	void list_ideal_sites__align(Structure *s,
			vector<StepParameterEntity*> i_v, vector<StepParameterEntity*> l_v, bool reversed=false);

};

#endif /* LOOP_H_ */
