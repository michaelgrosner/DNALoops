/*
 * Entity.h
 *
 *  Created on: Jul 17, 2011
 *      Author: grosner
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Includes.h"
#include "boost/foreach.hpp"

class Entity {
public:

	// Construction and destruction
	Entity();
	virtual ~Entity();

	// Setters
	void add_child(Entity *child);
	void set_parent(Entity *parent);
	void set_name(string name);

	// Getters
	vector<Entity*> get_child_vector();
	Entity*         get_parent();
	string			get_name() const;

	// Model-Specific getters
	// TODO: Resolve circular imports ???, allow vector<Atom*> ???
	vector<Entity*> get_atoms();

	// Statistics
	int n_children() const;
	int n_atoms()    const;

	// Output methods
	friend ostream &operator<<(ostream &out, const Entity &e);

	bool is_bottom;
	bool is_top;

private:

	// Integer denoting the ID of the parent, which will be used in the Foreign
	// Key to the parent. Since Loop objects do not have a parent, ensure this
	// is left to zero.
	int pk;

	// Integer ID denoting this eEtity for the DB
	int id;

	// A human readable name of the Entity. Defaults to empty string
	string m_name;

	// Vector to hold references to all the child objects to the parent
	vector<Entity*> m_children;

	// The parent reference
	Entity* m_parent;

	// A vector of all the bottom-level atom elements
	vector<Entity*> atom_vector;
	vector<Entity*> _sublevels();
};

#endif /* ENTITY_H_ */
