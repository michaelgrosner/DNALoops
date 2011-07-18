/*
 * Atom.h
 *
 *  Created on: Jul 16, 2011
 *      Author: grosner
 */

#ifndef ATOM_H_
#define ATOM_H_

#include "Includes.h"
#include "BioModels/Entity.h"

class Atom : public Entity {
public:
	Atom(string name, double x, double y, double z);
	virtual ~Atom();

	void set_residue_pk(int fk);

	friend ostream &operator<<(ostream &out, const Atom &a);

private:
	double x;
	double y;
	double z;

	int fk;

	string name;

};

#endif /* ATOM_H_ */
