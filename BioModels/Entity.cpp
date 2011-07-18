/*
 * Entity.cpp
 *
 *  Created on: Jul 17, 2011
 *      Author: grosner
 */

#include "Entity.h"

Entity::Entity() {
	pk = 0;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

void Entity::add_child(Entity child) {
	children.push_back(&child);
};
