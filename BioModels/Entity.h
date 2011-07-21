/*
 * Entity.h
 *
 *  Created on: Jul 17, 2011
 *      Author: Michael Grosner
 *
 *      The scheme of my objects is as follows:
 *
 *      Atom -(many)-> Residue -(many)-> Chain -(many)-> Structure -(many)-> Loop
 *      				  |									^			      ^
 *      				(two)							(many)   (many)------/
 *      				  |								/		/
 *      			BasePairEntity -(two)-> StepParameterEntity
 *
 *      Entity is the base class of all these objects (BasePairEntity and
 *      StepParameterEntity objects also inherit from BasePair and StepParameter
 *      DNASim objects)
 *
 *      Entity objects have a few built-in functions which define the
 *      relationships between parent and child entities, and the accessor/setter
 *      methods to make use of them.
 *
 *      In the future, I'd also like virtual functions implemented through this
 *      class to handle database transactions.
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Includes.h"
#include "boost/format.hpp"

using namespace boost::filesystem;

class Entity {
public:

	// Construction and destruction
	Entity();
	virtual ~Entity();

	// Setters
	/* Simply push back the vector containing the references to the children
	 * and set the child's parent to this */
	void add_child(Entity *child);

	/* Don't use this function for anything other than as a setter for the
	 * add_child method implemented above since this won't set the recursive
	 * relationship */
	void set_parent(Entity *parent);

	/* Give the Entity a pretty name */
	void set_name(string name);
	void set_name(path   path);

	// Getters
	vector<Entity*> get_child_vector() const;
	Entity* get_parent();
	string get_name() const;

	// Model-Specific getters
	template <class ChildClass> vector<ChildClass> get_all();
	template <class ChildClass> vector<ChildClass> get_all_reversed();
	//template <class ChildClass> vector<ChildClass> get_all_reversed();
	template <class ChildClass> int n_of();
	vector<Atom*> get_CAs();

	// Disregard this. This is used in the recursive algorithm for get_all().
	template <class ChildClass> void get_all__driver(vector<ChildClass> &entities);

	// Statistics
	int n_children() const;
	int n_atoms();

	// Output methods
	friend ostream &operator<<(ostream &out, const Entity &e);

	// To handle default arguments and make things prettier, never call this
	// directly, always use the pure to_pdb() method to generate PDB files!
	void write_pdb(string filelocation);
	virtual void as_pdb(int &chain_count, int &residue_count, int &atom_count,
			ofstream &pdbfile) {}

	// Due to circular dependency issues, the only way I'm able to check for class
	// type is via a virtual function returning the name of the model.
	virtual string class_name() const {return "Entity";};

	// Database methods
	/* Save Entity to DB. Return true if success */
	virtual bool commit(SQLiteDB &db) {return false;};

	// Operator Methods
	// Get i'th child
	//Entity operator[](int i);

	/* run_x3dna() will use all the child entities placed into this Entity to
	 * a) Generate a PDB file using the Atoms/Residues/etc. hopefully in the
	 *    correct order in which they were loaded via the write_pdb() function
	 * b) Make the appropriate system calls to the X3DNA suite of programs
	 *
	 * Afterwards, to load the output files into a Loop, use the X3DNAParser
	 * class. */
	void run_x3dna();

	bool is_bottom;
	bool is_top;

private:

	// Integer denoting the ID of the parent, which will be used in the Foreign
	// Key to the parent. Since Loop objects do not have a parent, ensure this
	// is left to zero.
	int pk;

	// Integer ID denoting this Entity for the DB -- NOT position!
	int id;

	// A human readable name of the Entity. Defaults to empty string
	string m_name;

	// Vector to hold references to all the child objects to the parent
	vector<Entity*> m_children;

	// The parent reference
	Entity* m_parent;

};

template <class ChildClass>
void Entity::get_all__driver(vector<ChildClass> &entities) {
	// Recursive tree algorithm to find the Atoms, all tagged with is_bottom.
	foreach(Entity* e, get_child_vector()) {
		if (dynamic_cast<ChildClass>(e) != NULL) {
			entities.push_back(dynamic_cast<ChildClass>(e));
		} else {
			e->get_all__driver<ChildClass>(entities);
		};
	}
}

template <class ChildClass>
vector<ChildClass> Entity::get_all() {
	vector<ChildClass> entities;
	get_all__driver<ChildClass>(entities);
	return entities;
}

template <class ChildClass>
vector<ChildClass> Entity::get_all_reversed() {
	vector<ChildClass> all = get_all<ChildClass>();
	return vector<ChildClass>(all.rbegin(), all.rend());
}

template <class ChildClass>
int Entity::n_of() {
	return get_all<ChildClass>().size();
}

#endif /* ENTITY_H_ */
