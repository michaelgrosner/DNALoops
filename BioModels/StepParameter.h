/*
 * StepParameter.h
 *
 *  Created on: Jul 16, 2011
 *      Author: Michael Grosner
 */

#ifndef STEPPARAMETER_H_
#define STEPPARAMETER_H_

#include "Includes.h"
#include "BioModels/Entity.h"
#include "BioModels/BasePair.h"
#include "BioModels/Loop.h"

class StepParameterEntity: public Entity, public StepParameters {
public:
	StepParameterEntity(const string& sp, Entity &parent, BasePairEntity* bp1,
			BasePairEntity* bp2, const int& p);
	virtual ~StepParameterEntity();

	void as_pdb(int &chain_count, int &residue_count, int &atom_count,
			ofstream &pdbfile) {}

	string class_name() {return "StepParameter";}

	bool commit(SQLiteDB &db) {return false;}

	// Output methods
	friend ostream &operator<<(ostream &out, const StepParameterEntity &sp);

private:
	int strand_position;
};

#endif /* STEPPARAMETER_H_ */
