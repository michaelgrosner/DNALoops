/*
 * StepParameter.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef STEPPARAMETER_H_
#define STEPPARAMETER_H_

#include "Includes.h"
#include "BioModels/Entity.h"
#include "BioModels/BasePair.h"
#include "BioModels/Loop.h"

class StepParameterEntity : public Entity, public StepParameters {
public:
	StepParameterEntity(const string& sp, Loop &l, const int& p);
	virtual ~StepParameterEntity();

	void   as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {};
	string class_name() {return "StepParameter";};
private:
	int strand_position;
};

#endif /* STEPPARAMETER_H_ */
