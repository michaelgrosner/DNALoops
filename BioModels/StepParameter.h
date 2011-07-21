/*
 * StepParameter.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#ifndef STEPPARAMETER_H_
#define STEPPARAMETER_H_

#include "Includes.h"
#include "Entity.h"
#include "BasePair.h"
#include "Loop.h"

class StepParameterEntity: public Entity, public StepParameters {
public:
	/* Construction with attached BasePairEntities */
	StepParameterEntity(const VectorReal& v, Entity &parent, BasePairEntity* bp1,
			BasePairEntity* bp2, const int& p);

	/* No attached BasePairEntities given: Loading from IdealStructureBuilder
	 * where only StepParameters are given */
	StepParameterEntity(const VectorReal& v, Entity &parent, const int& p);

	/* Position in the DNA strand */
	int position();

	/* When traversing along a strand of DNA in the reverse direction, the sign
	 * of shift and tilt become negative. Return a copy of the VectorReal in
	 * the reverse direction */
	VectorReal reversed();

	// Destructor
	virtual ~StepParameterEntity();

	/* Implementations of virtual functions declared in Entity.h */
	void   as_pdb(int &chain_count, int &residue_count, int &atom_count,
			ofstream &pdbfile) {}
	string class_name() const {return "StepParameter";}
	bool   commit(SQLiteDB &db) {return false;}

	// Output methods
	friend ostream &operator<<(ostream &out, const StepParameterEntity &sp);

private:
	int strand_position;
};

#endif /* STEPPARAMETER_H_ */
