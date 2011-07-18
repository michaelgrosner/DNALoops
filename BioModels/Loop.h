/*
 * Loop.h
 *
 *  Created on: Jul 15, 2011
 *      Author: grosner
 */

#ifndef LOOP_H_
#define LOOP_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Loop : public Entity {
public:
	Loop();
	virtual ~Loop();

	friend ostream &operator<<(ostream &out, const Loop &l);
};

#endif /* LOOP_H_ */
