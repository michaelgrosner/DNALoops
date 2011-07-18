/*
 * Entity.h
 *
 *  Created on: Jul 17, 2011
 *      Author: grosner
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Includes.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	void add_child(Entity child);

	//vector<Entity*> get_child_vector()

private:

	// Integer denoting the ID of the parent, which will be used in the Foreign
	// Key to the parent. Since Loop objects do not have a parent, ensure this
	// is left to zero.
	int pk;

	// Integer ID denoting this entity for the DB
	int id;

	// Vector to hold references to all the child objects to the parent
	vector<Entity*> children;

	// The parent reference
	Entity* parent;
};

#endif /* ENTITY_H_ */
