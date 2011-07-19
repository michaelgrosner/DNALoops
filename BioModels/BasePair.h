/*
 * BasePair.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef BASEPAIR_H_
#define BASEPAIR_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class BasePair : public Entity {
public:
	BasePair();
	virtual ~BasePair();

	void   as_pdb(int &chain_count, int &residue_count, int &atom_count, ofstream &pdbfile) {};
};

#endif /* BASEPAIR_H_ */
