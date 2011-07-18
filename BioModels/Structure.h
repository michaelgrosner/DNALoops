/*
 * Structure.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef STRUCTURE_H_
#define STRUCTURE_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Structure : public Entity {
public:

	// Construction and destruction
	Structure();
	Structure(string name);
	virtual ~Structure();

	friend ostream &operator<<(ostream &out, const Structure &s);
};

#endif /* STRUCTURE_H_ */
