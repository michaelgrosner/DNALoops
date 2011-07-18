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
void Entity::add_child(Entity *child) {
	m_children.push_back(child);
	child->set_parent(this);
}
;

void Entity::set_parent(Entity *parent) {
	m_parent = parent;
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
vector<Entity*> Entity::get_atoms() {
	// Due to data persistence, if this method is called previously, the atoms
	// will be double-copied
	if (atom_vector.size() > 0) {
		atom_vector.erase(atom_vector.begin(), atom_vector.end());
	}

	// Recursive tree algorithm to find the Atoms, all tagged with is_bottom.
	foreach(Entity* e, get_child_vector()) {
		vector<Entity*> level = e->_sublevels();
		atom_vector.insert(atom_vector.end(), level.begin(), level.end());
	}
	return atom_vector;
}

vector<Entity*> Entity::_sublevels() {
	vector<Entity*> av;
	cout << get_name() << " " << get_child_vector().size() << endl;
	foreach(Entity* e, get_child_vector()) {
		if (e->is_bottom) {
			av.push_back(e);
		}
	}
	foreach(Entity* e, get_child_vector()) {
		if (!e->is_bottom) {
			vector<Entity*> level = e->_sublevels();
			av.insert(atom_vector.end(), level.begin(), level.end());
		}
	}
	return av;
}

// Statistics
int Entity::n_children() const {
	return m_children.size();
}

int Entity::n_atoms() const {
	return 1;//get_atoms().size();
}

// Output methods
// Use the subclass to handle output
ostream& operator<<(ostream &out, const Entity &e) {
	out << e.get_name();
	return out;
}
