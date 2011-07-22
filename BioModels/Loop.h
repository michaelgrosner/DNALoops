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

	friend ostream &operator<<(ostream &out, Loop &l);

	// TODO: Change this to either stdout or to a file.
	void as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile);
	string class_name() const {return "Loop";};

	bool commit(SQLiteDB &db);

	/*
	 * Be warned: The structures passed into this function are "ideal" and therefore
	 * for now should be treated more as a container for StepParameterEntities with
	 * no BasePairEntities attached. */
	void find_ideal_sites(vector<Structure*> ideal_structures);
	void find_ideal_sites__driver(Structure *s, bool flip_ideal=false);

	vector<Structure*> ideal_structures();
	vector<Structure*> real_structures();
	vector<Structure*> hus();

	Structure* nearest_real_structure_to_ideal_structure(int start,
			int end, const Structure* ideal_s);
};

#endif /* LOOP_H_ */
