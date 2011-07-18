/*
 * Entity.cpp
 *
 *  Created on: Jul 17, 2011
 *      Author: grosner
 */

#include "Entity.h"

// Construction and destruction
Entity::Entity() {
	pk = 0;
	m_name = "NO NAME";
	is_bottom = false;
	is_top = false;
}

Entity::~Entity() {
	// TODO Auto-generated destructor stub
}

// Setters
void Entity::add_child(Entity child) {
	m_children.push_back(&child);
}
;

void Entity::set_parent(Entity parent) {
	m_parent = &parent;
}
;

void Entity::set_name(string name) {
	m_name = name;
}

// Getters
vector<Entity*> Entity::get_child_vector() {
	return m_children;
}

Entity* Entity::get_parent() {
	return m_parent;
}

string Entity::get_name() const {
	return m_name;
}

// Model-Specific getters
vector<Entity*> Entity::get_atoms(bool at_top=true) {
	//Entity* e = get_child_vector()[0];

	if (at_top)
		atom_vector.erase(atom_vector.begin(), atom_vector.end());

	foreach(Entity *e, get_child_vector())
				{
					if (e->is_bottom) {
						atom_vector.push_back(e);
					} else {
						return e->get_atoms(false);
					}
				}
	return atom_vector;
}

// Statistics
int Entity::n_children() const {
	return m_children.size();
}

// Output methods
// Use the subclass to handle output
ostream& operator<<(ostream &out, const Entity &e) {
	out << e;
	return out;
}
