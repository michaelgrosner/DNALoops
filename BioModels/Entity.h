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

	template <class T> T add_child(T &child);

private:
	//template <class T> vector<T> children;
};

#endif /* ENTITY_H_ */
