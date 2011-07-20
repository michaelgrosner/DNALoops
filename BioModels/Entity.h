/*
 * Entity.h
 *
 *  Created on: Jul 17, 2011
 *      Author: Michael Grosner
 */

#ifndef ENTITY_H_
#define ENTITY_H_

#include "Includes.h"
#include "boost/foreach.hpp"
#include "boost/filesystem.hpp"
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

	// Getters
	vector<Entity*> get_child_vector() const;
	Entity* get_parent();
	string get_name() const;

	// Model-Specific getters
	// TODO: Resolve circular imports ???, allow vector<Atom*> ???
	void get_sub_entities(string of_type, vector<Entity*> &entities);
	vector<Entity*> get_CAs();

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
	virtual string class_name() {return "Entity";};

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

#endif /* ENTITY_H_ */
