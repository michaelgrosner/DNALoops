/*
 * Chain.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef CHAIN_H_
#define CHAIN_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Chain : public Entity {
public:
	Chain();
	Chain(string name);
	virtual ~Chain();

	friend ostream &operator<<(ostream &out, const Chain &c);

private:

};

#endif /* CHAIN_H_ */
