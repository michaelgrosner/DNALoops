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

class Residue : public Entity {
public:
	Residue();
	Residue(string name, int position);
	virtual ~Residue();

private:
	string name;
	int position;

	int pk;

};

#endif /* RESIDUE_H_ */
