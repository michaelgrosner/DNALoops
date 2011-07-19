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
void Entity::get_atoms(vector<Entity*> &atoms) {
	// Recursive tree algorithm to find the Atoms, all tagged with is_bottom.
	foreach(Entity* e, get_child_vector()) {
		if (e->is_bottom) {
			atoms.push_back(e);
		} else {
			e->get_atoms(atoms);
		};
	}
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

// TODO: Make use of the Boost filesystem for this
void Entity::write_pdb(string filelocation) {

	// Not sure why, but ofstream requires a c_str here...
	ofstream pdbfile(filelocation.c_str(), ofstream::out);

	int atom_count = 1;
	int chain_count = 1;
	int residue_count = 1;

	as_pdb(chain_count, residue_count, atom_count, pdbfile);

	pdbfile.close();
}

void Entity::run_x3dna() {
	string pdbfilename = "all.pdb";
	path   x3dna_temp  = path(X3DNA_TEMP_PATH);

	if (is_directory(x3dna_temp)) {
		if (DEBUG) cout << x3dna_temp << " directory exists" << endl;
	}
	else {
		create_directory(x3dna_temp);
	}

	write_pdb(x3dna_temp.string() + "/" +pdbfilename);

	// TODO: Test these.
	// TODO: Ensure misc_3dna.par is in the cwd
	// TODO: Copy misc_3dna.par to x3dna_temp
	if (exists(x3dna_temp/path("misc_3dna.par"))) {
		if (DEBUG) cout << "misc_3nda found" << endl;
	}
	else {
		char *cmd = (boost::format("cp misc_3dna.par %s") % x3dna_temp).str().c_str();
		system(cmd)
	}

	// TODO: Check that 3dna programs are on the $PATH

	if (DEBUG) cout << (boost::format("cd %s") % x3dna_temp).str().c_str() << endl;
	int ret = chdir(x3dna_temp.string().c_str());
	cout << ret << endl;
	if (DEBUG) cout << (boost::format("find_pair %s %s%s") % pdbfilename % pdbfilename % ".inp").str().c_str() << endl;
	system((boost::format("find_pair %s %s%s") % pdbfilename % pdbfilename % ".inp").str().c_str());
	if (DEBUG) cout << (boost::format("analyze %s%s") % pdbfilename % ".inp").str().c_str() << endl;
	system((boost::format("analyze %s%s") % pdbfilename % ".inp").str().c_str());
}
